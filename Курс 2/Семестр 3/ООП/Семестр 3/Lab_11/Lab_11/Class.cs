using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Lab_11
{
    public static class Reflector
    {
        public static void GetAssemblyName(string className)
        {
            Type t = Type.GetType(className);
            string s = t.Assembly.FullName.ToString();

            StreamWriter sw = new StreamWriter("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_11\\Lab_11\\File.txt", true);

            sw.WriteLine(s);
            sw.Close();
        }

        public static void GetConstructors(string className)
        {
            Type t = Type.GetType(className);
            ConstructorInfo[] s = t.GetConstructors(BindingFlags.Instance | BindingFlags.Public);

            StreamWriter sw = new StreamWriter("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_11\\Lab_11\\File.txt", true);
            
            foreach (var item in s)
            {
                sw.WriteLine(item.IsPublic);
                break;
            }

            sw.Close();
        }

        public static void GetMethods(string className)
        {
            Type t = Type.GetType(className);
            MethodInfo[] s = t.GetMethods(BindingFlags.Instance | BindingFlags.Public);

            StreamWriter sw = new StreamWriter("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_11\\Lab_11\\File.txt", true);

            foreach (var item in s)
            {
                sw.WriteLine(item);
            }

            sw.Close();
        }

        public static void GetPropertiesAndFields(string className) 
        {
            Type t = Type.GetType(className);

            FieldInfo[] s = t.GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            PropertyInfo[] p = t.GetProperties(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);

            StreamWriter sw = new StreamWriter("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_11\\Lab_11\\File.txt", true);

            foreach (var item in s)
            {
                sw.WriteLine(item);
            }

            foreach (var item in p)
            {
                sw.WriteLine(item);
            }

            sw.Close();
        }

        public static void GetInterfaces(string className) 
        {
            Type t = Type.GetType(className);
            Type[] s = t.GetInterfaces();

            StreamWriter sw = new StreamWriter("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_11\\Lab_11\\File.txt", true);

            foreach (var item in s)
            {
                sw.WriteLine(item);
            }

            sw .Close();
        }

        public static void GetMethodsWithParameter(string className, string parameter) 
        {
            Type t = Type.GetType(className);
            Type paramType = Type.GetType(parameter);
            MethodInfo[] s = t.GetMethods(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);

            StreamWriter sw = new StreamWriter("C:\\Users\\HomeUser\\Desktop\\ООП\\Lab_11\\Lab_11\\File.txt", true);

            foreach (var item in s)
            {
                ParameterInfo[] p = item.GetParameters();

                foreach (var param in p)
                {
                    if (param.ParameterType == paramType)
                    {
                        sw.WriteLine(item);
                    }
                }
            }

            sw.Close ();
        }

        public static object Invoke(string className, string methodName, object[] parameters)
        {
            Type type = Type.GetType(className);
            MethodInfo method = type.GetMethod(methodName);

            object instance = Activator.CreateInstance(type);
            return method.Invoke(instance, parameters);
        }

        public static T Create<T>(params object[] parameters)
        {
            Type type = typeof(T);

            ConstructorInfo constructor = type.GetConstructor(
                parameters.Select(p => p.GetType()).ToArray()
            );

            return (T)constructor.Invoke(parameters);
        }
    }


    public class Bank : ITest
    {
        public string CreditNumber { get; set; }
        public string Name { get; set; }

        public Bank(string credit, string name)
        {
            CreditNumber = credit;
            Name = name;
        }

        public Bank() { }

        public override string ToString()
        {
            return $"{CreditNumber} ({Name})"; 
        }
    }

    public class Buyer
    {
        public string Name { get; set; }

        public string CreditNumber { get; set; }

        public int Balance { get; set; }

        public Buyer(string name, string credit, int balance)
        {
            Name = name;
            CreditNumber = credit;
            Balance = balance;
        }

        public Buyer() { }

        public override string ToString()
        {
            return $"Покупатель: {Name}, Карта: {CreditNumber}, Баланс: {Balance}";
        }

        public string GetMessage(string message)
        {
            return $"Hi, {message}";
        }
    }
}
