internal class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);   // Создаем WebApplicationBuilder (паттерн builder)

        builder.Services.AddHttpLogging(o => {  // Вывод в журнал
                                                o.LoggingFields = Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.RequestMethod |        // Request метод
                                                                  Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.RequestPath |          // Request uri
                                                                  Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.ResponseStatusCode |   // Response status
                                                                  Microsoft.AspNetCore.HttpLogging.HttpLoggingFields.ResponseBody;          // Response тело
                                             }
        );

        builder.Logging.AddFilter("Microsoft.AspNetCore.HttpLogging", LogLevel.Information); // Фильтр сообщений

        var app = builder.Build();                          // Создаем экземпляр WebApplication

        app.UseHttpLogging();                               // Midleware: вывод в журнал

        app.MapGet("/", () => "Мое первое ASPA");           // Задаем конечную точку 1
        app.MapGet("/person", () => "Person");              // Задаем конечную точку 2

        app.Run();                                          // Запускаем web-приложение
    }
}