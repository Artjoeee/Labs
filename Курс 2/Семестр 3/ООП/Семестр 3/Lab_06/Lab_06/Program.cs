using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Lab_06
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Flower rose = new Rose { Name = "Роза", Color = "Красный", ThornCount = 10, Price = new Price(100) };
                Flower gladiolus = new Gladiolus { Name = "Гладиолус", Color = "Белый", PetalCount = 15, Price = new Price(150) };
                Flower lily = new Lily { Name = "Лилия", Color = "Фиолетовый", PetalCount = 5, Price = new Price(50) };

                if (rose.Price.Amount < 0 || rose.Price.Amount > 1000)
                {
                    throw new PriceOutOfRangeException();
                }

                Bouquet bouquet = new Bouquet
                {
                    Pack = PackType.Plastic,
                    Flowers = new List<Flower>()
                };

                BouquetController controller = new BouquetController(bouquet);

                //controller.AddFlowerToBouquet(rose);
                //controller.AddFlowerToBouquet(gladiolus);
                //controller.AddFlowerToBouquet(lily);

                //int[] numbers = new int[4];
                //numbers[7] = 9;

                try
                {
                    var flowerCount = controller.FlowerCounterInBouquet();
                    var bouquetPrice = controller.GetBouquetPrice();
                    var averagePrice = bouquetPrice / flowerCount;
                }
                catch (DivideByZeroException)
                {
                    throw;
                }

                var foundFlower = controller.SearchFlowerByColor("Красный");

                if (foundFlower == null)
                {
                    throw new FlowerNotFoundException();
                }
                else
                {
                    Console.WriteLine($"Найденный цветок: {foundFlower}\n");
                }

                if (lily.Color == "")
                {
                    throw new InvalidFlowerDataException(lily.Color);
                }
            }
            catch (PriceOutOfRangeException ex)
            {
                Console.WriteLine($"Ошибка в цене: {ex.Message}");
            }
            catch (FlowerNotFoundException ex)
            {
                Console.WriteLine($"Ошибка в цвете: {ex.Message}");
            }
            catch (InvalidFlowerDataException ex)
            {
                Console.WriteLine($"Ошибка в параметрах: {ex.Message}");
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine($"Ошибка в индексе: {ex.Message}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Общая ошибка: {ex.Message}");
            }
            finally
            {
                Console.WriteLine("Завершение программы");
            }
        }
    }
}