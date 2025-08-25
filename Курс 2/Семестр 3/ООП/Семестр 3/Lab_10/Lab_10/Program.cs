using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Lab_10
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] monthsOfYear = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
            string[] winterAndSommer = { "December", "January", "February", "June", "July", "August" };


            var selectedMonths = from p in monthsOfYear
                                 where p.Length == 5
                                 select p;

            foreach (string month in selectedMonths)
            {
                Console.WriteLine(month);
            }

            Console.WriteLine();


            var selected = from p in monthsOfYear
                                 where winterAndSommer.Contains(p)
                                 select p;

            foreach (string month in selected)
            {
                Console.WriteLine(month);
            }

            Console.WriteLine();


            var sorted = from p in monthsOfYear
                           orderby p
                           select p;

            foreach (string month in sorted)
            {
                Console.WriteLine(month);
            }

            Console.WriteLine();


            var conteiner = from p in monthsOfYear
                                 where p.Contains("u") && p.Length >= 4
                                 select p;

            foreach (string month in conteiner)
            {
                Console.WriteLine(month);
            }

            Console.WriteLine();


            // -------------------------------------------------------------------------------------------------


            Customer customer1 = new Customer("Иванов", "Иван", "Иванович", "Бобруйская 25", "12345678", 5000);
            Customer customer2 = new Customer("Петров", "Петр", "Петрович", "Бобруйская 24", "23456789", 3000);
            Customer customer3 = new Customer("Сидоров", "Сидор", "Сидорович", "Бобруйская 23", "34567890", 7000);
            Customer customer4 = new Customer("Степанов", "Степан", "Степанович", "Бобруйская 26", "67845678", 4000);
            Customer customer5 = new Customer("Алексеев", "Алексей", "Алексеевич", "Бобруйская 27", "43256789", 2000);
            Customer customer6 = new Customer("Артёмов", "Артём", "Артёмович", "Бобруйская 28", "98767890", 1000);
            Customer customer7 = new Customer("Александров", "Александр", "Александрович", "Бобруйская 29", "56745678", 6000);
            Customer customer8 = new Customer("Станиславин", "Станислав", "Станиславович", "Бобруйская 30", "45656789", 8000);
            Customer customer9 = new Customer("Николаев", "Николай", "Николаевич", "Бобруйская 31", "78967890", 9000);
            Customer customer10 = new Customer("Артуров", "Артур", "Артурович", "Бобруйская 32", "76545678", 10000);

            List<Customer> list = new List<Customer>{ customer1, customer2, customer3, customer4, customer5, customer6, customer7, customer8, customer9, customer10};


            var sortedCustomers = from customer in list
                                  orderby customer.LastName, customer.FirstName
                                  select customer;

            foreach (var item in sortedCustomers)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine();


            Customer.DisplaySortedCustomers(list);

            Console.WriteLine();


            // ----------------------------------------------------------------------------------------------------


            Buyer buyer1 = new Buyer("Снежана", "52525252", 2000);
            Buyer buyer2 = new Buyer("Дарья", "42424242", 3000);
            Buyer buyer3 = new Buyer("Елена", "34343434", 9000);
            Buyer buyer4 = new Buyer("Екатерина", "23232323", 8000);
            Buyer buyer5 = new Buyer("Маргарита", "89898989", 4000);
            Buyer buyer6 = new Buyer("Светлана", "76767676", 7000);
            Buyer buyer7 = new Buyer("Валерия", "19191919", 1000);
            Buyer buyer8 = new Buyer("Марина", "28282828", 5000);

            List<Buyer> buyers = new List<Buyer> { buyer1, buyer2, buyer3, buyer4, buyer5, buyer6, buyer7, buyer8 };


            var sortedBuyers = from buyer in buyers
                               orderby buyer.Name
                               select buyer;

            foreach (var item in sortedBuyers)
            {
                Console.WriteLine(item);
            }
            
            Console.WriteLine();


            var filteredBuyers = from buyer in buyers
                                where string.Compare(buyer.CreditNumber, "34343434") >= 0 && string.Compare(buyer.CreditNumber, "76767676") <= 0
                                select buyer;

            foreach (var item in filteredBuyers)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine();


            var maxBuyer = buyers.Where(buyer => buyer.Balance == buyers.Max(b => b.Balance));

            foreach (var item in maxBuyer)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine();


            var fiveBuyers = buyers.OrderByDescending(buyer => buyer.Balance).Take(5);

            foreach (var item in fiveBuyers)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine();


            // -----------------------------------------------------------------------------------------------------


            string[] numbers = { "one", "two", "three", "four", "five", "six" };

            var sortedNumbers = numbers.Where(n => n.Contains("o")).OrderBy(n => n.Length).GroupBy(n => n.Length).Count();

            Console.WriteLine(sortedNumbers);

            Console.WriteLine();


            // -------------------------------------------------------------------------------------------------------


            List<Bank> banks = new List<Bank>
            {
                new Bank("52525252", "Приорбанк"),
                new Bank("42424242", "Альфабанк"),
                new Bank("34343434", "Беларусбанк")
            };

            List<Buyer> buyersByBanks = new List<Buyer> { buyer1, buyer2, buyer3 };

            var sortedBanks = buyersByBanks.Join(banks, b => b.CreditNumber, c => c.CreditNumber, (b, c) => new { NameOfBuyer = b.Name, NameOfBank = c.Name });

            foreach (var item in sortedBanks)
            {
                Console.WriteLine($"{item.NameOfBuyer}: {item.NameOfBank}");
            }
        }
    }
}
