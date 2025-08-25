using ANC_25_WEBAPI_DLL;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;

namespace ASPA008_1.Controllers
{
    public class DelCelebrityController : Controller
    {
        private readonly IRepository _repo;
        private readonly IOptions<CelebritiesConfig> _config;

        public DelCelebrityController(IRepository repo, IOptions<CelebritiesConfig> config)
        {
            _repo = repo;
            _config = config;
        }

        [HttpGet("/Delete/{id:int}")]
        public IActionResult ConfirmDelete(int id)
        {
            var celeb = _repo.GetCelebrityById(id); // твой метод в репозитории
            if (celeb == null)
                return NotFound();

            return View("DelCelebrity", celeb);
        }

        [HttpPost("Delete/{id:int}")]
        public IActionResult Delete(int id)
        {
            try
            {
                bool deleted = _repo.DelCelebrity(id);
                if (deleted)
                {
                    TempData["SuccessMessage"] = "Celebrity deleted successfully.";
                    return RedirectToAction("Index", "Celebrities"); // возврат к списку
                }
                else
                {
                    TempData["ErrorMessage"] = "Celebrity not found or couldn't be deleted.";
                    return RedirectToAction("Index", new { id });
                }
            }
            catch (Exception ex)
            {
                TempData["ErrorMessage"] = $"Error: {ex.Message}";
                return RedirectToAction("Index", new { id });
            }
        }
    }
}
