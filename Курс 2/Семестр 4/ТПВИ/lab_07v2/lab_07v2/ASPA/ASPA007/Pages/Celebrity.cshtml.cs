using ANC_25_WEBAPI_DLL;
using DAL_Celebrity_MSSQL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Options;

namespace ASPA007.Pages
{
    public class CelebrityModel : PageModel
    {
        public string? PhotosRequestPath { get; private set; }
        public Celebrity? Celebrity { get; private set; }

        [BindProperty(SupportsGet = true)]
        public Parms? ModelParms { get; set; }

        public IActionResult OnGet()
        {
            if (ModelParms == null || ModelParms.id == null || ModelParms.repo == null || ModelParms.config == null)
                throw new ANC25Exception(Status:500, code: "500001", detail: "CelebrityModel");
            else
            {
                this.PhotosRequestPath = ModelParms.config.Value.PhotosRequestPath;
                return ((this.Celebrity = ModelParms.repo.GetCelebrityById((int)ModelParms.id)) is null)
                    ? NotFound()
                    : ModelParms.AcceptMIMO == "json"
                        ? this.RedirectToRoute("GetCelebrityById", new { Id = ModelParms.id })
                        : Page();
            }
        }

        public class Parms
        {
            [FromRoute]
            public int? id { get; set; }

            [FromQuery(Name = "id")]
            public int? queryid { get; set; }

            [FromHeader(Name = "Accept")]
            public string? acceptheader { get; set; }

            [FromServices]
            public IRepository? repo { get; set; }

            [FromServices]
            public IOptions<CelebritiesConfig>? config { get; set; }

            public string? AcceptMIMO
            {
                get { return preferredAcceptMIMO(acceptheader, new string[] { "json", "html" }).Item1; }
            }

            private (string?, int) preferredAcceptMIMO(string? accept, string[] parms)
            {
                (string?, int) rc = (null, -1);
                if (accept != null)
                {
                    int k = -1, mink = accept.Length + 1, mini = -1;
                    for (int i = 0; i < parms.Length; i++)
                    {
                        if ((k = accept.IndexOf(parms[i], StringComparison.OrdinalIgnoreCase)) >= 0)
                            if (k < mink) { mink = k; mini = i; }
                    }
                    rc = ((mini >= 0) ? parms[mini] : null, mini);
                }
                return rc;
            }
        }
    }
}
