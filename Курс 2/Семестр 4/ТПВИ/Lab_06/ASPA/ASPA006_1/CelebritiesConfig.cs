public class CelebritiesConfig
{
    public JSONSection? JSON { get; set; }
    public MSSQLSection? MSSQL { get; set; }
    public class JSONSection
    {
        public string? Path { get; set;}
        public string? File { get; set;}
    }
    public class MSSQLSection
    {
        public string? ConnectionString { get; set; }
    }
}