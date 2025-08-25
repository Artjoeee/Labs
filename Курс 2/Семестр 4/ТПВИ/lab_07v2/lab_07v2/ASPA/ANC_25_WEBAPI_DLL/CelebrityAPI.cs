using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Options;
using Microsoft.Extensions.Configuration;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Routing;
using Microsoft.AspNetCore.Http;
using DAL_Celebrity;

namespace ANC_25_WEBAPI_DLL
{
    public static class CelebrityAPI
    {
        public static IServiceCollection AddCelebritiesConfiguration(this WebApplicationBuilder builder,
                                                                     string celebrityJson = "Celebrities.config.json")
        {
            builder.Configuration.AddJsonFile(celebrityJson);
            return builder.Services.Configure<CelebritiesConfig>(builder.Configuration.GetSection("Celebrities"));
        }

        public static IServiceCollection AddCelebritiesServices(this WebApplicationBuilder builder)
        {
            builder.Services.AddScoped<IRepository, Repository>((IServiceProvider p) =>
            {
                CelebritiesConfig config = p.GetRequiredService<IOptions<CelebritiesConfig>>().Value;
                return new Repository(config.ConnectionString);
            });
            return builder.Services;
        }

        public static RouteHandlerBuilder MapCelebrities(this IEndpointRouteBuilder routeBuilder,
                                                         string prefix = "/api/Celebrities")
        {
            var celebrities = routeBuilder.MapGroup(prefix);

            // Все знаменитости
            celebrities.MapGet("/", (IRepository repo) =>
            {
                var result = repo.GetAllCelebrities();
                return Results.Ok(result);
            });

            // Знаменитость по ID
            celebrities.MapGet("/{id:int:min(1)}", (IRepository repo, int id) =>
            {
                Celebrity? celebrity = repo.GetCelebrityById(id);
                if (celebrity == null)
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"Celebrity with Id = {id} not found");
                return Results.Ok(celebrity);
            });

            // Знаменитость по ID события
            celebrities.MapGet("/lifeevents/{id:int:min(1)}", (IRepository repo, int id) =>
            {
                Celebrity? celebrity = repo.GetCelebrityByLifeeventId(id);
                if (celebrity == null)
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"Celebrity for LifeEvent Id = {id} not found");
                return Results.Ok(celebrity);
            });

