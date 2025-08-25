using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Control
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите 2 числа:");

            int value1 = int.Parse(Console.ReadLine());
            int value2 = int.Parse(Console.ReadLine());

            string sum = $"{value1 + value2}";

            Console.WriteLine($"Их сумма: {sum}");

            string[,] arr = { { "one", "two" }, { "three", "four" } };

            int count = 0;

            foreach (var item in arr)
            {
                count += item.Count(Char.IsLetter);
            }

            Console.WriteLine(count);

            Point a = new Point(-1, 3, 9);
            Point b = new Point(5, 4, 4);

            Line list = new Line(a, b);

            var c = a + b;
            var d = a - b;

            Console.WriteLine(c);
            Console.WriteLine(d);

            int sum1 = a.X + a.Y + a.Z;
            int sum2 = b.X + b.Y + b.Z;

            if (sum1.CompareTo(sum2) == -1)
            {
                Console.WriteLine("<");
            }
            else if (sum1.CompareTo(sum2) == 0)
            {
                Console.WriteLine("=");
            }
            else
            {
                Console.WriteLine(">");
            }

            Console.WriteLine(list.First());
        }
    }
}
