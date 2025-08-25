using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_02
{
    public class Data
    {
        [Required(ErrorMessage = "Выбирите курс")]
        public string Name { get; set; }
        [Required(ErrorMessage = "Выбирите возрастную группу из списка")]
        public string Age { get; set; }
        [Required(ErrorMessage = "Выбирите сложность")]
        public string Complexity { get; set; }
        [Range(1, 20)]
        public string LecturesCount { get; set; }
        [Range(1, 20)]
        public string LabsCount { get; set; }
        [Required(ErrorMessage = "Выбирите вид контроля")]
        public string TypeOfControl { get; set; }
        [Required(ErrorMessage = "Выбирите преподавателя")]
        public string Teacher { get; set; }
        [ListOfReferences]
        public List<string> ListOfReferences { get; set; }
    }

    public class Courses: Data
    {
        public string Budget { get; set; }
    }

    public class Teacher
    {
        [Required(ErrorMessage = "Выбирите кафедру")]
        public string Department { get; set; }
        [Auditorium]
        public string Auditorium { get; set; }
        [Required(ErrorMessage = "Введите имя преподавателя")]
        [RegularExpression(@"^[а-яА-Я\s.]+$")]
        public string FullName { get; set; }
        [Required]
        public string Info { get; set; }
    }

    public class References
    {
        [Required(ErrorMessage = "Введите название книги")]
        [RegularExpression(@"^[a-zA-Zа-яА-Я\s.]+$")]
        public string Book { get; set; }
        [Required(ErrorMessage = "Введите имя автора")]
        [RegularExpression(@"^[а-яА-Я\s.]+$")]
        public string Author { get; set; }
        [Required]
        public string Year { get; set; }
        [Required]
        public string BookInfo { get; set; }
    }

    public class ListOfReferencesAttribute : ValidationAttribute
    {
        public override bool IsValid(object value)
        {
            if (value is List<string> list)
            {
                if (list.Count() != 0)
                    return true;
                else
                    ErrorMessage = "Выбирите список литературы";
            }

            return false;
        }
    }

    public class AuditoriumAttribute : ValidationAttribute
    {
        public override bool IsValid(object value)
        {
            if (value is string auditorium)
            {
                if (auditorium == "100" | auditorium == "101"
                    | auditorium == "102" | auditorium == "103")
                    return true;
                else
                    ErrorMessage = "Выбирите аудиторию из списка";
            }

            return false;
        }
    }
}
