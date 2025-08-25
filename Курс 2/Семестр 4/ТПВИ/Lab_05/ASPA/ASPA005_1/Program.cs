using ASPA005_1;
using DAL004;
using Microsoft.AspNetCore.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        var app = builder.Build();

        Repository.JSONFileName = "Celebrities.json";

        using (IRepository repository = Repository.Create("Celebrities"))
        {
            app.UseExceptionHandler("/Celebrities/Error");


            app.MapGet("/Celebrities", () => repository.getAllCelebrities());


            app.MapGet("/Celebrities/{id:int}", (int id) =>
            {
                Celebrity? celebrity = repository.getCelebrityById(id);

                if (celebrity == null)
                {
                    throw new FoundByIdException($"/Celebrities, Celebrity Id = {id}");
                }

                return celebrity;
            });


            app.MapPost("/Celebrities", (Celebrity celebrity) =>
            {
                int? id = repository.addCelebrity(celebrity);

                if (id == null)
                {
                    throw new AddCelebrityException("POST /Celebrities error, id == null");
                }

                if (repository.SaveChanges() <= 0)
                {
                    throw new SaveException("/Celebrities error, SaveChanges() <= 0");
                }

                return new Celebrity((int)id, celebrity.Firstname, celebrity.Surname, celebrity.PhotoPath);

            }).AddEndpointFilter(async (context, next) =>
            {
                Celebrity? celebrity = context.GetArgument<Celebrity>(0);

                if (celebrity == null)
                {
                    throw new AbsurdeException("POST /Celebrities error, celebrity == null");
                }

                return await next(context);

            }).AddEndpointFilter(async (context, next) =>
            {
                Celebrity? celebrity = context.GetArgument<Celebrity>(0);

                if (celebrity.Surname == null || celebrity.Surname.Length <= 1)
                {
                    throw new ValueException("POST /Celebrities error, Surname is wrong");
                }

                return await next(context);

            }).AddEndpointFilter(async (context, next) =>
            {
                Celebrity? celebrity = context.GetArgument<Celebrity>(0);

                if (repository.getCelebritiesBySurname(celebrity.Surname).Length > 0)
                {
                    throw new ValueException("POST /Celebrities error, Surname is doubled");
                }

                return await next(context);

            }).AddEndpointFilter(async (context, next) =>
            {
                Celebrity? celebrity = context.GetArgument<Celebrity>(0);

                object? result = await next(context);

                string fn = Path.GetFileName(celebrity.PhotoPath);

                if (!File.Exists(Path.Combine(repository.BasePath, $"{fn}")))
                {
                    if (context != null)
                    {
                        context.HttpContext.Response.Headers.Append("X-Celebrity", $"NotFound = {fn}");
                    }
                }

                return result; 
            });


            app.MapDelete("/Celebrities/{id:int}", (int id) =>
            {
                if (!repository.delCelebrityById(id))
                {
                    throw new DelByIdException($"DELETE /Celebrities error, Id = {id}");
                }

                return Results.Ok<string>($"Celebrity with Id = {id} deleted");
            });


            app.MapPut("/Celebrities/{id:int}", (int id, Celebrity celebrity) =>
            {
                int? newId = null;

                if ((newId = repository.updCelebrityById(id, celebrity)) == null)
                {
                    throw new UpdException($"Id = {id}");
                }

                if (repository.SaveChanges() <= 0)
                {
                    throw new SaveException("/Celebrities error, SaveChanges() <= 0");
                }

                return new Celebrity((int)newId, celebrity.Firstname, celebrity.Surname, celebrity.PhotoPath);
            });


            app.MapFallback((HttpContext ctx) => Results.NotFound(new { error = $"path {ctx.Request.Path} not supported" }));


            app.Map("/Celebrities/Error", (HttpContext ctx) =>
            {
                Exception? ex = ctx.Features.Get<IExceptionHandlerFeature>()?.Error;
                IResult rc = Results.Problem(detail: $"{ex.Message}", instance: app.Environment.EnvironmentName, title: "ASPA004", statusCode: 500);

                if (ex != null)
                {
                    if (ex is AbsurdeException)
                    {
                        rc = Results.Conflict(ex.Message);
                    }

                    if (ex is ValueException)
                    {
                        rc = Results.Conflict(ex.Message);
                    }

                    if (ex is UpdException)
                    {
                        rc = Results.NotFound(ex.Message);
                    }

                    if (ex is DelByIdException)
                    {
                        rc = Results.NotFound(ex.Message);
                    }

                    if (ex is FoundByIdException)
                    {
                        rc = Results.NotFound(ex.Message);
                    }

                    if (ex is BadHttpRequestException)
                    {
                        rc = Results.BadRequest(ex.Message);
                    }

                    if (ex is SaveException)
                    {
                        rc = Results.Problem(title: "ASPA004/SaveChanges", detail: ex.Message, instance: app.Environment.EnvironmentName, statusCode: 500);
                    }

                    if (ex is AddCelebrityException)
                    {
                        rc = Results.Problem(title: "ASPA004/addCelebrity", detail: ex.Message, instance: app.Environment.EnvironmentName, statusCode: 500);
                    }
                }

                return rc;
            });

            app.Run();
        }
    }
}

