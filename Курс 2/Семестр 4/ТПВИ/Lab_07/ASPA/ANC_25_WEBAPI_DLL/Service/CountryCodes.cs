using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ANC_25_WEBAPI_DLL.Service
{
    public class CountryCodes
    {
        public class Country
        {
            [JsonProperty("countryLabel")]
            public string countryLabel { get; set; }

            [JsonProperty("code")]
            public string code { get; set; }
        }

        private List<Country> _countries;

        public CountryCodes(string jsonFilePath)
        {
            var json = File.ReadAllText(jsonFilePath);
            _countries = JsonConvert.DeserializeObject<List<Country>>(json);
        }

        public List<Country> GetAllCountries()
        {
            return _countries.OrderBy(c => c.countryLabel).ToList();
        }

        public string? GetCountryNameByCode(string code)
        {
            return _countries.FirstOrDefault(c => c.code == code)?.countryLabel;
        }
    }
}
