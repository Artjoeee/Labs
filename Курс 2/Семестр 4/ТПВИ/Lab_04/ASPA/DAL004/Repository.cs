using Newtonsoft.Json;

namespace DAL004
{
    public class Repository: IRepository
    {
        public string BasePath { get; }
        public static string? JSONFileName { get; set; }

        public List<Celebrity>? celebrities;
        public static string? JsonPath { get; set; }
        public int UpdateCount { get; set; }

        public Repository(string basePath)
        {
            BasePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, basePath);
            JsonPath = Path.Combine(BasePath, JSONFileName);
            UpdateCount = 0;
            celebrities = JsonConvert.DeserializeObject<List<Celebrity>>(File.ReadAllText(JsonPath));
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

        public int? addCelebrity(Celebrity celebrity)
        {
            if (celebrity.Id == null)
            {
                celebrity.Id = celebrities[celebrities.Count - 1].Id + 1;
            }

            celebrities.Add(celebrity);
            ++UpdateCount; 

            return celebrity.Id;
        }

        public bool delCelebrityById(int id)
        {
            if (getCelebrityById(id) != null)
            {
                celebrities.Remove(getCelebrityById(id));
                ++UpdateCount;

                return true;
            }

            return false;
        }

        public int? updCelebrityById(int id, Celebrity celebrity)
        {
            if (getCelebrityById(id) != null)
            {
                celebrity.Id = id;
                addCelebrity(celebrity);
            }

            delCelebrityById(id);
            ++UpdateCount;

            return id;
        }

        public int SaveChanges()
        {
            File.WriteAllText(JsonPath, JsonConvert.SerializeObject(celebrities, Formatting.Indented));
            return UpdateCount;
        }
    }
}
