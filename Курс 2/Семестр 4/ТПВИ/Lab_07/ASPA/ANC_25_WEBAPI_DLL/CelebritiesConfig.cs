using Microsoft.Extensions.DependencyInjection;
using System.Runtime.CompilerServices;
namespace ANC_25_WEBAPI_DLL
{
    public class CelebritiesConfig
    {
        public string PhotosFolder      { get; set; }
        public string ConnectionString  { get; set; }
        public string PhotosRequestPath { get; set; }
        public string CountryCodes { get; set; }
        public CelebritiesConfig()
        {
            this.PhotosFolder = "wwwroot/Celebrities";
            this.ConnectionString = @"Server=(localdb)\mssqllocaldb; Database=CELEBRITIES; Trusted_Connection=True;";
            this.PhotosRequestPath = "./Celebrities";
            this.CountryCodes = "C:\\Users\\HomeUser\\Desktop\\Курс 2\\Семестр 2\\ТПВИ\\Lab_07\\ASPA\\ANC_25_WEBAPI_DLL\\country-codes.json";
        }
    }
}

