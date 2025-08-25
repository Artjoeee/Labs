using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_02
{
    public partial class Customer
    {
        // Поле для подсчета количества объектов класса Customer
        private static int objectCount = 0;     
        
        // Поле только для чтения, которое хранит id
        private readonly Guid id;               
        
        // Поля для хранения информации о клиенте
        private string lastName;
        private string firstName;
        private string middleName;
        private string address;
        private string creditCardNumber;
        private decimal balance;

        // Константа для минимально допустимого баланса
        private const decimal MinBalance = 0;

        // Свойство для доступа к полю lastName
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

        // Свойство для доступа к полю firstName
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

        // Свойство для доступа к полю middleName
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

        // Свойство для доступа к полю address
        public string Address
        {
            get 
            {
                return address; 
            }
            set 
            { address = value; 
            }
        }

        // Свойство для доступа к полю creditCardNumber
        public string CreditCardNumber
        {
            get 
            {
                return creditCardNumber; 
            }
            set
            {
                // Проверяем корректность номера кредитной карты
                if (IsValidCreditCard(value))
                    creditCardNumber = value;
                else
                    throw new ArgumentException("Некорректный номер кредитной карты.");
            }
        }

        // Свойство для доступа к балансу клиента 
        public decimal Balance
        {
            get 
            {
                return balance; 
            }
            private set // Записывать значение можно только внутри класса
            {
                balance = value; 
            }
        }

        // Статический конструктор, который вызывается один раз
        static Customer()
        {
            Console.WriteLine("Создание типа Customer");
        }

        // Приватный конструктор
        private Customer()
        {
            ++objectCount; 
        }

        public Customer(string creditCardNumber)
            : this() // Вызов приватного конструктора
        {
            this.CreditCardNumber = creditCardNumber; // Инициализация свойства CreditCardNumber
            balance = MinBalance;
            id = Guid.NewGuid();
        }

        // Конструктор с параметрами для инициализации фамилии, имени, отчества и номера карты
        public Customer(string lastName, string firstName, string middleName, string creditCardNumber)
            : this(creditCardNumber) // Вызов конструктора с номером карты
        {
            // Инициализация полей через свойства
            this.LastName = lastName;
            this.FirstName = firstName;
            this.MiddleName = middleName;
        }

        // Полный конструктор с дополнительными параметрами: адресом и балансом
        public Customer(string lastName, string firstName, string middleName, string address, string creditCardNumber, decimal balance)
            : this(lastName, firstName, middleName, creditCardNumber) // Вызов конструктора с базовыми параметрами
        {
            this.Address = address;
            this.Balance = balance;
        }

        // Метод для зачисления средств на баланс клиента
        public void Deposit(decimal amount)
        {
            if (amount <= 0)
                throw new ArgumentException("Сумма должна быть больше 0.");

            balance += amount;
        }

        // Метод для списания средств с баланса клиента с использованием ключевых слов ref и out
        public bool TryWithdraw(ref decimal currentBalance, decimal amount, out string result)
        {
            // Проверка, что сумма для списания больше нуля
            if (amount <= 0)
            {
                result = "Сумма должна быть больше 0.";
                return false;
            }

            // Проверка, что после списания баланс не будет ниже минимального
            if (currentBalance - amount < MinBalance)
            {
                result = "Недостаточно средств.";
                return false;
            }

            // Списание средств и обновление баланса через параметр ref
            currentBalance -= amount; 
            result = "Операция успешна.";

            return true;
        }

        // Статический метод для отображения информации о количестве созданных объектов класса
        public static void DisplayClassInfo()
        {
            Console.WriteLine($"Создано объектов Customer: {objectCount}");
        }

        // Переопределение метода Equals для сравнения объектов Customer по номеру кредитной карты
        public override bool Equals(object obj)
        {
            if (obj is Customer otherCustomer)
                return creditCardNumber == otherCustomer.creditCardNumber;

            return false;
        }

        // Переопределение метода GetHashCode для генерации хэш-кода на основе номера кредитной карты
        public override int GetHashCode()
        {
            return creditCardNumber.GetHashCode();
        }

        // Переопределение метода ToString для представления объекта в виде строки
        public override string ToString()
        {
            return $"ID: {id}, {lastName} {firstName} {middleName}, Адрес: {address}, Номер карты: {creditCardNumber}, Баланс: {balance} $";
        }

        // Приватный метод для проверки номера кредитной карты
        private bool IsValidCreditCard(string creditCard)
        {
            return creditCard.Length == 16;
        }

        // Статический метод для отображения списка клиентов в алфавитном порядке
        public static void DisplaySortedCustomers(List<Customer> customers)
        {
            // Сортируем клиентов сначала по фамилии, затем по имени
            var sortedCustomers = customers.OrderBy(c => c.LastName).ThenBy(c => c.FirstName).ToList();

            foreach (var customer in sortedCustomers)
            {
                Console.WriteLine(customer);
            }
        }

        // Статический метод для фильтрации клиентов по диапазону номеров кредитных карт
        public static void DisplayCustomersInCardRange(List<Customer> customers, string start, string end)
        {
            // Фильтруем клиентов по диапазону номеров кредитных карт
            var filteredCustomers = customers.Where(c => string.Compare(c.CreditCardNumber, start) >= 0 && string.Compare(c.CreditCardNumber, end) <= 0).ToList();

            foreach (var customer in filteredCustomers)
            {
                Console.WriteLine(customer);
            }
        }
    }
}
