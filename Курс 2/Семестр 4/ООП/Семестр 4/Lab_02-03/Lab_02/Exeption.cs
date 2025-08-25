using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_02
{
    public class EmptyFullNameException : Exception
    {
        public EmptyFullNameException() 
            : base("Введите имя преподавателя") { }
    }

    public class EmptyListOfReferencesException : Exception
    {
        public EmptyListOfReferencesException() 
            : base("Пустой список литературы") { }
    }

    public class EmptyComplexityException : Exception
    {
        public EmptyComplexityException()
            : base("Выбирите сложность") { }
    }

    public class EmptyTypeOfControlException : Exception
    {
        public EmptyTypeOfControlException()
            : base("Выбирите вид контроля") { }
    }

    public class EmptyCourseException : Exception
    {
        public EmptyCourseException()
            : base("Выбирите курс") { }
    }

    public class WrongAgeException : Exception
    {
        public WrongAgeException()
            : base("Выбирите возрастную группу из списка") { }
    }

    public class WrongLabsNumberException : Exception
    {
        public WrongLabsNumberException()
            : base("Недопустимое количество лабораторных работ") { }
    }

    public class WrongLecturesNumberException : Exception
    {
        public WrongLecturesNumberException()
            : base("Недопустимое количество лекций") { }
    }

    public class TeacherAbsenceExeption : Exception
    {
        public TeacherAbsenceExeption()
            : base("Выбирите преподавателя") { }
    }

    public class WrongClassroomExсeption : Exception
    {
        public WrongClassroomExсeption()
            : base("Выбирите аудиторию из списка") { }
    }

    public class EmptyDepartmentException : Exception
    {
        public EmptyDepartmentException()
            : base("Выбирите кафедру") { }
    }

    public class EmptyBookException : Exception
    {
        public EmptyBookException()
            : base("Введите название книги") { }
    }

    public class EmptyAuthorException : Exception
    {
        public EmptyAuthorException()
            : base("Введите имя автора") { }
    }
}
