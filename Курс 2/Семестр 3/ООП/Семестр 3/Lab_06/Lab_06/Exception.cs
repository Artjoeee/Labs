using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_06
{
    public class PriceOutOfRangeException : ArgumentOutOfRangeException
    {
        public PriceOutOfRangeException() 
            : base("Цена цветка должна быть в пределах от 0 до 1000") { }
    }

    public class FlowerException : Exception
    {
        public FlowerException(string message) : base(message) { }
    }

    public class FlowerNotFoundException : FlowerException
    {
        public FlowerNotFoundException()
            : base($"Цветок с заданным цветом не найден в букете") { }
    }

    // Исключение для проверки некорректных данных при создании цветка
    public class InvalidFlowerDataException : ArgumentException
    {
        public InvalidFlowerDataException(string paramName)
            : base($"Некорректное значение параметра {paramName}") { }
    }
}
