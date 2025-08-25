using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Json;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Lab_13
{
    // Сериализация в бинарный формат
    class BinarySerializer : ISerializer
    {
        public void Serialize<T>(T obj, string filePath)
        {
            IFormatter formatter = new BinaryFormatter();
            using (var stream = new FileStream(filePath, FileMode.Create))
            {
                formatter.Serialize(stream, obj);
            }
        }

        public T Deserialize<T>(string filePath)
        {
            IFormatter formatter = new BinaryFormatter();
            using (var stream = new FileStream(filePath, FileMode.Open))
            {
                return (T)formatter.Deserialize(stream);
            }
        }
    }

    // Сериализация в JSON
    class JsonSerializer : ISerializer
    {
        public void Serialize<T>(T obj, string filePath)
        {
            var serializer = new DataContractJsonSerializer(typeof(T));
            using (var stream = new FileStream(filePath, FileMode.Create))
            {
                serializer.WriteObject(stream, obj);
            }
        }

        public T Deserialize<T>(string filePath)
        {
            var serializer = new DataContractJsonSerializer(typeof(T));
            using (var stream = new FileStream(filePath, FileMode.Open))
            {
                return (T)serializer.ReadObject(stream);
            }
        }
    }

    // Сериализация в XML
    class XmlSerializerAdapter : ISerializer
    {
        public void Serialize<T>(T obj, string filePath)
        {
            var serializer = new XmlSerializer(typeof(T));
            using (var writer = new StreamWriter(filePath))
            {
                serializer.Serialize(writer, obj);
            }
        }

        public T Deserialize<T>(string filePath)
        {
            var serializer = new XmlSerializer(typeof(T));
            using (var reader = new StreamReader(filePath))
            {
                return (T)serializer.Deserialize(reader);
            }
        }
    }

    // Сериализация в SOAP
    class SoapSerializer : ISerializer
    {
        public void Serialize<T>(T obj, string filePath)
        {
            var serializer = new System.Runtime.Serialization.Formatters.Soap.SoapFormatter();
            using (var stream = new FileStream(filePath, FileMode.Create))
            {
                serializer.Serialize(stream, obj);
            }
        }

        public T Deserialize<T>(string filePath)
        {
            var serializer = new System.Runtime.Serialization.Formatters.Soap.SoapFormatter();
            using (var stream = new FileStream(filePath, FileMode.Open))
            {
                return (T)serializer.Deserialize(stream);
            }
        }
    }

    [Serializable]
    public class Flower
    {
        public string Name { get; set; }
        public string Color { get; set; }

        [NonSerialized]
        public int ThornCount;

        public override string ToString() => $"Цветок: {Name}, Цвет: {Color}, Шипы: {ThornCount}";
    }

    [Serializable]
    public class FlowerArrayWrapper
    {
        public Flower[] Flowers { get; set; }
    }
}
