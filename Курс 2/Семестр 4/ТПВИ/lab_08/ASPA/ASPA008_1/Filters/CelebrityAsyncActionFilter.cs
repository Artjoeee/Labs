using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc.Filters;
using System.Text.Json;

namespace ASPA008_1.Filters
{

    public class InfoAsyncActionFilter : Attribute, IAsyncActionFilter
    {
        public static readonly string Wikipedia = "WIKI";
        public static readonly string Facebook = "FACE";

        private readonly string infotype;


        public InfoAsyncActionFilter(string infotype = "")
        { 
            this.infotype = infotype.ToUpper(); 
        }

        public async Task OnActionExecutionAsync(ActionExecutingContext context, ActionExecutionDelegate next)
        {
            IRepository? repo = context.HttpContext.RequestServices.GetService<IRepository>();
            int id = (int)(context.ActionArguments["id"] ?? -1);
            Celebrity? celebrity = repo?.GetCelebrityById(id);

            if (infotype.Contains(Wikipedia) && celebrity != null)
                context.HttpContext.Items.Add(Wikipedia, await WikiInfoCelebrity.GetReferences(celebrity.FullName));

            if (infotype.Contains(Facebook) && celebrity != null)
                context.HttpContext.Items.Add(Facebook, GetFromFace(celebrity.FullName));

            await next();
        }

        private string GetFromFace(string fullName)
        {
            return "Info from face";
        }
    }

    public class WikiInfoCelebrity
    {
        private HttpClient client;
        Dictionary<string, string> wikiReferences;
        string wikiURI;

        private WikiInfoCelebrity(string fullName)
        {
            client = new HttpClient();
            wikiReferences = new Dictionary<string, string>();
            wikiURI = $"https://en.wikipedia.org/w/api.php?action=opensearch&search={Uri.EscapeDataString(fullName)}&format=json";
        }

        public static async Task<Dictionary<string, string>> GetReferences(string fullName)
        {
            WikiInfoCelebrity info = new WikiInfoCelebrity(fullName);
            HttpResponseMessage message = await info.client.GetAsync(info.wikiURI);
            if (message.StatusCode == System.Net.HttpStatusCode.OK)
            {
                List<dynamic>? result = await message.Content.ReadFromJsonAsync<List<dynamic>>() ?? default(List<dynamic>);
                List<string>? ls1 = JsonSerializer.Deserialize<List<string>>(result[1]);
                List<string>? ls3 = JsonSerializer.Deserialize<List<string>>(result[3]);
                for (int i = 0; i < ls1.Count; i++)
                {
                    info.wikiReferences.Add(ls1[i], ls3[i]);
                }
            }


            return info.wikiReferences;
        }
    }
}
