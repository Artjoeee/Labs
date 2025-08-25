#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Перечисление для типа счета
enum AccountType
{
    SAVINGS,
    CURRENT,
    FIXED_DEPOSIT,
    OTHER
};

// Структура для хранения информации о клиенте
struct BankClient
{
    string fullName;
    AccountType accountType;
    long accountNumber;
    double balance;

    // Битовое поле для хранения даты последнего изменения 
    struct Date
    {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 16;
    } 
    lastModified;
};

// Функция для вывода информации о клиенте
void displayClient(const BankClient& client)
{
    cout << "ФИО: " << client.fullName << endl;
    cout << "Тип счета: ";

    // Проверка типа счета
    switch (client.accountType)
    {
    case SAVINGS:
        cout << "Сберегательный" << endl;
        break;
    case CURRENT:
        cout << "Текущий" << endl;
        break;
    case FIXED_DEPOSIT:
        cout << "Депозитный" << endl;
        break;
    case OTHER:
        cout << "Другой" << endl;
        break;
    }

    cout << "Номер счета: " << client.accountNumber << endl;
    cout << "Сумма на счете: " << client.balance << endl;
    cout << "Дата последнего изменения: " << client.lastModified.day << "." << client.lastModified.month << "." << client.lastModified.year << endl;
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<BankClient> clients; // Вектор для хранения клиентов

    int choice;

    do
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить клиента" << endl;
        cout << "2. Вывести всех клиентов" << endl;
        cout << "3. Поиск клиентов по сумме на счете" << endl;
        cout << "4. Удалить клиента" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1: // Добавление нового клиента
        {
            BankClient newClient;

            cout << "Введите ФИО клиента: ";
            cin.ignore(); // Очистим буфер ввода
            getline(cin, newClient.fullName);

            int accountTypeChoice;

            cout << "Выберите тип счета (0 - Сберегательный, 1 - Текущий, 2 - Депозитный, 3 - Другой): ";          
            cin >> accountTypeChoice;

            newClient.accountType = static_cast<AccountType>(accountTypeChoice);

            cout << "Введите номер счета: ";
            cin >> newClient.accountNumber;

            cout << "Введите сумму на счете: ";
            cin >> newClient.balance;

            int day, month, year;

            cout << "Введите дату последнего изменения (день месяц год): "; 
            cin >> day >> month >> year;

            // Заполнение данных о дате последнего изменения
            newClient.lastModified.day = day;
            newClient.lastModified.month = month;
            newClient.lastModified.year = year;

            clients.push_back(newClient); // Добавляем клиента в вектор

            cout << "Клиент успешно добавлен!" << endl << endl;
            break;
        }
        case 2: // Вывод всех клиентов
        {
            if (clients.empty())
            {
                cout << "Нет добавленных клиентов." << endl;
            }
            else
            {
                cout << "Список клиентов:" << endl;
                for (const auto& client : clients)
                {
                    displayClient(client); // Выводим информацию о каждом клиенте
                }
            }
            break;
        }
        case 3: // Поиск клиентов по сумме на счете
        {
            double amount;

            cout << "Введите сумму для поиска (<100, >100): ";
            cin >> amount;

            if (amount < 100)
            {
                cout << "Клиенты с суммой на счете меньше 100:" << endl;
                for (const auto& client : clients)
                {
                    if (client.balance < 100)
                    {
                        displayClient(client); // Выводим информацию о клиенте
                    }
                }
            }
            else
            {
                cout << "Клиенты с суммой на счете больше или равной 100:" << endl;
                for (const auto& client : clients)
                {
                    if (client.balance >= 100)
                    {
                        displayClient(client); // Выводим информацию о клиенте
                    }
                }
            }
            break;
        }
        case 4: // Удаление клиента
        {
            int index;

            cout << "Введите индекс клиента для удаления: ";
            cin >> index;

            if (index >= 0 && index < clients.size())
            {
                clients.erase(clients.begin() + index); // Удаление клиента из вектора
                cout << "Клиент успешно удален!" << endl;
            }
            else
            {
                cout << "Ошибка: Неверный индекс клиента." << endl;
            }
            break;
        }
        case 0: // Выход из программы
        {
            cout << "Выход из программы." << endl;
            break;
        }

        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}