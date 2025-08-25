#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Перечисление для представления даты рождения как битового поля
struct DateOfBirth 
{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 12;
};

// Структура для хранения информации о контакте
struct Contact 
{
    string fullName;
    DateOfBirth dateOfBirth;
    string address;
    string phone;
};

// Функция для ввода данных о новом контакте
Contact inputContactData() 
{
    Contact contact;

    cout << "Введите Ф.И.О. контакта: ";
    getline(cin, contact.fullName);

    int day, month, year;

    cout << "Введите дату рождения (ДД ММ ГГГГ): ";
    cin >> day >> month >> year;

    contact.dateOfBirth.day = day;
    contact.dateOfBirth.month = month;
    contact.dateOfBirth.year = year;

    cin.ignore(); // Очистка символа новой строки из ввода

    cout << "Введите адрес контакта: ";
    getline(cin, contact.address);

    cout << "Введите номер телефона контакта: ";
    getline(cin, contact.phone);

    return contact;
}

// Функция для вывода информации о контакте
void displayContactData(const Contact& contact) 
{
    cout << "Ф.И.О.: " << contact.fullName << endl;
    cout << "Дата рождения: " << contact.dateOfBirth.day << " " << contact.dateOfBirth.month << " " << contact.dateOfBirth.year << endl;
    cout << "Адрес: " << contact.address << endl;
    cout << "Телефон: " << contact.phone << endl;
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
    int choice;
    string lastName;

    do 
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить контакт" << endl;
        cout << "2. Вывести все контакты" << endl;
        cout << "3. Поиск по фамилии" << endl;
        cout << "4. Удалить контакт" << endl;
        cout << "5. Выход" << endl;
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
        {            
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
        case 4:
            if (!contacts.empty()) 
            {
                int index;

                cout << "Выберите контакт для удаления (введите индекс): ";
                cin >> index;

                contacts.erase(contacts.begin() + index); // Удаление
                cout << "Контакт удален." << endl;
            }
            else 
            {
                cout << "Список контактов пустой." << endl;
            }
            break;
        case 5:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);

    return 0;
}