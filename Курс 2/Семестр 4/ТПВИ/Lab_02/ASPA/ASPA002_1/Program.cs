var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.UseWelcomePage("/aspnetcore");

app.UseDefaultFiles();

app.UseStaticFiles();

app.MapGet("/Hello", () => "Hello World!");

app.Run();
