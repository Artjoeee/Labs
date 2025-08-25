using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_01
{
    public class EmptyStringException : Exception
    {
        public EmptyStringException() : base("Пустая строка. Пожалуйста, введите текст") { }
    }

    public class EmptySubstringException : Exception
    {
        public EmptySubstringException() : base("Пожалуйста, введите подстроку") { }
    }

    public class WrongIndexException : Exception
    {
        public WrongIndexException() : base("Неверный индекс") { }
    }

    public class WrongPunctuationException : Exception
    {
        public WrongPunctuationException() : base("Ошибка пунктуации") { }
    }
}
