using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Diagnostics;
using Microsoft.Extensions.Options;

class Program
{
    static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        builder.Configuration.AddJsonFile("Celebrities.config.json", optional: true); //+json-provider

        builder.Services.Configure<CelebritiesConfig>(builder.Configuration.GetSection("CelebritiesSetting")); //DI. Cвязывает параметры из файла с сервисом(классом) в контейнере DI

        builder.Services.AddScoped<IRepository, Repository>(p => { 
            CelebritiesConfig config = p.GetRequiredService<IOptions<CelebritiesConfig>>().Value;
            return new Repository(config.MSSQL.ConnectionString); });

        builder.Services.AddRazorPages();

        var app = builder.Build();
        //app.UseStaticFiles(); //используем директорию для статических фалов
        //app.UseDefaultFiles(); // чтобы по умолчанию использовать index.html
        //app.MapGet("/", () => Results.File("index.html", "text/html"));

        app.UseRouting();
        app.MapRazorPages();

        app.MapGet("/", context => {
            context.Response.Redirect("/photo");
            return Task.CompletedTask;
        });

        app.UseExceptionHandler("/Error");
        app.MapGet("/Configuration", () => app.Configuration.AsEnumerable());
        app.MapGet("/Service/Configuration", (IConfiguration conf) => conf.AsEnumerable()); //DI 
        app.MapGet("/Service/Repository", (IRepository r) => r.GetAllCelebrities()); //DI

        app.MapGet("/Service/Configuration/{parm}", (IConfiguration conf, string parm) => {
            //string? valueParm = builder.Configuration[parm]; //not DI
            string? valueParm = conf[parm]; //DI
            return Results.Ok(new { Parm = parm, Value = valueParm });
        });

        app.MapGet("/Service/Configuration/Binding", (IOptions<CelebritiesConfig> conf) => { CelebritiesConfig cconf = conf.Value; return Results.Ok(cconf); }); //DI 

        
        // --- ЗНАМЕНИТОСТИ (Celebrities) ---
        var celebrities = app.MapGroup("/api/Celebrities");

        celebrities.MapGet("/", (IRepository repo) =>                                       repo.GetAllCelebrities()); //все
        celebrities.MapGet("/{id:int:min(1)}", (IRepository repo, int id) =>                repo.GetCelebrityById(id)); // Получить знаменитость по ID
        celebrities.MapGet("/Lifeevents/{id:int:min(1)}", (IRepository repo, int id) =>     repo.GetCelebrityByLifeEventId(id));// Получить знаменитость по ID события

        // Удалить знаменитость по ID
        celebrities.MapDelete("/{id:int:min(1)}", (IRepository repo, int id) =>{
            if (repo.DelCelebrity(id)) return Results.Ok($"OK: DelCelebrity: {id}");
            else return Results.BadRequest($"ERROR: DelCelebrity {id}");
        });

        // Добавить новую знаменитость
        celebrities.MapPost("/", (IRepository repo, Celebrity celebrity) =>{
            if (repo.AddCelebrity(new Celebrity { FullName = celebrity.FullName, Nationality = celebrity.Nationality, ReqPhotoPath = celebrity.ReqPhotoPath })) return Results.Ok($"OK: AddCelebrity: {celebrity}");
            else return Results.BadRequest($"ERROR: AddCelebrity: {celebrity}");
        });

        // Изменить знаменитость по ID
        celebrities.MapPut("/{id:int:min(1)}", (IRepository repo, int id, Celebrity celebrity) => {
            if (repo.UpdCelebrity(id, new Celebrity { FullName = celebrity.FullName, Nationality = celebrity.Nationality, ReqPhotoPath = celebrity.ReqPhotoPath })) return Results.Ok($"OK: UpdCelebrity: {celebrity}");
            else return Results.BadRequest($"ERROR: UpdCelebrity: {celebrity}");
        });

        // Получить файл фотографии по имени файла (fname)
        celebrities.MapGet("/photo/{fname}", async (IOptions<CelebritiesConfig> iconfig, HttpContext context, string fname) =>
        {
            try
            {
                var config = iconfig.Value;
                if (string.IsNullOrEmpty(config.JSON.Path)) { return Results.BadRequest("Photos directory not configured"); }
                var fullPath = Path.Combine(config.JSON.Path, fname);
                if (!File.Exists(fullPath)) { return Results.NotFound($"File {fname} not found"); }
                var contentType = GetContentType(fname);
                return Results.File(fullPath, contentType);
            }
            catch (Exception ex) { return Results.Problem($"Error retrieving photo: {ex.Message}"); }
        });

        // --- СОБЫТИЯ (LifeEvents) ---
        var lifeEvents = app.MapGroup("/api/LifeEvents");

        lifeEvents.MapGet("/", (IRepository repo) =>                                        repo.GetAllLifeEvents()); //все
        lifeEvents.MapGet("/{id:int:min(1)}", (IRepository repo, int id) =>                 repo.GetLifeEventById(id));// Получить событие по ID
        lifeEvents.MapGet("/Celebrities/{id:int:min(1)}", (IRepository repo, int id) =>     repo.GetLifeEventsByCelebrityId(id));// Получить все события по ID знаменитости

        // Удалить событие по ID
        lifeEvents.MapDelete("/{id:int:min(1)}", (IRepository repo, int id) => {
            return repo.DelLifeEvent(id);
        });

        // Добавить новое событие
        lifeEvents.MapPost("/", (IRepository repo, LifeEvent lifeEvent) => { 
            return repo.AddLifeEvent(lifeEvent);
        });

        // Изменить событие по ID
        lifeEvents.MapPut("/{id:int:min(1)}", (IRepository repo, int id, LifeEvent lifeEvent) => {
            return repo.UpdLifeEvent(id, lifeEvent);
        });

        app.MapFallback((HttpContext ctx) => {return Results.NotFound(new { message = $"path {ctx.Request.Path.Value} not supported" }); });
        
        app.Map("/Error", (HttpContext ctx) =>
        {
            Exception? ex = ctx.Features.Get<IExceptionHandlerFeature>()?.Error;
            return Results.Ok(new { message = ex?.Message });
        });

        app.Run();
    }

    // Вспомогательный метод для определения Content-Type
    private static string GetContentType(string fileName)
    {
        var extension = Path.GetExtension(fileName).ToLowerInvariant();

        return extension switch
        {
            ".jpg" or ".jpeg" => "image/jpeg",
            ".png" => "image/png",
            ".gif" => "image/gif",
            ".webp" => "image/webp",
            _ => "application/octet-stream"
        };
    }
}
