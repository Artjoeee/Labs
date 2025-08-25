using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_03
{
    // Класс Set, поддерживающий элементы типа T, где T должен реализовывать интерфейс IComparable<T>
    public class Set<T> where T : IComparable<T>  
    {
        private HashSet<T> _elements;  // Поле, содержащее элементы множества

        // Вложенный класс Production
        public class Production
        {
            public Guid Id { get; }
            public string Organization { get; set; }

            // Конструктор для инициализации Id и Organization
            public Production(string organization)
            {
                Id = Guid.NewGuid();  // Генерация уникального идентификатора
                Organization = organization;
            }

            // Переопределение метода ToString
            public override string ToString()
            {
                return $"Production Id: {Id}, Organization: {Organization}";
            }
        }

        // Вложенный класс Developer
        public class Developer
        {
            public string FullName { get; set; }
            public Guid Id { get; }
            public string Department { get; set; }

            // Конструктор для инициализации полей FullName, Id и Department
            public Developer(string fullName, string department)
            {
                FullName = fullName;
                Id = Guid.NewGuid();
                Department = department;
            }

            // Переопределение метода ToString
            public override string ToString()
            {
                return $"Developer: {FullName}, Id: {Id}, Department: {Department}";
            }
        }

        // Свойства для хранения информации о производстве и разработчике
        public Production ProductionInfo { get; set; }
        public Developer DeveloperInfo { get; set; }

        // Конструктор по умолчанию, инициализирующий пустой HashSet
        public Set()
        {
            _elements = new HashSet<T>();  // Создание пустого множества элементов
        }

        // Конструктор, принимающий коллекцию элементов и инициализирующий HashSet
        public Set(IEnumerable<T> elements)
        {
            _elements = new HashSet<T>(elements);  // Инициализация множества элементами из переданной коллекции
        }

        // Метод для добавления элемента в множество
        public void Add(T element)
        {
            _elements.Add(element);
        }

        // Перегрузка оператора "-" для удаления элемента из множества
        public static Set<T> operator -(Set<T> set, T element)
        {
            set._elements.Remove(element);
            return set;
        }

        // Перегрузка оператора "*" для пересечения двух множеств
        public static Set<T> operator *(Set<T> set1, Set<T> set2)
        {
            return new Set<T>(set1._elements.Intersect(set2._elements));
        }

        // Перегрузка оператора "<" для проверки, является ли первое множество подмножеством второго
        public static bool operator <(Set<T> set1, Set<T> set2)
        {
            return set1._elements.IsSubsetOf(set2._elements);
        }

        // Перегрузка оператора ">" для проверки, является ли первое множество надмножеством второго
        public static bool operator >(Set<T> set1, Set<T> set2)
        {
            return set2._elements.IsSubsetOf(set1._elements);
        }

        // Перегрузка оператора "&" для объединения двух множеств
        public static Set<T> operator &(Set<T> set1, Set<T> set2)
        {
            return new Set<T>(set1._elements.Union(set2._elements));
        }

        // Метод для удаления всех нулевых элементов из множества
        public void RemoveZeroElements()
        {
            _elements.RemoveWhere(e => e.CompareTo(default) == 0);  // Удаляет элементы, которые равны значению по умолчанию
        }

        // Переопределение метода ToString для вывода элементов множества в виде строки
        public override string ToString()
        {
            return string.Join(", ", _elements);
        }

        // Метод для получения элементов множества (используется в статистических операциях)
        public HashSet<T> GetElements()
        {
            return _elements;
        }
    }

    // Статический класс для статистических операций с множествами
    public static class StatisticOperation
    {
        // Метод для подсчета суммы элементов множества
        public static T Sum<T>(Set<T> set) where T : struct, IComparable<T>
        {
            dynamic sum = 0;

            foreach (var item in set.GetElements())  // Проход по всем элементам множества
            {
                sum += (dynamic)item;
            }

            return (T)sum;
        }

        // Метод для вычисления разницы между максимальным и минимальным элементом множества
        public static T DifferenceMaxMin<T>(Set<T> set) where T : IComparable<T>
        {
            var elements = set.GetElements().ToList();
            return (dynamic)elements.Max() - (dynamic)elements.Min();
        }

        // Метод для подсчета количества элементов в множестве
        public static int Count<T>(Set<T> set) where T : IComparable<T>
        {
            return set.GetElements().Count;
        }
    }

    // Статический класс с методами расширения для типа string
    public static class StringExtensions
    {
        // Метод расширения для добавления точки в конце строки, если её нет
        public static string AddPeriod(this string str)
        {
            return str.EndsWith(".") ? str : str + ".";
        }
    }

    // Статический класс с методами расширения для множества Set<int>
    public static class SetExtensions
    {
        // Метод расширения для удаления всех нулевых элементов из множества
        public static void RemoveZero(this Set<int> set)
        {
            set.RemoveZeroElements();  // Вызов метода для удаления нулевых элементов
        }
    }
}