using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace Lab_01
{
    internal class Program
    {
        static void Main(string[] args)
        {


            // Определение переменных всех возможных примитивных типов 
            bool var1 = false;
            Console.WriteLine(var1);

            int var2 = 1;
            Console.WriteLine(var2);

            byte var3 = 111;
            Console.WriteLine(var3);

            sbyte var4 = -22;
            Console.WriteLine(var4);

            char var5 = 'a';
            Console.WriteLine(var5);

            decimal var6 = 222;
            Console.WriteLine(var6);

            double var7 = 44;
            Console.WriteLine(var7);

            float var8 = 0.4f;
            Console.WriteLine(var8);

            uint var9 = 123;
            Console.WriteLine(var9);

            long var10 = 9223372036854775807;
            Console.WriteLine(var10);

            ulong var11 = 1L;
            Console.WriteLine(var11);

            ushort var12 = 65535;
            Console.WriteLine(var12);

            short var13 = 32767;
            Console.WriteLine(var13);

            object var14 = 1;
            Console.WriteLine(var14);
            
            string var15 = "Hello";
            Console.WriteLine(var15);

            dynamic var16 = "Dynamic";
            Console.WriteLine(var16);

            // Ввод и вывод в консоль
            //Console.WriteLine("Ввод значений переменных: ");
            //Console.Write("bool: ");
            //var1 = bool.Parse(Console.ReadLine());
            //Console.Write("int: ");
            //var2 = int.Parse(Console.ReadLine());
            //Console.Write("byte: ");
            //var3 = byte.Parse(Console.ReadLine());
            //Console.Write("sbyte: ");
            //var4 = sbyte.Parse(Console.ReadLine());
            //Console.Write("char: ");
            //var5 = char.Parse(Console.ReadLine());
            //Console.Write("decimal: ");
            //var6 = decimal.Parse(Console.ReadLine());
            //Console.Write("double: ");
            //var7 = double.Parse(Console.ReadLine());
            //Console.Write("float: ");
            //var8 = float.Parse(Console.ReadLine());
            //Console.Write("uint: ");
            //var9 = uint.Parse(Console.ReadLine());
            //Console.Write("long: ");
            //var10 = long.Parse(Console.ReadLine());
            //Console.Write("ulong: ");
            //var11 = ulong.Parse(Console.ReadLine());
            //Console.Write("ushort: ");
            //var12 = ushort.Parse(Console.ReadLine());
            //Console.Write("short: ");
            //var13 = short.Parse(Console.ReadLine());
            //Console.Write("object: ");
            //var14 = Console.ReadLine();
            //Console.Write("string: ");
            //var15 = Console.ReadLine();
            //Console.Write("dynamic: ");
            //var16 = Console.ReadLine();
            
            //Console.WriteLine($"bool:   {var1}\n" +
            //                 $"int:     {var2}\n" +
            //                 $"byte:    {var3}\n" +
            //                 $"sbyte:   {var4}\n" +
            //                 $"char:    {var5}\n" +
            //                 $"decimal: {var6}\n" +
            //                 $"double:  {var7}\n" +
            //                 $"float:   {var8}\n" +
            //                 $"uint:    {var9}\n" +
            //                 $"long:    {var10}\n" +
            //                 $"ulong:   {var11}\n" +
            //                 $"ushort:  {var12}\n" +
            //                 $"short:   {var13}\n" +
            //                 $"object:  {var14}\n" +
            //                 $"string:  {var15}\n" +
            //                 $"dynamic: {var16}\n"
            //                 );

            // Неявное приведение
            byte type1 = 4;
            ushort type2 = type1;   

            sbyte type3 = 4;            
            short type4 = type3;

            sbyte type5 = -4;           
            short type6 = type5;

            long type7 = 6;
            double type8 = type7;

            short type9 = 1;
            int type10 = type9;

            // Явное приведение
            int obvious1 = 4;
            int obvious2 = 6;
            byte obvious3 = (byte)(obvious1 + obvious2);

            double obvious4 = 4.0;
            decimal obvious5 = (decimal)obvious4;

            short obvious6 = 2;
            byte obvious7 = (byte)obvious6;

            long obvious8 = 9;
            int obvious9 = (int)obvious8;

            int obvious10 = 111;
            short odvious11 = (short)obvious10;

            // Класс Convert
            int num1 = Convert.ToInt32("23");
            bool num2 = true;
            double num3 = Convert.ToDouble(num2);
            Console.WriteLine($"n={num1}  d={num2}");

            // Упаковка и распаковка значимых типов
            int number = 5;
            object box = number;
            int unbox = (int)box;

            // Работа с неявно типизированной переменной
            var symbol1 = 5;
            var symbol2 = "Hello";
            var symbol3 = new[] { 0, 1, 2 };
            Console.WriteLine(symbol2);

            // Работа с Nullable переменной 
            int? val = null;
            Console.WriteLine(val);

            int? val1 = 5;
            Nullable<int> val2 = 5;

            // Определение переменной  типа  var и присвоение ей другого типа
            var value1 = 5.0;
            value1 = 5;

            // Объявление и сравнение строковых литералов
            string s1 = "hello";
            string s2 = "world";

            int result = string.Compare(s1, s2);

            if (result < 0)
            {
                Console.WriteLine("Строка s1 перед строкой s2");
            }
            else if (result > 0)
            {
                Console.WriteLine("Строка s1 стоит после строки s2");
            }
            else
            {
                Console.WriteLine("Строки s1 и s2 идентичны");
            }

            // Объявление трех строк
            string literal1 = "один ";
            string literal2 = "два ";
            string literal3 = "три ";

            // Сцепление
            string literal4 = literal1 + literal2 + literal3;
            string literal5 = string.Concat(literal4, "!!!");
            Console.WriteLine(literal5);

            // Копирование
            string literal7 = string.Copy(literal1);
            Console.WriteLine(literal7);

            // Выделение подстроки
            string literal8 = literal1.Substring(2);
            Console.WriteLine(literal8);

            // Разделение строки на слова
            string phrase = "one two three four five";
            string[] words = phrase.Split(' ');

            foreach (string word in words)
            {
                Console.WriteLine($"<{word}>");
            }

            // Вставка подстроки в заданную позицию
            string insert = literal3.Insert(4, "четыре");
            Console.WriteLine(insert);

            // Удаление заданной подстроки
            phrase = phrase.Remove(0, 4);
            Console.WriteLine(phrase);

            // Интерполирование строк
            int age = 19;
            Console.WriteLine($"Мне {age} лет");

            // Пустая и null строки
            string test1 = "abcd";
            string test2 = "";
            string test3 = null;

            Console.WriteLine("Строка test1 {0}.", Test(test1));
            Console.WriteLine("Строка test2 {0}.", Test(test2));
            Console.WriteLine("Строка test3 {0}.", Test(test3));

            // Использование метода string.IsNullOrEmpty
            String Test(string test)
            {
                if (String.IsNullOrEmpty(test))
                    return "null или пустая";
                else
                    return String.Format("(\"{0}\") не пустая", test);
            }

            if (String.IsNullOrWhiteSpace(test2))
                Console.WriteLine("Строка test2 пустая или null-строка или строка из пробелов");
            else
                Console.WriteLine("Строка test2 не пустая");

            // Строка на основе StringBuilder
            var str = new StringBuilder("один два три");
            str.Insert(0, "(");
            str.Append(")");
            Console.WriteLine(str);

            str.Remove(5, 8);
            Console.WriteLine(str);

            // Целый двумерный массив
            int[,] numbers = { { 1, 2, 3 }, { 4, 5, 6 } };

            int rows = numbers.GetUpperBound(0) + 1;    // Количество строк
            int columns = numbers.Length / rows;        // Количество столбцов

            for (int q = 0; q < rows; q++)
            {
                for (int j = 0; j < columns; j++)
                {
                    Console.Write($"{numbers[q, j]} \t");
                }
                Console.WriteLine();
            }

            // Одномерный массив строк
            string[] people = { "Tom", "Sam", "Bob", "Kate", "Alice" };

            foreach (var person in people)
                Console.Write($"{person} ");

            Console.WriteLine();
            int lenght = people.Length;
            Console.WriteLine(lenght);

            Console.WriteLine("Напишите заменяющий элемент и его позицию:");
            string userElement = Console.ReadLine();
            int userPosition = Convert.ToInt32(Console.ReadLine());

            people.SetValue($"{userElement}", userPosition);
            foreach (var person in people)
                Console.Write($"{person} ");

            // Ступенчатый массив
            float[][] array1 = new float[3][];
            array1[0] = new float[2];
            array1[1] = new float[3];
            array1[2] = new float[4];

            Console.WriteLine("\nВведите элементы массива: ");
            for (var i = 0; i < array1.Length; i++)
            {
                for (var j = 0; j < array1[i].Length; j++)
                    array1[i][j] = float.Parse(Console.ReadLine());
                Console.WriteLine();
            }

            Console.WriteLine("Массив: ");
            for (int i = 0; i < array1.Length; i++)
            {
                for (int j = 0; j < array1[i].Length; j++)
                {
                    Console.Write($"{array1[i][j]} \t");
                }
                Console.WriteLine();
            }

            // Неявно типизированные переменные
            var typedArr = new[] { 1.1, 2.2, 3.3 };
            var typedStr = "Boom";

            // Кортеж из 5 элементов
            (int, string, char, string, ulong) tuple1 = (-4, "Hello", 'a', "World", 199388384848);
            (int, string, char, string, ulong) tuple2 = (235, "Goodbye", 'l', "World", 23423200201);

            // Вывод кортежа целиком и выборочно
            Console.WriteLine("Кортеж: ");
            Console.WriteLine(tuple1);
            Console.WriteLine("Элементы кортежа (1, 3, 4): ");
            Console.WriteLine(tuple1.Item1);
            Console.WriteLine(tuple1.Item3);
            Console.WriteLine(tuple1.Item4);

            // Распоковка кортежа в переменные
            var firstItem = tuple1.Item1;
            var secondItem = tuple1.Item2;
            var thirdItem = tuple1.Item3;
            var fourthItem = tuple1.Item4;
            var fifthItem = tuple1.Item5;

            var (item1, item2, tem3, item4, item5) = tuple2;

            (int, float) newTuple = (-43, 7.8f);
            (int intVar, float floatVar) = newTuple;

            var (_, str1, _, str2, _) = (-4, "Hello", 'a', "World", 199388384848);

            // Сравнение кортежей
            if (tuple1 == tuple2)
                Console.WriteLine("Кортежи равны");
            else
                Console.WriteLine("Кортежи не равны");

            // Локальная функция
            int[] arr = { 1, 2, 3, 4, 5, 6 };
            string str3 = "WWW";

            (int maxLoc, int minLoc, int sumLoc, char letter) = myFunc(arr, str3);

            Console.WriteLine($"\nМаксимальный элемент массива: {maxLoc}\n" +
                              $"Минимальный элемент массива: {minLoc}\n" +
                              $"Сумма всех элементов массива: {sumLoc}\n" +
                              $"Первая буква строки: {letter}\n");


            (int, int, int, char) myFunc(int[] arrLoc, string strLoc)
            {
                int max = arrLoc.Max();
                int min = arrLoc.Min();
                int sum = arrLoc.Sum();
                char s = strLoc[0];

                return (max, min, sum, s);
            }

            // checked/unchecked
            try
            {
                firstChecked();
            }
            catch (OverflowException e)
            {
                Console.WriteLine(e.Message);
            }
            secondUnchecked();

            void firstChecked()
            {
                checked
                {
                    int maxVal1 = int.MaxValue;
                    maxVal1++;
                    Console.WriteLine(maxVal1);
                }

            }

            void secondUnchecked()
            {
                unchecked
                {
                    int maxVal2 = int.MaxValue;
                    maxVal2++;
                    Console.WriteLine(maxVal2);
                }
            }
        }
    }
}
