using DAL004;

namespace Validation
{
    public class SurnameFilter : IEndpointFilter
    {
        internal static IRepository? repository;

        public async ValueTask<object?> InvokeAsync(EndpointFilterInvocationContext context, EndpointFilterDelegate next)
        {
            Celebrity? celebrity = context.GetArgument<Celebrity>(0);

            if (celebrity == null)
            {
                throw new ASPA005_2.AbsurdeException("POST /Celebrities error, loc = 001");
            }

            if (celebrity.Surname == null || celebrity.Surname.Length <= 1)
            {
                throw new ASPA005_2.ValueException("POST /Celebrities error, Surname is wrong");
            }

            if (repository.getCelebritiesBySurname(celebrity.Surname).Length > 0)
            {
                throw new ASPA005_2.ValueException("POST /Celebrities error, Surname is doubled");
            }

            return await next(context);
        }
    }

    public class PhotoExistFilter : IEndpointFilter
    {
        internal static IRepository? repository;

        public async ValueTask<object?> InvokeAsync(EndpointFilterInvocationContext context, EndpointFilterDelegate next)
        {
            Celebrity? celebrity = context.GetArgument<Celebrity>(0);

            object? result = await next(context);

            string fn = Path.GetFileName(celebrity.PhotoPath);

            if (!File.Exists(Path.Combine(repository.BasePath, $"{fn}")))
            {
                if (context != null)
                {
                    context.HttpContext.Response.Headers.Append("X-Celebrity", $"NotFound = {fn}");
                }
            }

            return result;
        }
    }

    public class UpdateFilter : IEndpointFilter
    {
        internal static IRepository? repository;

        public async ValueTask<object?> InvokeAsync(EndpointFilterInvocationContext context, EndpointFilterDelegate next)
        {
            if (repository.SaveChanges() <= 0)
            {
                throw new ASPA005_2.SaveException("/Celebrities error, SaveChanges() <= 0");
            }

            return await next(context);
        }
    }

    public class IdFilter : IEndpointFilter
    {
        internal static IRepository? repository;

        public async ValueTask<object?> InvokeAsync(EndpointFilterInvocationContext context, EndpointFilterDelegate next)
        {
            var id = (int)context.Arguments[0];

            if (repository.getCelebrityById(id) == null)
            {
                throw new ASPA005_2.FoundByIdException($"/Celebrities error, Id = {id}");
            }

            return await next(context);
        }
    }
}
