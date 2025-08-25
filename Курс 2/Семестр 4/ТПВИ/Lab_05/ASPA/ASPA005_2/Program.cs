using ASPA005_2;
using Validation;
using DAL004;
using Microsoft.AspNetCore.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        var app = builder.Build();

        RouteGroupBuilder api = app.MapGroup("/Celebrities");

        Repository.JSONFileName = "Celebrities.json";

        using (IRepository repository = Repository.Create("Celebrities"))
        {
            api.UseExceptionHandler("/Error");


            api.MapGet("", () => repository.getAllCelebrities());


            api.MapGet("/{id:int}", (int id) =>
            {
                Celebrity? celebrity = repository.getCelebrityById(id);
                
                return celebrity;

            })
            .AddEndpointFilter<IdFilter>();


            SurnameFilter.repository = PhotoExistFilter.repository
                = UpdateFilter.repository = IdFilter.repository = repository;


            api.MapPost("", (Celebrity celebrity) =>
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
            })
            .AddEndpointFilter<PhotoExistFilter>()
            .AddEndpointFilter<SurnameFilter>();


            api.MapDelete("/{id:int}", (int id) =>
            {
                if (!repository.delCelebrityById(id))
                {
                    throw new DelByIdException($"DELETE /Celebrities error, Id = {id}");
                }

                return Results.Ok<string>($"Celebrity with Id = {id} deleted");
            })
            .AddEndpointFilter<IdFilter>();


            api.MapPut("/{id:int}", (int id, Celebrity celebrity) =>
            {
                int? newId = null;

                if ((newId = repository.updCelebrityById(id, celebrity)) == null)
                {
                    throw new UpdException($"Id = {id}");
                }

                return new Celebrity((int)newId, celebrity.Firstname, celebrity.Surname, celebrity.PhotoPath);
            })
            .AddEndpointFilter<IdFilter>();


            app.MapFallback((HttpContext ctx) => Results.NotFound(new { error = $"path {ctx.Request.Path} not supported" }));


            api.Map("/Error", (HttpContext ctx) =>
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

