using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    internal class Program
    {
        static void Main(string[] args)
        {
            foreach (var item in Enum.GetValues(typeof(DaysOfWeek)))
            {
                Console.WriteLine($"{item}");
            }

            int[] arr = { 1, 2, 3, 4, 5 };
            string str = "";

            foreach (var item in arr)
            {
                string value = item.ToString();
                str += value;
            }

            int num = int.Parse(str);
            Console.WriteLine(num);

            Computer asus = new Computer("intel", 16, 1000);
            Computer dell = new Computer("amd", 8, 800);

            if (asus.CompareTo(dell) == -1)
            {
                Console.WriteLine("asus < dell");
            }
            else if (asus.CompareTo(dell) == 0)
            {
                Console.WriteLine("asus = dell");
            }
            else
            {
                Console.WriteLine("asus > dell");
            }

            Console.WriteLine(dell.Price(dell.price, "1999"));
        }
    }
}
