using ANC_25_WEBAPI_DLL;
using ASPA008_1.Models;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;

namespace ASPA008_1.Controllers
{
    public class CelebritiesController : Controller
    {
        private readonly IRepository _repository;
        private readonly string _reqPhotoPath;

        public CelebritiesController(IRepository repository, IOptions<CelebritiesConfig> config)
        {
            _repository = repository;
            _reqPhotoPath = config.Value.PhotosRequestPath;
        }

        public IActionResult Index()
        {
            var model = new CelebritiesModel
            {
                ReqPhotoPath = _reqPhotoPath,
                Celebrities = _repository.GetAllCelebrities().ToList(),
                SuccessMessage = TempData["SuccessMessage"]?.ToString(),
                ErrorMessage = TempData["ErrorMessage"]?.ToString()
            };

            return View(model);
        }

      
    }
}
