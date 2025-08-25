using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Diagnostics;
using Microsoft.Extensions.Options;

class Program
{
    static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        builder.Configuration.AddJsonFile("Celebrities.config.json", optional: true); //+json-provider

        builder.Services.Configure<CelebritiesConfig>(builder.Configuration.GetSection("CelebritiesSetting")); //DI. C�������� ��������� �� ����� � ��������(�������) � ���������� DI

        builder.Services.AddScoped<IRepository, Repository>(p => { 
            CelebritiesConfig config = p.GetRequiredService<IOptions<CelebritiesConfig>>().Value;
            return new Repository(config.MSSQL.ConnectionString); });

        builder.Services.AddRazorPages();

        var app = builder.Build();
        //app.UseStaticFiles(); //���������� ���������� ��� ����������� �����
        //app.UseDefaultFiles(); // ����� �� ��������� ������������ index.html
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

        
        // --- ������������ (Celebrities) ---
        var celebrities = app.MapGroup("/api/Celebrities");

        celebrities.MapGet("/", (IRepository repo) =>                                       repo.GetAllCelebrities()); //���
        celebrities.MapGet("/{id:int:min(1)}", (IRepository repo, int id) =>                repo.GetCelebrityById(id)); // �������� ������������ �� ID
        celebrities.MapGet("/Lifeevents/{id:int:min(1)}", (IRepository repo, int id) =>     repo.GetCelebrityByLifeEventId(id));// �������� ������������ �� ID �������

        // ������� ������������ �� ID
        celebrities.MapDelete("/{id:int:min(1)}", (IRepository repo, int id) =>{
            if (repo.DelCelebrity(id)) return Results.Ok($"OK: DelCelebrity: {id}");
            else return Results.BadRequest($"ERROR: DelCelebrity {id}");
        });

        // �������� ����� ������������
        celebrities.MapPost("/", (IRepository repo, Celebrity celebrity) =>{
            if (repo.AddCelebrity(new Celebrity { FullName = celebrity.FullName, Nationality = celebrity.Nationality, ReqPhotoPath = celebrity.ReqPhotoPath })) return Results.Ok($"OK: AddCelebrity: {celebrity}");
            else return Results.BadRequest($"ERROR: AddCelebrity: {celebrity}");
        });

        // �������� ������������ �� ID
        celebrities.MapPut("/{id:int:min(1)}", (IRepository repo, int id, Celebrity celebrity) => {
            if (repo.UpdCelebrity(id, new Celebrity { FullName = celebrity.FullName, Nationality = celebrity.Nationality, ReqPhotoPath = celebrity.ReqPhotoPath })) return Results.Ok($"OK: UpdCelebrity: {celebrity}");
            else return Results.BadRequest($"ERROR: UpdCelebrity: {celebrity}");
        });

        // �������� ���� ���������� �� ����� ����� (fname)
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

        // --- ������� (LifeEvents) ---
        var lifeEvents = app.MapGroup("/api/LifeEvents");

        lifeEvents.MapGet("/", (IRepository repo) =>                                        repo.GetAllLifeEvents()); //���
        lifeEvents.MapGet("/{id:int:min(1)}", (IRepository repo, int id) =>                 repo.GetLifeEventById(id));// �������� ������� �� ID
        lifeEvents.MapGet("/Celebrities/{id:int:min(1)}", (IRepository repo, int id) =>     repo.GetLifeEventsByCelebrityId(id));// �������� ��� ������� �� ID ������������

        // ������� ������� �� ID
        lifeEvents.MapDelete("/{id:int:min(1)}", (IRepository repo, int id) => {
            return repo.DelLifeEvent(id);
        });

        // �������� ����� �������
        lifeEvents.MapPost("/", (IRepository repo, LifeEvent lifeEvent) => { 
            return repo.AddLifeEvent(lifeEvent);
        });

        // �������� ������� �� ID
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

    // ��������������� ����� ��� ����������� Content-Type
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
