using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_11
{
    internal class Program
    {
        static void Main(string[] args)
        {
            File.WriteAllText(@"C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_11\\Lab_11\\File.txt", string.Empty);

            Buyer buyer = new Buyer("A", "1", 1);
            Bank bank = new Bank("1", "T");

            string className1 = "Lab_11.Bank";
            string className2 = "Lab_11.Buyer";
            string parameter = "System.Int32";

            Reflector.GetAssemblyName(className1);
            Reflector.GetAssemblyName(className2);

            Reflector.GetConstructors(className1);
            Reflector.GetConstructors(className2);

            Reflector.GetMethods(className1);
            Reflector.GetMethods(className2);

            Reflector.GetPropertiesAndFields(className1);
            Reflector.GetPropertiesAndFields(className2);

            Reflector.GetInterfaces(className1);
            Reflector.GetInterfaces(className2);

            Reflector.GetMethodsWithParameter(className1, parameter);
            Reflector.GetMethodsWithParameter(className2, parameter);

            object result = Reflector.Invoke("Lab_11.Buyer", "GetMessage", new object[] { "Artsiom" });
            Console.WriteLine($"{result}");

            var person = Reflector.Create<Bank>("12345678", "Тёмыч");
            Console.WriteLine(person);
        }
    }
}
