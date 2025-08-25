using ANC_25_WEBAPI_DLL;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;
using System.Diagnostics.Contracts;

namespace ASPA008_1.Models
{
    public class CelebritiesModel
    {
        public string ReqPhotoPath { get; set; }
        public List<DAL_Celebrity_MSSQL.Celebrity> Celebrities { get; set; }
        public string SuccessMessage { get; set; }
        public string ErrorMessage { get; set; }


    }
}
