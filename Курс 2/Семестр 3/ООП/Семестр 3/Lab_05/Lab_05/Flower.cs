using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_05
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
