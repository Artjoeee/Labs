using ANC_25_WEBAPI_DLL;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Options;

namespace ASPA007.Pages
{
    public class CelebritiesModel : PageModel
    {
        private readonly IRepository _repository;
        public IEnumerable<Celebrity> Celebrities { get; set; }
        public string ReqPhotoPath { get; set; }

        public CelebritiesModel(IRepository repository, IOptions<CelebritiesConfig> config)
        {
            _repository = repository;
            ReqPhotoPath = config.Value.PhotosRequestPath;
        }

        public void OnGet()
        {
            Celebrities = _repository.GetAllCelebrities();
        }
    }
}
