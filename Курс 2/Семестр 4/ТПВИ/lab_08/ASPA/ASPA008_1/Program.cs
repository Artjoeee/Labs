using ANC_25_WEBAPI_DLL;
using ANC_25_WEBAPI_DLL.Service;
using ASPA007.Data;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

//MVC
builder.Services.AddControllersWithViews();

builder.AddCelebritiesConfiguration();  // ����������� ������������ IOptions<CelebritiesConfig>
builder.AddCelebritiesServices();       // ����������� ��������: IRepository, CountryCodes, CelebritiesTitles

builder.Services.AddControllersWithViews();

var celebritiesConfig = builder.Configuration.GetSection("Celebrities").Get<CelebritiesConfig>();

builder.Services.AddDbContext<CelebrityContext>(options =>
    options.UseSqlServer(builder.Configuration.GetSection("Celebrities").Get<CelebritiesConfig>().ConnectionString));

// ������������ CountryCodes
builder.Services.AddSingleton(new CountryCodes(celebritiesConfig.CountryCodes));

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseMiddleware<MiddlewareErrorHandler>();    // ����������� ����������� ������
    app.UseExceptionHandler("/Home/Error");
    app.UseHsts();
}


app.UseHttpsRedirection();
app.UseStaticFiles();
app.UseRouting();

app.MapCelebrities();       // Map ��� Celebrities
app.MapLifeEvents();        // Map ��� Lifeevents
app.MapPhotoCelebrities();  // Map ��� ����������

app.UseAuthorization();

// �������������
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
