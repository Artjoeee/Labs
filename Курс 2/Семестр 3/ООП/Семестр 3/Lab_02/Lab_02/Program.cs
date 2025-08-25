using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Lab_02
{

    internal class Program
    {
        static void Main()
        {
            // Создание нескольких объектов
            var customer1 = new Customer("Иванов", "Иван", "Иванович", "Бобруйская 25", "1234567812345678", 5000);
            var customer2 = new Customer("Петров", "Петр", "Петрович", "Бобруйская 24", "2345678923456789", 3000);
            var customer3 = new Customer("Сидоров", "Сидор", "Сидорович", "Бобруйская 23", "3456789034567890", 7000);

            // Вызов методов класса
            customer1.Deposit(2000);

            // Сравнение объектов
            Console.WriteLine(customer1.Equals(customer2)); // False
            Console.WriteLine(customer1.Equals(new Customer("Иванов", "Иван", "Иванович", "123 Main St", "1234567812345678", 5000))); // True
             
            // Вывод информации о классе
            Customer.DisplayClassInfo();

            // Создание массива объектов и выполнение задания
            List<Customer> customers = new List<Customer> { customer1, customer2, customer3 };

            // a) Список покупателей в алфавитном порядке
            Console.WriteLine("Покупатели в алфавитном порядке:");
            Customer.DisplaySortedCustomers(customers);

            // Пример работы с ref и out
            decimal balance = customer2.Balance;

            Console.WriteLine($"Баланс до операции: {balance} $");
            if (customer2.TryWithdraw(ref balance, 2000, out string operationResult))
            {
                Console.WriteLine($"Баланс после списания: {balance} $");
            }
            else
            {
                Console.WriteLine($"Операция не удалась: {operationResult}");
            }

            // b) Список покупателей, у которых номер кредитной карточки в заданном интервале
            Console.WriteLine("\nПокупатели с номерами карт в диапазоне 2000000000000000 - 3000000000000000:");
            Customer.DisplayCustomersInCardRange(customers, "2000000000000000", "3000000000000000");

            // Анонимный тип
            var anonymousCustomer = new { id = Guid.NewGuid(), LastName = "Федоров", FirstName = "Федор", middleName = "Федорович", address = "Бобруйская 22", CreditCardNumber = "2345678912345678", Balance = 4000M };
            Console.WriteLine($"\nID: {anonymousCustomer.id}, {anonymousCustomer.LastName} {anonymousCustomer.FirstName} {anonymousCustomer.middleName}," +
                $" Адресс: {anonymousCustomer.address}, Номер карты: {anonymousCustomer.CreditCardNumber}, Баланс: {anonymousCustomer.Balance} $");
        }
    }
}
