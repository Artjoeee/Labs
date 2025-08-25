using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_03
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Тестирование класса Set с элементами типа int
            Set<int> set1 = new Set<int>(new List<int> { 1, 2, 3, 0 });
            Set<int> set2 = new Set<int>(new List<int> { 2, 3, 4 });

            set1.RemoveZero();

            Console.WriteLine("Set1: " + set1);
            Console.WriteLine("Set2: " + set2);

            // Пересечение множеств set1 и set2
            Set<int> intersection = set1 * set2;
            Console.WriteLine("Пересечение: " + intersection);

            // Объединение множеств set1 и set2
            Set<int> union = set1 & set2;
            Console.WriteLine("Объединение: " + union);

            // Проверка, является ли set1 подмножеством set2
            Console.WriteLine("Set1 является подмножеством Set2: " + (set1 < set2));

            // Проверка, является ли set1 надмножеством set2
            Console.WriteLine("Set1 является надмножеством Set2: " + (set1 > set2));

            // Удаление элемента 1 из множества set1
            set1 = set1 - 1;
            Console.WriteLine("Set1 после удаления 1: " + set1);
            
            // Инициализация вложенных объектов Production и Developer
            set1.ProductionInfo = new Set<int>.Production("Microsoft");
            set1.DeveloperInfo = new Set<int>.Developer("Artsiom Zhamoida", "Development");

            Console.WriteLine(set1.ProductionInfo);
            Console.WriteLine(set1.DeveloperInfo);

            // Тестирование статистических операций
            Console.WriteLine("Сумма элементов Set1: " + StatisticOperation.Sum(set1));
            Console.WriteLine("Разница между максимальным и минимальным элементами Set1: " + StatisticOperation.DifferenceMaxMin(set1));
            Console.WriteLine("Количество элементов Set1: " + StatisticOperation.Count(set1));

            // Тестирование метода расширения для строк
            string str = "Hello";
            Console.WriteLine("Добавление точки в конец строки: " + str.AddPeriod());
        }
    }
}
