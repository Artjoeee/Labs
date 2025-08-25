using Newtonsoft.Json;
using System.Runtime.CompilerServices;

namespace DAL003
{
    public class Repository : IRepository
    {
        public string BasePath { get; }

        public static string? JSONFileName { get; set; }

        public List<Celebrity>? celebrities;

        public Repository(string basePath)
        {
            BasePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, basePath);
            string jsonPath = Path.Combine(BasePath, JSONFileName);

            celebrities = JsonConvert.DeserializeObject<List<Celebrity>>(File.ReadAllText(jsonPath));
        }

        public void Dispose()
        {
            celebrities.Clear();
        }

        public Celebrity[] getAllCelebrities()
        {
            return celebrities.ToArray();
        }

        public Celebrity[] getCelebritiesBySurname(string surname)
        {
            return celebrities.Where(c => c.Surname.Equals(surname)).ToArray();
        }

        public Celebrity? getCelebrityById(int id)
        {
            return celebrities.FirstOrDefault(c => c.Id == id);
        }

        public string? getPhotoPathById(int id)
        {
            Celebrity celebrity = getCelebrityById(id);

            if (celebrity != null)
            {
                string photoPath = Path.Combine(BasePath, celebrity.PhotoPath);
                return photoPath;
            }

            return null;
        }

        public static IRepository Create(string basePath)
        {
            return new Repository(basePath);
        }
    }
}
