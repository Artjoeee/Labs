using Microsoft.SqlServer.Server;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.Xml;

namespace Lab_13
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var rose = new Flower { Name = "Роза", Color = "Красный", ThornCount = 10 };
            var filePath = "flower_data";

            // Выбор сериализатора
            ISerializer serializer = new BinarySerializer();
            serializer.Serialize(rose, filePath + ".bin");
            var deserializedRose = serializer.Deserialize<Flower>(filePath + ".bin");
            Console.WriteLine($"Binary: {deserializedRose}");

            serializer = new JsonSerializer();
            serializer.Serialize(rose, filePath + ".json");
            deserializedRose = serializer.Deserialize<Flower>(filePath + ".json");
            Console.WriteLine($"JSON: {deserializedRose}");

            serializer = new XmlSerializerAdapter();
            serializer.Serialize(rose, filePath + ".xml");
            deserializedRose = serializer.Deserialize<Flower>(filePath + ".xml");
            Console.WriteLine($"XML: {deserializedRose}");

            serializer = new SoapSerializer();
            serializer.Serialize(rose, filePath + ".soap");
            deserializedRose = serializer.Deserialize<Flower>(filePath + ".soap");
            Console.WriteLine($"SOAP: {deserializedRose}");

            // Коллекция объектов
            var flowers = new List<Flower>
            {
                new Flower { Name = "Роза", Color = "Красный", ThornCount = 10 },
            new Flower { Name = "Лилия", Color = "Белый", ThornCount = 0 },
            };

            // Для SOAP сериализуем через обёртку
            var flowerArrayWrapper = new FlowerArrayWrapper { Flowers = flowers.ToArray() };

            serializer = new XmlSerializerAdapter();
            serializer.Serialize(flowers, filePath + "_list.xml");
            var deserializedFlowers = serializer.Deserialize<List<Flower>>(filePath + "_list.xml");

            Console.WriteLine("Список цветов:");
            foreach (var flower in deserializedFlowers)
            {
                Console.WriteLine(flower);
            }

            serializer = new SoapSerializer();
            serializer.Serialize(flowerArrayWrapper, filePath + "_list.soap");
            var deserializedFlowerArray = serializer.Deserialize<FlowerArrayWrapper>(filePath + "_list.soap");

            Console.WriteLine("Список цветов (SOAP):");
            foreach (var flower in deserializedFlowerArray.Flowers)
            {
                Console.WriteLine(flower);
            }

            // 3. XPath селекторы для XML документа
            Console.WriteLine("\nXPath запросы для XML:");
            var xmlDoc = new XmlDocument();
            xmlDoc.Load(filePath + "_list.xml"); // Убедитесь, что файл существует и корректен

            try
            {
                // Селектор для поиска всех цветков с определенным цветом
                var xpathExpression1 = "/ArrayOfFlower/Flower[Color='Красный']";
                var selectedFlowers1 = xmlDoc.SelectNodes(xpathExpression1);

                if (selectedFlowers1 != null && selectedFlowers1.Count > 0)
                {
                    foreach (XmlNode flowerNode in selectedFlowers1)
                    {
                        Console.WriteLine($"XPath - Цветок с красным цветом: {flowerNode.OuterXml}");
                    }
                }
                else
                {
                    Console.WriteLine("XPath запрос 1: Цветы с красным цветом не найдены.");
                }

                // Селектор для поиска всех цветков с количеством шипов больше 5
                var xpathExpression2 = "/ArrayOfFlower/Flower[ThornCount>5]";
                var selectedFlowers2 = xmlDoc.SelectNodes(xpathExpression2);

                if (selectedFlowers2 != null && selectedFlowers2.Count > 0)
                {
                    foreach (XmlNode flowerNode in selectedFlowers2)
                    {
                        Console.WriteLine($"XPath - Цветок с более чем 5 шипами: {flowerNode.OuterXml}");
                    }
                }
                else
                {
                    Console.WriteLine("XPath запрос 2: Цветы с более чем 5 шипами не найдены.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при работе с XPath: {ex.Message}");
            }


            // 4. LINQ to XML для создания нового XML документа
            Console.WriteLine("\nLINQ to XML создание и запросы:");

            // Создание нового XML документа с использованием LINQ
            var flowersXml = new XElement("Flowers",
                from flower in flowers
                select new XElement("Flower",
                    new XElement("Name", flower.Name),
                    new XElement("Color", flower.Color),
                    new XElement("ThornCount", flower.ThornCount)
                )
            );

            // Запись в файл
            flowersXml.Save("flowers_linq.xml");

            // Запрос: Получить все цветы с количеством шипов больше 5
            var flowersWithThorns = flowersXml.Descendants("Flower")
                .Where(f => (int)f.Element("ThornCount") > 5);

            foreach (var flower in flowersWithThorns)
            {
                Console.WriteLine($"LINQ - Цветок с более чем 5 шипами: {flower}");
            }

            // Запрос: Получить все цветы красного цвета
            var redFlowers = flowersXml.Descendants("Flower")
                .Where(f => (string)f.Element("Color") == "Красный");

            foreach (var flower in redFlowers)
            {
                Console.WriteLine($"LINQ - Красный цветок: {flower}");
            }
        }
    }
}
