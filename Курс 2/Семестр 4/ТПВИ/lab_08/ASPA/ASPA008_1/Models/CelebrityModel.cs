using DAL_Celebrity_MSSQL;

namespace ASPA008_1.Models
{
    public record CelebrityModel(string photosrequestpath, Celebrity celebrity, List<LifeEvent> lifeevents, Dictionary<string, string>? references);
}
