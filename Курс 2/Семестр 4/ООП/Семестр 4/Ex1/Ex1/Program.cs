using Ex1;

internal class Program
{
    private static void Main(string[] args)
    {
        var student1 = new Student("Антон", 19, new List<int> { 5, 6, 7 });
        var student2 = new Student("Артем", 19, new List<int> { 6, 7, 8 });
        var student3 = new Student("Вика", 19, new List<int> { 7, 8, 9 });

        Console.WriteLine(Student.Mid(student2));
    }
}