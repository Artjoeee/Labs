using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Lab_05
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Flower rose = new Rose { Name = "Роза", Color = "Красный", ThornCount = 10, Price = new Price(100) };
            Flower gladiolus = new Gladiolus { Name = "Гладиолус", Color = "Белый", PetalCount = 15, Price = new Price(150) };
            Flower lily = new Lily { Name = "Лилия", Color = "Фиолетовый", PetalCount = 5, Price = new Price(50) };

            Bouquet bouquet = new Bouquet 
            { 
                Pack = PackType.Plastic,
                Flowers = new List<Flower>()
            };

            BouquetController controller = new BouquetController(bouquet);

            controller.AddFlowerToBouquet(rose);
            controller.AddFlowerToBouquet(gladiolus);
            controller.AddFlowerToBouquet(lily);

            controller.DisplayBouquetInfo();

            Console.WriteLine($"\nСтоимость букета: {controller.GetBouquetPrice()} $\n");

            controller.SortFlowersInBouquet();
            controller.DisplayBouquetInfo();

            controller.RemoveFlowerFromBouquet(rose);
            controller.DisplayBouquetInfo();

            var foundFlower = controller.SearchFlowerByColor("Фиолетовый");
            Console.WriteLine($"\nНайденный цветок: {foundFlower}\n");
        }
    }
}
