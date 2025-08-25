namespace ASPA004_1
{
    public class FoundByIdException: Exception
    {
        public FoundByIdException(string message) : base($"Found by Id: {message}") { }
    }

    public class SaveException : Exception
    {
        public SaveException(string message) : base($"SaveChanges error: {message}") { }
    }

    public class AddCelebrityException : Exception
    {
        public AddCelebrityException(string message) : base($"AddCelebrityException error: {message}") { }
    }
}
