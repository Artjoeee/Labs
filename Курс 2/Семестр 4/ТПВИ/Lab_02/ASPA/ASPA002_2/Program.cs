using Microsoft.Extensions.FileProviders;

internal class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);
        var app = builder.Build();

        app.UseWelcomePage("/aspnetcore");

        DefaultFilesOptions options = new DefaultFilesOptions();

        options.DefaultFileNames.Clear(); // ������� ����� ������ �� ���������
        options.DefaultFileNames.Add("Neumann.html"); // ��������� ����� ��� �����

        app.UseDefaultFiles(options); // ��������� ����������

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