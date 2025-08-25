using DAL003;
using Microsoft.Extensions.FileProviders;
internal class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);
        var app = builder.Build();

        Repository.JSONFileName = "Celebrities.json";
        using (IRepository repository = Repository.Create("Celebrities"))
        {
            app.UseStaticFiles(new StaticFileOptions
            {
                FileProvider = new PhysicalFileProvider(
                Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Celebrities")),
                RequestPath = "/Photo"
            });

            app.UseDirectoryBrowser(new DirectoryBrowserOptions()
            {
                FileProvider = new PhysicalFileProvider(
                Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Celebrities")),
                RequestPath = "/Celebrities/download"
            });

            app.UseStaticFiles(new StaticFileOptions()
            {
                FileProvider = new PhysicalFileProvider(
                Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Celebrities")),
                RequestPath = "/Celebrities/download",
                OnPrepareResponse = context =>
                {
                    var fileName = Path.GetFileName(context.File.PhysicalPath);
                    context.Context.Response.Headers.CacheControl = "no-store, no-cache, must-revalidate, max-age=0";
                    context.Context.Response.Headers.Pragma = "no-cache";
                    context.Context.Response.Headers.Expires = "0";
                    context.Context.Response.Headers.ContentDisposition = $"attachment; filename=\"{fileName}\"";
                }
            });

            app.MapGet("/Celebrities", () => repository.getAllCelebrities());
            app.MapGet("/Celebrities/{id:int}", (int id) => repository.getCelebrityById(id));
            app.MapGet("/Celebrities/BySurname/{surname}", (string surname) => repository.getCelebritiesBySurname(surname));
            app.MapGet("/Celebrities/PhotoPathById/{id:int}", (int id) => repository.getPhotoPathById(id));
            app.MapGet("/", () => "Hello World!");
            app.Run();
        }
    }
}