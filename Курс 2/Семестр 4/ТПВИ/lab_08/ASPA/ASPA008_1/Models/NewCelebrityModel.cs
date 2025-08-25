using System.ComponentModel.DataAnnotations;

namespace ASPA008_1.Models
{
    public class NewCelebrityModel
    {
        [Required]
        public string FullName { get; set; }

        [Required]
        [StringLength(2, MinimumLength = 2)]
        public string Nationality { get; set; }

        public string ReqPhotoPath { get; set; }

        [Required(ErrorMessage = "Upload a photo")]
        public IFormFile PhotoFile { get; set; }
    }
}
