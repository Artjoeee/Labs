using ANC_25_WEBAPI_DLL;
using ANC_25_WEBAPI_DLL.Service;
using ASPA007.Data;
using DAL_Celebrity_MSSQL;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddDbContext<CelebrityContext>(options =>
    options.UseSqlServer(builder.Configuration.GetSection("Celebrities").Get<CelebritiesConfig>().ConnectionString));

builder.Services.AddScoped<IRepository, CelebrityRepository>();

builder.Services.AddRazorPages(options =>
{
    options.Conventions.AddPageRoute("/Celebrities", "/");
    options.Conventions.AddPageRoute("/NewCelebrity", "/0");
    options.Conventions.AddPageRoute("/Celebrity", "Celebrities/{id:int:min(1)}");
    options.Conventions.AddPageRoute("/Celebrity", "{id:int:min(1)}");
    options.Conventions.AddPageRoute("/LifeEvents", "LifeEvent/{id:int:min(1)}");
});

var app = builder.Build();

if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Error");
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapRazorPages();

app.Run();
