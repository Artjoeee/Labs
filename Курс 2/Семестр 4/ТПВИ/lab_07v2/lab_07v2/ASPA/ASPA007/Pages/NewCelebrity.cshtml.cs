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
        [TempData]
        public string SuccessMessage { get; set; }
        public string ErrorMessage { get; set; }
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
                if (string.IsNullOrEmpty(Celebrity.FullName))
                {
                    ErrorMessage = "Please provide full name";
                    return Page();
                }

                if (string.IsNullOrEmpty(Celebrity.Nationality) || Celebrity.Nationality.Length != 2)
                {
                    ErrorMessage = "Nationality must consist of 2 letters";
                    return Page();
                }

                if (Upload != null && Upload.Length > 0)
                {
                    var extension = Path.GetExtension(Upload.FileName).ToLower();
                    var allowedExtensions = new[] { ".jpg", ".jpeg", ".png" };

                    if (!allowedExtensions.Contains(extension))
                    {
                        ErrorMessage = "Only JPG, JPEG or PNG are allowed";
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
                        SuccessMessage = "Celebrity added successfully!";
                        return RedirectToPage("/Celebrities");
                    }
                    else
                    {
                        ErrorMessage = "Failed to save data";
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
                ErrorMessage = $"Error: {ex.Message}";
            }

            return Page();
        }
    }
}