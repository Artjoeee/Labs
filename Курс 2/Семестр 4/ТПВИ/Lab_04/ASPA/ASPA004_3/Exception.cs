namespace ASPA004_3
{
    public class PhotoPathException : Exception
    {
        public PhotoPathException(string message) : base($"PhotoPath error: {message}") { }
    }

    public class UpdException : Exception
    {
        public UpdException(string message) : base($"Update by Id: {message}") { }
    }

    public class DelByIdException : Exception
    {
        public DelByIdException(string message) : base($"Delete by Id: {message}") { }
    }

    public class FoundByIdException : Exception
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
