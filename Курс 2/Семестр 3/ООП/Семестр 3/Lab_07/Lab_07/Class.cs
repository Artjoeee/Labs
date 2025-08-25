using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Lab_07
{
    public class CollectionType<T> : IGeneralization<T>
    {
        public HashSet<T> _elements;

        public Flower Rose { get; }
        public Flower Gladiolus { get; }
        public Flower Lily { get; }

        public CollectionType(IEnumerable<T> elements)
        {
            _elements = new HashSet<T>(elements);
        }

        public CollectionType(Flower rose, Flower gladiolus, Flower lily)
        {
            Rose = rose;
            Gladiolus = gladiolus;
            Lily = lily;
        }

        public override string ToString()
        {
            return string.Join(", ", _elements);
        }

        public void Add(T item)
        {
            _elements.Add(item);
        }

        public void Remove(T item)
        {
            _elements.Remove(item);
        }

        public bool View(T item)
        {
            foreach (var x in _elements)
            {
                if (x.Equals(item))
                {
                    return true;
                } 
            }

            return false; 
        }

        public HashSet<T> GetElements() 
        {
            return _elements;
        }

        public void Write(string collection)
        {
            StreamWriter sw = new StreamWriter("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_07\\Lab_07\\File.txt");

            sw.WriteLine(collection);
            sw.Close();
        }

        public void Read(string file)
        {
            string line;

            StreamReader sr = new StreamReader(file);
            line = sr.ReadLine();

            Console.WriteLine("\nЧтение из файла");

            while (line != null)
            {
                Console.WriteLine(line);
                line = sr.ReadLine();
            }

            sr.Close();
        }
    }


    public static class StaticOperation
    {
        public static T Compare<T>(CollectionType<T> collection) where T : struct, IComparable<T>
        {
            T max = default;

            foreach (var x in collection.GetElements()) 
            {
                x.CompareTo(max);
                max = x;
            }

            return max;
        }
    }


    public class Flower
    {
        public string Color { get; set; }
        public string Name { get; set; }

        public override string ToString()
        {
            return $"\nЦветок: {Name}, Цвет: {Color}";
        }
    }
}
