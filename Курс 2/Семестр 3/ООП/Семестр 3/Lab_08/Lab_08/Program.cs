using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Lab_08
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Director turner1 = new Director(150);
            Director turner2 = new Director(200);
            Director turner3 = new Director(150);

            turner1.MoneyChanged += DisplayMessage;
            turner2.MoneyChanged += DisplayMessage;

            Console.WriteLine($"turner1: {turner1.Cash}");
            Console.WriteLine($"turner2: {turner2.Cash}");
            Console.WriteLine($"turner3: {turner3.Cash}");

            turner1.Reise(50);
            turner1.Punishment(30);

            Console.WriteLine($"turner1: {turner1.Cash}");

            turner2.Reise(50);

            Console.WriteLine($"turner2: {turner2.Cash}");
            Console.WriteLine($"\nturner3: {turner3.Cash}");

            void DisplayMessage(string message) => Console.WriteLine(message);
            void DoOperation(string message, Action<string> op) => op(message);

            string text = "\nКазнить нельзя, Помиловать!";
            string spaceText = "H   E   L   L   O";

            Action<string> punctuation = (string message) =>
            {
                string newText = Regex.Replace(message, "[-.?!)(,:;]", "");
                Console.WriteLine(newText);
            };


            Action<string> addSymbol = (string message) =>
            {
                string symbol = "!!";
                Console.WriteLine(text + symbol);
            };


            Action<string> upper = (string message) =>
            {
                string upperText = message.ToUpper();
                Console.WriteLine(upperText);
            };


            Action<string> lower = (string message) =>
            {
                string upperText = message.ToLower();
                Console.WriteLine(upperText);
            };


            Action<string> spaceDelete = (string message) => 
            {
                Console.WriteLine(Regex.Replace(message, @"\s+", " "));
            };


            DoOperation(text, punctuation);
            DoOperation(text, addSymbol);
            DoOperation(text, upper);
            DoOperation(text, lower);
            DoOperation(spaceText, spaceDelete);
        }
    }
}
