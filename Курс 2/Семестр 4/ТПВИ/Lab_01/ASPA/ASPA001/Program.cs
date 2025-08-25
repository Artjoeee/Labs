internal class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);   // ������� WebApplicationBuilder (������� builder)

        builder.Services.AddHttpLogging(o => {  // ����� � ������
                                                o.LoggingFields = Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.RequestMethod |        // Request �����
                                                                  Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.RequestPath |          // Request uri
                                                                  Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.ResponseStatusCode |   // Response status
                                                                  Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.ResponseBody;          // Response ����
                                             }
        );

        builder.Logging.AddFilter("Microsoft.AspNetCore.HttpLogging", LogLevel.Information); // ������ ���������

        var app = builder.Build();                          // ������� ��������� WebApplication

        app.UseHttpLogging();                               // Midleware: ����� � ������

        app.MapGet("/", () => "��� ������ ASPA");           // ������ �������� ����� 1
        app.MapGet("/person", () => "Person");              // ������ �������� ����� 2

        app.Run();                                          // ��������� web-����������
    }
}