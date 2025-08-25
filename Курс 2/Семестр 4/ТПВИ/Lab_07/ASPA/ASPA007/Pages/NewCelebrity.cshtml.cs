using ANC_25_WEBAPI_DLL;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Options;
namespace ASPA007.Pages
{
    public class NewCelebrityModel : PageModel
    {
        private readonly IRepository _repository;
        public string PhotosRequestPath { get; set; }
        public string PhotosFolder { get; set; }

        [BindProperty]
        public Celebrity Celebrity { get; set; }

        [BindProperty]
        public IFormFile Upload { get; set; }

        public bool Confirm { get; set; } = false;

        public NewCelebrityModel(IRepository repository, IOptions<CelebritiesConfig> config)
        {
            _repository = repository;
            PhotosRequestPath = config.Value.PhotosRequestPath;
            PhotosFolder = config.Value.PhotosFolder;
        }

        public void OnGet(bool confirm = false, string fullname = null, string nationality = null, string filename = null)
        {
            Confirm = confirm;

            if (confirm)
            {
                Celebrity = new Celebrity
                {
                    FullName = fullname,
                    Nationality = nationality,
                    ReqPhotoPath = filename
                };
            }
            else
            {
                Celebrity = new Celebrity();
            }
        }

        public IActionResult OnPost(string press)
        {
            try
            {
                if (Upload != null && Upload.Length > 0)
                {
                    var extension = Path.GetExtension(Upload.FileName).ToLower();
                    var allowedExtensions = new[] { ".jpg", ".jpeg", ".png" };

                    if (!allowedExtensions.Contains(extension))
                    {
                        return Page();
                    }

                    var uniqueFileName = Guid.NewGuid().ToString() + extension;

                    if (!Directory.Exists(PhotosFolder))
                    {
                        Directory.CreateDirectory(PhotosFolder);
                    }

                    var filePath = Path.Combine(PhotosFolder, uniqueFileName);

                    using (var fileStream = new FileStream(filePath, FileMode.Create))
                    {
                        Upload.CopyTo(fileStream);
                    }

                    Celebrity.ReqPhotoPath = uniqueFileName;
                }

                if (press?.ToLower() == "confirm")
                {
                    
                    if (_repository.AddCelebrity(Celebrity))
                    {
                        return RedirectToPage("/Celebrities");
                    }
                }
                else if (press?.ToLower() == "save")
                {

                    return RedirectToPage("", new
                    {
                        confirm = true,
                        fullname = Celebrity.FullName,
                        nationality = Celebrity.Nationality,
                        filename = Celebrity.ReqPhotoPath
                    });
                }
            }
            catch (Exception ex)
            {
                
            }

            return Page();
        }
    }
}