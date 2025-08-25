using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_05
{
    public enum PackType
    {
        Paper,
        Plastic,
        Rope
    }


    public struct Price
    {
        public decimal Amount { get; set; }

        public Price(decimal amount)
        {
            Amount = amount;
        }

        public override string ToString()
        {
            return $"{Amount}";
        }
    }


    abstract class Plant : ICloneable
    {
        public string Name { get; set; }

        public abstract bool DoClone();

        public virtual string Describe()
        {
            return $"Это растение по имени {Name}.";
        }

        public override string ToString()
        {
            return $"Растение: {Name}";
        }

        public override bool Equals(object obj)
        {
            if (obj is Flower otherFlower)
                return Name == otherFlower.Name;

            return false;
        }

        public override int GetHashCode()
        {
            return Name.GetHashCode();
        }
    }


    partial class Flower : Plant, ICloneable
    {
        public string Color { get; set; }
        public Price Price { get; set; }

        bool ICloneable.DoClone()
        {
            Console.WriteLine("Клонирование через интерфейс ICloneable.");
            return true;
        }
    }


    class Rose : Flower
    {
        public int ThornCount { get; set; }

        public override string ToString()
        {
            return $"{Name}, Цвет: {Color}, Количество шипов: {ThornCount}, Цена: {Price} $";
        }
    }


    class Gladiolus : Flower
    {
        public int PetalCount { get; set; }

        public override string ToString()
        {
            return $"{Name}, Цвет: {Color}, Количество лепестков: {PetalCount}, Цена: {Price} $";
        }
    }


    class Lily : Flower
    {
        public int PetalCount { get; set; }

        public override string ToString()
        {
            return $"{Name}, Цвет: {Color}, Количество лепестков: {PetalCount}, Цена: {Price} $";
        }
    }


    class Bouquet
    {
        public List<Flower> Flowers { get; set; }

        public PackType Pack { get; set; }

        public void AddFlower(Flower flower)
        {
            Flowers.Add(flower);
        }

        public void RemoveFlower(Flower flower)
        {
            Flowers.Remove(flower);
            Console.WriteLine($"\nУдаление цветка {flower.Name}\n");
        }

        public void DisplayBouquet()
        {
            Console.WriteLine("Букет состоит из следующих цветов:");

            foreach (var flower in Flowers)
            {
                Console.WriteLine(flower);
            }

            Console.WriteLine($"Тип упаковки: {Pack}");
        }

        public decimal CalculateTotalPrice()
        {
            decimal total = 0;

            foreach (var flower in Flowers)
            {
                total += flower.Price.Amount;
            }

            return total;
        }

        public void SortFlowers()
        {
            Console.WriteLine("Сортировка по цвету\n");
            Flowers.Sort((f1, f2) => f1.Color.CompareTo(f2.Color));
        }

        public Flower FindFlowerByColor(string color)
        {
            return Flowers.FirstOrDefault(f => f.Color == color);
        }
    }


    class BouquetController
    {
        private Bouquet bouquet;

        public BouquetController(Bouquet bouquet)
        {
            this.bouquet = bouquet;
        }

        public void AddFlowerToBouquet(Flower flower)
        {
            bouquet.AddFlower(flower);
        }

        public void RemoveFlowerFromBouquet(Flower flower)
        {
            bouquet.RemoveFlower(flower);
        }

        public void DisplayBouquetInfo()
        {
            bouquet.DisplayBouquet();
        }

        public decimal GetBouquetPrice()
        {
            return bouquet.CalculateTotalPrice();
        }

        public void SortFlowersInBouquet()
        {
            bouquet.SortFlowers();
        }

        public Flower SearchFlowerByColor(string color)
        {
            return bouquet.FindFlowerByColor(color);
        }
    }


    class Printer
    {
        public void IAmPrinting(Plant obj)
        {
            Console.WriteLine(obj.ToString());
        }
    }
}
