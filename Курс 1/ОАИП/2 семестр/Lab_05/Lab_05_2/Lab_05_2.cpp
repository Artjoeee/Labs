#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Структура для хранения данных о клиенте
struct Client 
{
    string fullName;
    string accountType;
    int accountNumber;
    double accountBalance;
    string lastModifiedDate;
};

// Функция для ввода данных клиента
void inputClientData(Client& client) 
{
    cout << "Введите ФИО: ";
    getline(cin, client.fullName);

    cout << "Введите тип счёта (1 - срочный, 2 - льготный): ";
    getline(cin, client.accountType);

    cout << "Введите номер счёта: ";
    cin >> client.accountNumber;

    cout << "Введите сумму на счёте: ";
    cin >> client.accountBalance;

    cin.ignore(); 

    cout << "Введите дату последнего изменения: ";
    getline(cin, client.lastModifiedDate);
}

// Функция для вывода данных клиента
void displayClientData(const Client& client) 
{
    cout << "ФИО: " << client.fullName << endl;
    cout << "Тип счёта: " << client.accountType << endl;
    cout << "Номер счёта: " << client.accountNumber << endl;
    cout << "Сумма на счёте: " << client.accountBalance << endl;
    cout << "Дата последнего изменения: " << client.lastModifiedDate << endl;
}

// Функция для записи данных о клиенте в файл
void writeClientToFile(const Client& client, const string& fileName) 
{
    ofstream file(fileName, ios::app);
    file << client.fullName << "," << client.accountType << ","
        << client.accountNumber << "," << client.accountBalance << ","
        << client.lastModifiedDate << endl;
    file.close();
}

// Функция для чтения данных о клиентах из файла и их вывода
void readClientFromFile(const string& fileName) 
{
    ifstream file(fileName);
    string line;

    while (getline(file, line)) 
    {
        cout << line << endl;
    }

    file.close();
}

// Функция для поиска клиента по номеру счёта
Client findClientByAccountNumber(const string& fileName, int accountNumber) 
{
    ifstream file(fileName);
    Client client;

    while (file >> client.fullName >> client.accountType >> client.accountNumber >> client.accountBalance >> client.lastModifiedDate) 
    {
        if (client.accountNumber == accountNumber) 
        {
            file.close();

            return client;
        }
    }

    file.close();

    return { "", "", 0, 0.0, "" }; // Возвращаем пустого клиента, если не найден
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Client client;
    string fileName = "client.txt";

    int choice;
    int accountNumber;

    do 
    {
        cout << "\n1. Введите данные клиента\n";
        cout << "2. Вывод всех клиентов\n";
        cout << "3. Запись данных в файл\n";
        cout << "4. Чтение данных из файла\n";
        cout << "5. Поиск клиента по номеру счёта\n";
        cout << "6. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        cin.ignore(); 

        switch (choice) 
        {
        case 1:
            inputClientData(client); // Вызов функции ввода данных клиента
            break;
        case 2:
            displayClientData(client); // Вызов функции вывода данных клиента
            break;
        case 3:
            writeClientToFile(client, fileName); // Вызов функции записи данных о клиенте в файл
            break;
        case 4:
            readClientFromFile(fileName); // Вызов функции чтения данных клиентов из файла
            break;
        case 5:
        {
            cout << "Введите номер счёта для поиска: ";
            cin >> accountNumber;

            cin.ignore();

            client = findClientByAccountNumber(fileName, accountNumber); // Поиск клиента по номеру счета

            if (client.fullName != "")
            {
                cout << "Клиент найден:\n";
                displayClientData(client); // Вывод информации о найденном клиенте
            }
            else
            {
                cout << "Клиент не найден.\n";
            }
            break;
        }
        case 6:
            cout << "Конец программы.\n";
            break;
        default:
            cout << "Неправильный выбор.\n";
        }
    } while (choice != 6);

    return 0;
}