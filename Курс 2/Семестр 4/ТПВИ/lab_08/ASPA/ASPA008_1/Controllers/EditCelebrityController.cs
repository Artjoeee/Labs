using ANC_25_WEBAPI_DLL;
using ANC_25_WEBAPI_DLL.Service;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;

namespace ASPA008_1.Controllers
{
    [Route("Edit")]
    public class EditCelebrityController : Controller
    {
        private readonly IRepository _repository;
        private readonly CelebritiesConfig _config;
        private readonly CountryCodes _countryCodes;

        public EditCelebrityController(IRepository repository,
                                      IOptions<CelebritiesConfig> config,
                                      CountryCodes countryCodes)
        {
            _repository = repository;
            _config = config.Value;
            _countryCodes = countryCodes;
        }


        // GET: /Edit/{id}
        [HttpGet("{id:int}")]
        public IActionResult Edit(int id, bool confirm = false, string fullname = null, string nationality = null, string filename = null)
        {
            ViewBag.Countries = _countryCodes.GetAllCountries();
            ViewBag.PhotosRequestPath = _config.PhotosRequestPath;
            ViewBag.Confirm = confirm;

            Celebrity celebrity;

            if (confirm)
            {
                celebrity = new Celebrity
                {
                    Id = id,
                    FullName = fullname,
                    Nationality = nationality,

                    ReqPhotoPath = string.IsNullOrEmpty(filename)
                         ? TempData["Filename"] as string
                         : filename
                };
            }
            else
            {
                celebrity = _repository.GetCelebrityById(id);
                if (celebrity == null)
                    return NotFound();
            }

            return View("EditCelebrity", celebrity);
        }

        // POST: /Edit/{id}
        [HttpPost("{id:int}")]
        public IActionResult Edit(int id, Celebrity celebrity, IFormFile ReqPhotoPath, string press, string OldPhotoPath)
        {
            ViewBag.Countries = _countryCodes.GetAllCountries();
            ViewBag.PhotosRequestPath = _config.PhotosRequestPath;
            ViewBag.PhotosFolder = _config.PhotosFolder;

            if (id != celebrity.Id)
                return BadRequest();

            // По умолчанию Confirm = false, при нажатии "save" устанавливаем true для показа подтверждения
            ViewBag.Confirm = false;

            if (string.IsNullOrEmpty(celebrity.FullName))
            {
                ViewBag.ErrorMessage = "Please provide full name";
                return View("EditCelebrity", celebrity);
            }

            if (string.IsNullOrEmpty(celebrity.Nationality) || celebrity.Nationality.Length != 2)
            {
                ViewBag.ErrorMessage = "Nationality must consist of 2 letters";
                return View("EditCelebrity", celebrity);
            }

            var existingCelebrity = _repository.GetCelebrityById(id);
            if (existingCelebrity == null)
                return NotFound();

            if (ReqPhotoPath != null && ReqPhotoPath.Length > 0)
            {
                var extension = Path.GetExtension(ReqPhotoPath.FileName).ToLower();
                var allowedExtensions = new[] { ".jpg", ".jpeg", ".png" };

                if (!allowedExtensions.Contains(extension))
                {
                    ViewBag.ErrorMessage = "Only JPG, JPEG or PNG are allowed";
                    return View("EditCelebrity", celebrity);
                }

                var fileName = Path.GetFileName(ReqPhotoPath.FileName);
                var filePath = Path.Combine(_config.PhotosFolder, fileName);

                try
                {
                    Directory.CreateDirectory(_config.PhotosFolder);

                    using (var stream = new FileStream(filePath, FileMode.Create))
                    {
                        ReqPhotoPath.CopyTo(stream);
                    }

                    celebrity.ReqPhotoPath = fileName;
                }
                catch (Exception ex)
                {
                    return Content($"Ошибка при сохранении файла: {ex.Message}");
                }
            }
            else
            {
                celebrity.ReqPhotoPath = OldPhotoPath;
            }

            if (!string.IsNullOrEmpty(press))
            {
                if (press.ToLower() == "confirm")
                {
                    // Сохраняем изменения в репозиторий
                    if (_repository.UpdCelebrity(id, celebrity))
                    {
                        TempData["SuccessMessage"] = "Celebrity updated successfully!";
                        return RedirectToAction("Index", "Celebrities");
                    }

                    TempData["ErrorMessage"] = "Not update data by celebrity";
                    return RedirectToAction("Index", "Celebrities");
                }
                else if (press.ToLower() == "save")
                {
                    // Отобразить форму с подтверждением (readonly)
                    ViewBag.Confirm = true;
                    return View("EditCelebrity", celebrity);
                }
            }

            // Если press пустой или другой — показать обычную форму редактирования
            return View("EditCelebrity", celebrity);
        }


    }
}
