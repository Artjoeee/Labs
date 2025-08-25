using ANC_25_WEBAPI_DLL;
using ASPA008_1.Filters;
using ASPA008_1.Models;
using DAL_Celebrity;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;

namespace ASPA008_1.Controllers
{
    public class CelebrityController : Controller
    {
        private readonly IRepository _repo;
        private readonly IOptions<CelebritiesConfig> _config;

        public CelebrityController(IRepository repo, IOptions<CelebritiesConfig> config)
        {
            _repo = repo;
            _config = config;
        }
       

        [HttpGet("/Celebrity/{id:int}")]
        [InfoAsyncActionFilter(infotype: "Wikipedia, Facebook")]
        public IActionResult Human(int id)
        {
            var celebrity = _repo.GetCelebrityById(id);
            if (celebrity == null)
                return NotFound();

            var references = HttpContext.Items[InfoAsyncActionFilter.Wikipedia] as Dictionary<string, string>;

            var lifeEvents = _repo.GetLifeEventsByCelebrityId(id) ?? new List<LifeEvent>();

            var model = new CelebrityModel(
                _config.Value.PhotosRequestPath,
                celebrity,
                lifeEvents,
                references
            );

            return View(model); // Views/Celebrity/Human.cshtml
        }


    }
}
