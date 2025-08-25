using System;
using System.Net;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;

namespace ANC_25_WEBAPI_DLL
{
    public class MiddlewareErrorHandler
    {
        private readonly RequestDelegate _next;
        private readonly ILogger<MiddlewareErrorHandler> _logger;

        public MiddlewareErrorHandler(RequestDelegate next, ILogger<MiddlewareErrorHandler> logger)
        {
            _next = next;
            _logger = logger;
        }

        public async Task InvokeAsync(HttpContext context)
        {
            try
            {
                await _next(context);
            }
            catch (Exception ex)
            {
                await HandleExceptionAsync(context, ex);
            }
        }

        private async Task HandleExceptionAsync(HttpContext context, Exception exception)
        {
            context.Response.ContentType = "application/json";

            var errorResponse = new
            {
                StatusCode = StatusCodes.Status500InternalServerError,
                Code = "UNKNOWN",
                Message = exception.Message,
                Details = exception.StackTrace
            };

            if (exception is ANC25Exception anc25Exception)
            {
                context.Response.StatusCode = anc25Exception.Status;
                errorResponse = new
                {
                    StatusCode = anc25Exception.Status,
                    Code = anc25Exception.Code,
                    Message = exception.Message,
                    Details = anc25Exception?.Detail
                };
            }
            else if (exception is FileNotFoundException)
            {
                context.Response.StatusCode = StatusCodes.Status404NotFound;
                errorResponse = new
                {
                    StatusCode = StatusCodes.Status404NotFound,
                    Code = "404",
                    Message = "Resource not found",
                    Details = exception?.Message
                };
            }
            else if (exception is UnauthorizedAccessException)
            {
                context.Response.StatusCode = StatusCodes.Status401Unauthorized;
                errorResponse = new
                {
                    StatusCode = StatusCodes.Status401Unauthorized,
                    Code = "401",
                    Message = "Unauthorized access",
                    Details = exception?.Message
                };
            }
            else if (exception is ArgumentException)
            {
                context.Response.StatusCode = StatusCodes.Status400BadRequest;
                errorResponse = new 
                {
                    StatusCode = StatusCodes.Status400BadRequest,
                    Code = "400",
                    Message = "Invalid arguments",
                    Details = exception?.Message
                };
            }

            _logger.LogError(exception, "An error occurred: {Message}", exception?.Message);

            await context.Response.WriteAsJsonAsync(errorResponse);
        }
    }

    public class ANC25Exception : Exception
    {
        public int Status { get; }
        public string Code { get; }
        public string Detail { get; }

        public ANC25Exception(int Status, string code, string detail)
            : base($"Error {Status}: {detail}")
        {
            this.Status = Status;
            Code = code;
            Detail = detail;
        }
    }
}