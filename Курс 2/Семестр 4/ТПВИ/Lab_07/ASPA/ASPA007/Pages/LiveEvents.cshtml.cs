using ANC_25_WEBAPI_DLL;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Options;

namespace ASPA007.Pages
{
    public class LiveEventsModel : PageModel
    {
        private readonly IOptions<CelebritiesConfig> _config;

        public List<Celebrity> Celebrities { get; set; }
        public string ReqPhotoPath { get; set; }

        public LiveEventsModel(IOptions<CelebritiesConfig> config, IRepository repo)
        {
            _config = config;
            Celebrities = repo.GetAllCelebrities();
            ReqPhotoPath = config.Value.PhotosRequestPath;
        }

        public async Task OnGetAsync()
        {

        }
    }
}
