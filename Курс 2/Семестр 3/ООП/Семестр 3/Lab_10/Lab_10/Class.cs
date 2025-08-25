using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_10
{
    public partial class Customer
    {
        private static int objectCount = 0;

        private readonly Guid id;

        private string lastName;
        private string firstName;
        private string middleName;
        private string address;
        private string creditCardNumber;
        private decimal balance;

        private const decimal MinBalance = 0;

        public string LastName
        {
            get
            {
                return lastName;
            }
            set
            {
                lastName = value;
            }
        }

        public string FirstName
        {
            get
            {
                return firstName;
            }
            set
            {
                firstName = value;
            }
        }

        public string MiddleName
        {
            get
            {
                return middleName;
            }
            set
            {
                middleName = value;
            }
        }

        public string Address
        {
            get
            {
                return address;
            }
            set
            {
                address = value;
            }
        }

        public string CreditCardNumber
        {
            get
            {
                return creditCardNumber;
            }
            set
            {
                if (IsValidCreditCard(value))
                    creditCardNumber = value;
                else
                    throw new ArgumentException("Некорректный номер кредитной карты.");
            }
        }

        public decimal Balance
        {
            get
            {
                return balance;
            }
            private set
            {
                balance = value;
            }
        }

        static Customer()
        {
            Console.WriteLine("Создание типа Customer");
        }

        private Customer()
        {
            ++objectCount;
        }

        public Customer(string creditCardNumber)
            : this()
        {
            CreditCardNumber = creditCardNumber;
            balance = MinBalance;
            id = Guid.NewGuid();
        }

        public Customer(string lastName, string firstName, string middleName, string creditCardNumber)
            : this(creditCardNumber)
        {
            LastName = lastName;
            FirstName = firstName;
            MiddleName = middleName;
        }

        public Customer(string lastName, string firstName, string middleName, string address, string creditCardNumber, decimal balance)
            : this(lastName, firstName, middleName, creditCardNumber)
        {
            Address = address;
            Balance = balance;
        }

        public void Deposit(decimal amount)
        {
            if (amount <= 0)
                throw new ArgumentException("Сумма должна быть больше 0.");

            balance += amount;
        }

        public bool TryWithdraw(ref decimal currentBalance, decimal amount, out string result)
        {
            if (amount <= 0)
            {
                result = "Сумма должна быть больше 0.";
                return false;
            }

            if (currentBalance - amount < MinBalance)
            {
                result = "Недостаточно средств.";
                return false;
            }

            currentBalance -= amount;
            result = "Операция успешна.";

            return true;
        }

        public static void DisplayClassInfo()
        {
            Console.WriteLine($"Создано объектов Customer: {objectCount}");
        }

        public override bool Equals(object obj)
        {
            if (obj is Customer otherCustomer)
                return creditCardNumber == otherCustomer.creditCardNumber;

            return false;
        }

        public override int GetHashCode()
        {
            return creditCardNumber.GetHashCode();
        }

        public override string ToString()
        {
            return $"ID: {id}, {lastName} {firstName} {middleName}, Адрес: {address}, Номер карты: {creditCardNumber}, Баланс: {balance} $";
        }

        private bool IsValidCreditCard(string creditCard)
        {
            return creditCard.Length == 8;
        }

        public static void DisplaySortedCustomers(List<Customer> customers)
        {
            var sortedCustomers = customers.OrderBy(c => c.LastName).ThenBy(c => c.FirstName);

            foreach (var customer in sortedCustomers)
            {
                Console.WriteLine(customer);
            }
        }

        public static void DisplayCustomersInCardRange(List<Customer> customers, string start, string end)
        {
            var filteredCustomers = customers.Where(c => string.Compare(c.CreditCardNumber, start) >= 0 && string.Compare(c.CreditCardNumber, end) <= 0);

            foreach (var customer in filteredCustomers)
            {
                Console.WriteLine(customer);
            }
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

        public override string ToString()
        {
            return $"Покупатель: {Name}, Карта: {CreditNumber}, Баланс: {Balance}";
        }
    }

    public class Bank
    {
        public string CreditNumber { get; set; }
        public string Name { get; set; }

        public Bank(string credit, string name) 
        {
            CreditNumber = credit;
            Name = name;
        }
    }
}
