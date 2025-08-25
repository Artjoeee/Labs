using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Options;
using System.Collections.Generic;
using System.Threading.Tasks;

public class PhotoModel : PageModel
{
    private readonly IOptions<CelebritiesConfig> _config;

    public List<Celebrity> Celebrities { get; set; }

    public PhotoModel(IOptions<CelebritiesConfig> config, IRepository repo)
    {
        _config = config;
        Celebrities = repo.GetAllCelebrities();
    }

    public async Task OnGetAsync()
    {
      
    }

}
