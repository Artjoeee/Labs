#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Структура для хранения информации о контакте
struct Contact 
{
    string fullName;
    string dateOfBirth;
    string address;
    string phone;
    string workplace;
    string position;
};

// Функция для ввода данных о контакте
Contact inputContactData() 
{
    Contact contact;

    cout << "Введите Ф.И.О. контакта: ";
    getline(cin, contact.fullName);

    cout << "Введите дату рождения (ДД.ММ.ГГГГ): ";
    getline(cin, contact.dateOfBirth);

    cout << "Введите адрес контакта: ";
    getline(cin, contact.address);

    cout << "Введите номер телефона контакта: ";
    getline(cin, contact.phone);

    cout << "Введите место работы или учебы: ";
    getline(cin, contact.workplace);

    cout << "Введите должность: ";
    getline(cin, contact.position);

    return contact;
}

// Функция для вывода информации о контакте
void displayContactData(const Contact& contact) 
{
    cout << "Ф.И.О.: " << contact.fullName << endl;
    cout << "Дата рождения: " << contact.dateOfBirth << endl;
    cout << "Адрес: " << contact.address << endl;
    cout << "Телефон: " << contact.phone << endl;
    cout << "Место работы/учебы: " << contact.workplace << endl;
    cout << "Должность: " << contact.position << endl;
}

// Функция для записи контакта в файл
void writeContactToFile(const Contact& contact, const string& filename) 
{
    ofstream file(filename, ios::app);

    if (file.is_open()) 
    {
        file << contact.fullName << endl;
        file << contact.dateOfBirth << endl;
        file << contact.address << endl;
        file << contact.phone << endl;
        file << contact.workplace << endl;
        file << contact.position << endl;
        file << endl;

        file.close();

        cout << "Контакт успешно записан в файл." << endl;
    }
    else 
    {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}

// Функция для чтения контактов из файла
vector<Contact> readContactsFromFile(const string& filename) 
{
    vector<Contact> contacts;
    ifstream file(filename);

    if (file.is_open()) 
    {
        Contact contact;

        while (getline(file, contact.fullName)) 
        {
            getline(file, contact.dateOfBirth);
            getline(file, contact.address);
            getline(file, contact.phone);
            getline(file, contact.workplace);
            getline(file, contact.position);
            contacts.push_back(contact);
        }

        file.close();
    }
    else 
    {
        cout << "Ошибка открытия файла для чтения." << endl;
    }
    return contacts;
}

// Функция для поиска контакта по фамилии
vector<Contact> searchContactsByLastName(const vector<Contact>& contacts, const string& lastName) 
{
    vector<Contact> foundContacts;

    for (const auto& contact : contacts) 
    {
        size_t pos = contact.fullName.find_last_of(' ');
        string contactLastName = contact.fullName.substr(pos + 1);

        if (contactLastName == lastName) 
        {
            foundContacts.push_back(contact);
        }
    }

    return foundContacts;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Contact> contacts;

    // Название файла для хранения контактов
    const string filename = "contacts.txt";

    int choice;

    do 
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить контакт" << endl;
        cout << "2. Вывести все контакты" << endl;
        cout << "3. Записать контакты в файл" << endl;
        cout << "4. Прочитать контакты из файла" << endl;
        cout << "5. Поиск по фамилии" << endl;
        cout << "6. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        cin.ignore(); // Очистка символа новой строки из ввода

        switch (choice) 
        {
        case 1:
            contacts.push_back(inputContactData());
            break;
        case 2:
            cout << "Все контакты:" << endl;
            for (const auto& contact : contacts) 
            {
                displayContactData(contact);
                cout << endl;
            }
            break;
        case 3:
            for (const auto& contact : contacts) 
            {
                writeContactToFile(contact, filename);
            }
            break;
        case 4:
            contacts = readContactsFromFile(filename);
            cout << "Контакты успешно прочитаны из файла." << endl;
            break;
        case 5:
        {
            string lastName;

            cout << "Введите фамилию для поиска: ";
            getline(cin, lastName);

            vector<Contact> foundContacts = searchContactsByLastName(contacts, lastName);

            if (foundContacts.empty()) 
            {
                cout << "Контакты с такой фамилией не найдены." << endl;
            }
            else 
            {
                cout << "Найденные контакты:" << endl;

                for (const auto& contact : foundContacts) 
                {
                    displayContactData(contact);
                    cout << endl;
                }
            }
        }
        break;
        case 6:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 6);

    return 0;
}