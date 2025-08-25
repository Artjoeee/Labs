

namespace DAL_Celebrity_MSSQL
{
    public interface IRepository : DAL_Celebrity.IRepository<Celebrity, LifeEvent> { }

    public class Celebrity  // Знаменитость
    {
        public Celebrity() { this.FullName = string.Empty; this.Nationality = string.Empty; }
        public int Id { get; set; }                     // Id Знаменитости
        public string FullName { get; set; }            // полное имя Знаменитости
        public string Nationality { get; set; }         // гражданство Знаменитости (2 символа ISO)
        public string? ReqPhotoPath { get; set; }       // request path Фотографии
        public virtual bool Update(Celebrity celebrity) // вспомогательный метод
        {
            if (celebrity == null) return false;
            bool isUpdated = false;
            if (!string.IsNullOrEmpty(celebrity.FullName))      { this.FullName = celebrity.FullName;            isUpdated = true; }
            if (!string.IsNullOrEmpty(celebrity.Nationality))   { this.Nationality = celebrity.Nationality;      isUpdated = true; }
            if (celebrity.ReqPhotoPath != null)                 { this.ReqPhotoPath = celebrity.ReqPhotoPath;    isUpdated = true; }
            return isUpdated;
        }
    }

    public class LifeEvent // Событие в жизни знаменитости
    {
        public LifeEvent() { this.Description = string.Empty; }
        public int Id { get; set; }                     // Id События
        public int CelebrityId { get; set; }            // Id Знаменитости
        public DateTime? Date { get; set; }             // дата События
        public string Description { get; set; }         // описание События
        public string? ReqPhotoPath { get; set; }       // request path Фотографии
        public virtual bool Update(LifeEvent lifeEvent) // вспомогательный метод
        {
            if (lifeEvent == null) return false;
            bool isUpdated = false;
            if (lifeEvent.CelebrityId != 0)                     { this.CelebrityId = lifeEvent.CelebrityId;     isUpdated = true; }
            if (lifeEvent.Date.HasValue)                        { this.Date = lifeEvent.Date;                   isUpdated = true; }
            if (!string.IsNullOrEmpty(lifeEvent.Description))   { this.Description = lifeEvent.Description;     isUpdated = true; }
            if (lifeEvent.ReqPhotoPath != null)                 { this.ReqPhotoPath = lifeEvent.ReqPhotoPath;   isUpdated = true; }
            return isUpdated;
        }
    }
}
