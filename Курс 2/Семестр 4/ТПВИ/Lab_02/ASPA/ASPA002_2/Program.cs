using Microsoft.Extensions.FileProviders;

internal class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);
        var app = builder.Build();

        app.UseWelcomePage("/aspnetcore");

        DefaultFilesOptions options = new DefaultFilesOptions();

        options.DefaultFileNames.Clear(); // удаляем имена файлов по умолчанию
        options.DefaultFileNames.Add("Neumann.html"); // добавляем новое имя файла

        app.UseDefaultFiles(options); // установка параметров

        app.UseStaticFiles();

        app.UseStaticFiles(new StaticFileOptions
        {
            FileProvider = new PhysicalFileProvider(
            Path.Combine(builder.Environment.ContentRootPath, "Picture")),
            RequestPath = "/Picture"
        });

        app.UseStaticFiles("/static");

        app.MapGet("/Hello", () => "Hello World!");

        app.Run();
    }
}