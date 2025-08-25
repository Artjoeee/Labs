namespace ASPA005_1
{
    public class ValueException : Exception
    {
        public ValueException(string message) : base($"Value: {message}") { }
    }

    public class AbsurdeException : Exception
    {
        public AbsurdeException(string message) : base($"Absurde: {message}") { }
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
