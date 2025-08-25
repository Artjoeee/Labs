using ANC_25_WEBAPI_DLL;
using ANC_25_WEBAPI_DLL.Service;
using ASPA008_1.Filters;
using ASPA008_1.Models;
using DAL_Celebrity;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;

namespace ASPA008_1.Controllers
{


    [Route("NewCelebrity")]
    public class NewCelebrityController : Controller
    {

        private readonly IRepository _repository;
        private readonly CelebritiesConfig _config;
        private readonly CountryCodes _countryCodes;

        public NewCelebrityController(IRepository repository,
                                      IOptions<CelebritiesConfig> config,
                                      CountryCodes countryCodes)
        {
            _repository = repository;
            _config = config.Value;
            _countryCodes = countryCodes;
        }

        // GET: /NewCelebrity
        [HttpGet]
        public IActionResult New(bool confirm = false, string fullname = null, string nationality = null, string filename = null)
        {
            ViewBag.Countries = _countryCodes.GetAllCountries();
            ViewBag.PhotosRequestPath = _config.PhotosRequestPath;
            ViewBag.PhotosFolder = _config.PhotosFolder;
            ViewBag.Confirm = confirm;

            var celebrity = confirm
                ? new Celebrity { FullName = fullname, Nationality = nationality, ReqPhotoPath = filename }
                : new Celebrity();

            return View("Index", celebrity);
        }

        // POST: /NewCelebrity
        [HttpPost]
        public IActionResult New(Celebrity celebrity, IFormFile ReqPhotoPath, string press)
        {
            ViewBag.Countries = _countryCodes.GetAllCountries();
            ViewBag.PhotosRequestPath = _config.PhotosRequestPath;
            ViewBag.PhotosFolder = _config.PhotosFolder;
            ViewBag.Confirm = false;

            if (string.IsNullOrEmpty(celebrity.FullName))
            {
                ViewBag.ErrorMessage = "Please provide full name";
                return View("Index", celebrity);
            }

            if (string.IsNullOrEmpty(celebrity.Nationality) || celebrity.Nationality.Length != 2)
            {
                ViewBag.ErrorMessage = "Nationality must consist of 2 letters";
                return View("Index", celebrity);
            }

            // Обработка загрузки фото
            if (ReqPhotoPath != null && ReqPhotoPath.Length > 0)
            {
                var extension = Path.GetExtension(ReqPhotoPath.FileName).ToLower();
                var allowedExtensions = new[] { ".jpg", ".jpeg", ".png" };

                if (!allowedExtensions.Contains(extension))
                {
                    ViewBag.ErrorMessage = "Only JPG, JPEG or PNG are allowed";
                    return View("Index", celebrity);
                }

                var fileName = Path.GetFileName(ReqPhotoPath.FileName);
                var filePath = Path.Combine(_config.PhotosFolder, fileName);

                try
                {
                    Directory.CreateDirectory(_config.PhotosFolder);

                    using (var fileStream = new FileStream(filePath, FileMode.Create))
                        ReqPhotoPath.CopyTo(fileStream);

                    celebrity.ReqPhotoPath = fileName;
                }
                catch (Exception ex)
                {
                    ViewBag.ErrorMessage = $"Ошибка при сохранении файла: {ex.Message}";
                    return View("Index", celebrity);
                }
            }

            // Обработка кнопок
            if (press?.ToLower() == "confirm")
            {
                if (_repository.AddCelebrity(celebrity))
                {
                    TempData["SuccessMessage"] = "Celebrity added successfully!";
                    return RedirectToAction("Index", "Celebrities");
                }

                ViewBag.ErrorMessage = "Failed to save data";
            }
            else if (press?.ToLower() == "save")
            {
                return RedirectToAction("New", new
                {
                    confirm = true,
                    fullname = celebrity.FullName,
                    nationality = celebrity.Nationality,
                    filename = celebrity.ReqPhotoPath
                });
            }

            return View("Index", celebrity);
        }
    }
}
