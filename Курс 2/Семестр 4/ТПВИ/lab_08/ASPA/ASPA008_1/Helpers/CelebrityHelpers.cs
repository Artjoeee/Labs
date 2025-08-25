using Microsoft.AspNetCore.Html;
using Microsoft.AspNetCore.Mvc.Rendering;
using System.Text.Encodings.Web;

namespace ASPA008_1.Helpers
{
    public static class CelebrityHelpers
    {
        public static HtmlString CelebrityPhoto<TModel>(this IHtmlHelper<TModel> htmlHelper,
                                                         int id,
                                                         string fullName,
                                                         string nationality,
                                                         string photoPath,
                                                         string basePath)
        {
            var anchorHref = $"/Celebrity/{id}";
            var imgSrc = $"{basePath}/{photoPath}";

            string html = $@"
                <div class=""celebrity-card"">
                    <a href=""{anchorHref}"">
                        <img src=""{imgSrc}"" alt=""{HtmlEncoder.Default.Encode(fullName)}"" />
                    </a>
                    <h3>{HtmlEncoder.Default.Encode(fullName)}</h3>
                    <p>{HtmlEncoder.Default.Encode(nationality)}</p>
                </div>";

            return new HtmlString(html);
        }
    }
}
