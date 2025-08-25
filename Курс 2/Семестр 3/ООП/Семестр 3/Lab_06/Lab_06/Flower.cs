using Lab_06;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Lab_06
{
    partial class Flower : Plant, ICloneable
    {
        public override bool DoClone()
        {
            Console.WriteLine("Клонирование через абстрактный класс Plant.\n");

            return true;
        }

        public override string Describe()
        {
            return $"Это цветок по имени {Name}, цвет которого — {Color}.\n";
        }

        public override string ToString()
        {
            return $"Цветок: {Name}, Цвет: {Color}";
        }
    }
}