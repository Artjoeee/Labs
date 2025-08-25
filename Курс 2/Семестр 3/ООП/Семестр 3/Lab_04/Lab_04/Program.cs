using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_04
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Plant rose = new Rose { Name = "Прекрасная роза", Color = "Красный", ThornCount = 10 };
            Plant gladiolus = new Gladiolus { Name = "Великолепный гладиолус", Color = "Белый", PetalCount = 15 };
            Plant cactus = new Cactus { Name = "Пустынный кактус", NeedleCount = 100 };

            Bush bush = new Bush { Name = "Зелёный куст", Type = "Вечнозелёный" };

            Paper wrappingPaper = new Paper { Material = "Упаковочная" };

            Bouquet bouquet = new Bouquet { Wrapper = wrappingPaper };

            bouquet.Flowers.Add((Flower)rose);
            bouquet.Flowers.Add((Flower)gladiolus);

            Console.WriteLine(rose.Describe());

            Flower flower = new Flower { Name = "Роза", Color = "Красный" };

            ICloneable cloneableFlower = flower;
            Console.WriteLine("Вызов метода DoClone() через интерфейс ICloneable:");
            cloneableFlower.DoClone();

            Console.WriteLine("\nВызов метода DoClone() через абстрактный класс Plant:");
            flower.DoClone();

            // Проверка типа объекта с помощью is и as  
            if (rose is Rose)
            {
                Console.WriteLine("Это роза");
            }

            Gladiolus tempGladiolus = gladiolus as Gladiolus;

            if (tempGladiolus != null)
            {
                Console.WriteLine("Это гладиолус");
            }

            // Создание объекта Printer и вызов метода IAmPrinting для каждого растения
            Printer printer = new Printer();

            Plant[] plantArray = { rose, gladiolus, cactus, bush };

            Console.WriteLine("\nВывод информации о растениях:");

            foreach (var plant in plantArray)
            {
                printer.IAmPrinting(plant);
            }

            // Работа с объектами через ссылки на интерфейсы и абстрактные классы
            List<ICloneable> plants = new List<ICloneable> { rose, gladiolus, cactus, bush };
            Console.WriteLine("\nКлонирование растений:");

            foreach (var plant in plants)
            {
                Console.WriteLine($"{plant}");
            }

            Console.WriteLine("\nИнформация о букете:");
            Console.WriteLine(bouquet);
        }
    }
}
