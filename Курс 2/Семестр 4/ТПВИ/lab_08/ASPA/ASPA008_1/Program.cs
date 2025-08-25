using ANC_25_WEBAPI_DLL;
using ANC_25_WEBAPI_DLL.Service;
using ASPA007.Data;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

//MVC
builder.Services.AddControllersWithViews();

builder.AddCelebritiesConfiguration();  // подключение конфигурации IOptions<CelebritiesConfig>
builder.AddCelebritiesServices();       // подключение сервисов: IRepository, CountryCodes, CelebritiesTitles

builder.Services.AddControllersWithViews();

var celebritiesConfig = builder.Configuration.GetSection("Celebrities").Get<CelebritiesConfig>();

builder.Services.AddDbContext<CelebrityContext>(options =>
    options.UseSqlServer(builder.Configuration.GetSection("Celebrities").Get<CelebritiesConfig>().ConnectionString));

// Регистрируем CountryCodes
builder.Services.AddSingleton(new CountryCodes(celebritiesConfig.CountryCodes));

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseMiddleware<MiddlewareErrorHandler>();    // подключение обработчика ошибок
    app.UseExceptionHandler("/Home/Error");
    app.UseHsts();
}


app.UseHttpsRedirection();
app.UseStaticFiles();
app.UseRouting();

app.MapCelebrities();       // Map для Celebrities
app.MapLifeEvents();        // Map для Lifeevents
app.MapPhotoCelebrities();  // Map для фотографий

app.UseAuthorization();

// маршрутизация
app.MapControllerRoute(
    name: "NewCelebrity",
    pattern: "/NewCelebrity",
    defaults: new { controller = "NewCelebrity", action = "New" });
app.MapControllerRoute(
    name: "EditCelebrity",
    pattern: "/Edit",
    defaults: new { controller = "EditCelebrity", action = "Edit" });
app.MapControllerRoute(
    name: "DelCelebrity",
    pattern: "/Delete",
    defaults: new { controller = "DelCelebrity", action = "Delete" });
app.MapControllerRoute(
    name: "celebrity",
    pattern: "/{id:int:min(1)}",
    defaults: new {Controller = "Celebrity", Action = "Human"});
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Celebrities}/{action=Index}/{id?}");

app.Run();