            // Удалить знаменитость по ID
            celebrities.MapDelete("/{id:int:min(1)}", (IRepository repo, int id) =>
            {
                if (!repo.DelCelebrity(id))
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"Celebrity with Id = {id} not found or could not be deleted");

                return Results.Ok(new { Message = $"Celebrity with Id = {id} deleted successfully" });
            });

            // Добавить новую знаменитость
            celebrities.MapPost("/", (IRepository repo, Celebrity celebrity) =>
            {
                if (celebrity == null)
                    throw new ANC25Exception(Status: 400, code: "400", detail: "Celebrity data is required");

                if (!repo.AddCelebrity(celebrity))
                    throw new ANC25Exception(Status: 500, code: "500", detail: "Failed to add celebrity");

                return Results.Created($"/api/Celebrities/{celebrity.Id}", celebrity);
            });

            // Изменить знаменитость по ID
            celebrities.MapPut("/{id:int:min(1)}", (IRepository repo, int id, Celebrity celebrity) =>
            {
                if (celebrity == null || id != celebrity.Id)
                    throw new ANC25Exception(Status: 400, code: "400", detail: "Invalid celebrity data");

                if (!repo.UpdCelebrity(id, celebrity))
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"Celebrity with Id = {id} not found or could not be updated");

                return Results.Ok(celebrity);
            });

            // Получить файл фотографии по имени файла (fname)
            return celebrities.MapGet("/photo/{fname}", async (IOptions<CelebritiesConfig> iconfig, HttpContext context, string fname) =>
            {
                CelebritiesConfig config = iconfig.Value;
                string filepath = Path.Combine(config.PhotosFolder, fname);

                if (!File.Exists(filepath))
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"Photo {fname} not found");

                var fileStream = File.OpenRead(filepath);
                return Results.File(fileStream, "image/jpeg");
            });
        }

        public static RouteHandlerBuilder MapPhotoCelebrities(this IEndpointRouteBuilder routeBuilder, string? prefix = "/Photos")
        {
            if (string.IsNullOrEmpty(prefix))
                prefix = routeBuilder.ServiceProvider.GetRequiredService<IOptions<CelebritiesConfig>>().Value.PhotosRequestPath;

            return routeBuilder.MapGet($"{prefix}/{{fname}}", async (IOptions<CelebritiesConfig> iconfig, HttpContext context, string fname) =>
            {
                CelebritiesConfig config = iconfig.Value;
                string filepath = Path.Combine(config.PhotosFolder, fname);

                if (!File.Exists(filepath))
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"Photo {fname} not found");

                await using FileStream file = File.OpenRead(filepath);
                using BinaryReader sr = new BinaryReader(file);
                await using BinaryWriter sw = new BinaryWriter(context.Response.BodyWriter.AsStream());

                int n;
                byte[] buffer = new byte[2048];
                context.Response.ContentType = "image/jpeg";
                context.Response.StatusCode = StatusCodes.Status200OK;

                while ((n = await sr.BaseStream.ReadAsync(buffer, 0, 2048)) > 0)
                {
                    await sw.BaseStream.WriteAsync(buffer, 0, n);
                }
            });
        }

        public static RouteHandlerBuilder Maplifeevents(this IEndpointRouteBuilder routebuilder,
                                                        string prefix = "/api/lifeevents")
        {
            var lifeevents = routebuilder.MapGroup(prefix);

            // Все события
            lifeevents.MapGet("/", (IRepository repo) =>
            {
                var result = repo.GetAllLifeevents();
                return Results.Ok(result);
            });

            // Событие по ID
            lifeevents.MapGet("/{id:int:min(1)}", (IRepository repo, int id) =>
            {
                LifeEvent? lifeEvent = repo.GetLifeeventbyId(id);
                if (lifeEvent == null)
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"LifeEvent with Id = {id} not found");
                return Results.Ok(lifeEvent);
            });

            // Все события по ID знаменитости
            lifeevents.MapGet("/Celebrities/{id:int:min(1)}", (IRepository repo, int id) =>
            {
                var events = repo.GetLifeeventsByCelebrityId(id);
                if (events == null || !events.Any())
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"No life events found for celebrity Id = {id}");

                return Results.Ok(events);
            });

            // Удалить событие по ID
            lifeevents.MapDelete("/{id:int:min(1)}", (IRepository repo, int id) =>
            {
                if (!repo.DelLifeevent(id))
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"LifeEvent with Id = {id} not found or could not be deleted");

                return Results.Ok(new { Message = $"LifeEvent with Id = {id} deleted successfully" });
            });

            // Добавить новое событие
            lifeevents.MapPost("/", (IRepository repo, LifeEvent lifeevent) =>
            {
                if (lifeevent == null)
                    throw new ANC25Exception(Status: 400, code: "400", detail: "LifeEvent data is required");

                Celebrity? c = repo.GetCelebrityById(lifeevent.CelebrityId);
                if (c == null)
                    throw new ANC25Exception(Status: 404, code: "404005", detail: $"Celebrity Id = {lifeevent.CelebrityId} not found");

                if (!repo.AddLifeevent(lifeevent))
                    throw new ANC25Exception(Status: 500, code: "500005", detail: "Failed to add life event");

                return Results.Created($"/api/lifeevents/{lifeevent.Id}", lifeevent);
            });

            // Изменить событие по ID
            return lifeevents.MapPut("/{id:int:min(1)}", (IRepository repo, int id, LifeEvent lifevent) =>
            {
                if (lifevent == null || id != lifevent.Id)
                    throw new ANC25Exception(Status: 400, code: "400", detail: "Invalid life event data");

                if (!repo.UpdLifeevent(id, lifevent))
                    throw new ANC25Exception(Status: 404, code: "404", detail: $"LifeEvent with Id = {id} not found or could not be updated");

                return Results.Ok(lifevent);
            });
        }
    }
}