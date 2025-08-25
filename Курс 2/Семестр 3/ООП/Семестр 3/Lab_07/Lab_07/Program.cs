using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab_07
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                CollectionType<int> collection = new CollectionType<int>(new HashSet<int> { 1, 2, 3, 4 });

                Flower rose = new Flower { Color = "Красный", Name = "Роза" };
                Flower gladiolus = new Flower { Color = "Белый", Name = "Гладиолус" };
                Flower lily = new Flower { Color = "Фиолетовый", Name = "Лилия" };

                CollectionType<Flower> list = new CollectionType<Flower>(new HashSet<Flower> { rose, gladiolus, lily });

                Console.WriteLine(collection);

                collection.Add(5);
                collection.Add(6);
                collection.Add(7);
                collection.Remove(4);

                bool element = collection.View(2);

                if (element == false)
                {
                    throw new Exception();
                }

                Console.WriteLine(collection);
                Console.WriteLine("\nМаксимальный элемент: " + StaticOperation.Compare(collection));
                Console.WriteLine(list);

                collection.Write(collection.ToString());
                collection.Read("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_07\\Lab_07\\File.txt");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Console.WriteLine("\nКонец программы");
            }
        }
    }
}
