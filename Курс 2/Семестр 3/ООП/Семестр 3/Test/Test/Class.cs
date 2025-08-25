using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    public enum DaysOfWeek
    {
        Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
    }

    public class Computer : IComparable<Computer>
    {
        public string processor;
        public int ram;
        public int price;

        public Computer(string processor, int ram, int price)
        {
            this.processor = processor;
            this.ram = ram;
            this.price = price;
        }

        public int CompareTo(Computer other)
        {
            return price.CompareTo(other.price);
        }

        public string Price(int price, string year)
        {
            return $"{price} {Covert(year)}";
        }

        public static bool operator true(Computer a)
        {
            return false;
        }

        public static bool operator false(Computer b) 
        {
            return true;    
        }

        public static string Covert(string year)
        {
            if (year == "1999")
            {
                
                return "Рубль";
            }
            else
            {
                return "Доллар";
            }
        }
    }
}
