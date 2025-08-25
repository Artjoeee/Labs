#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

// Структура для представления книги
struct Book 
{
    int bookNumber;  // Номер книги
    string bookName;  // Название книги
};

// Класс хеш-таблицы с цепочками по методу универсального хеширования
class HashTable 
{
private:
    int tableSize;  // Размер таблицы

    vector<Book*> table;  // Вектор указателей на книги
    vector<int> a, b;  // Коэффициенты для метода универсального хеширования

public:
    // Конструктор
    HashTable(int size) : tableSize(size) 
    {
        // Инициализация векторов коэффициентов случайными значениями
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, size - 1);

        for (int i = 0; i < 2; i++) 
        {
            a.push_back(dis(gen));
            b.push_back(dis(gen));
        }

        // Инициализация таблицы
        table.resize(tableSize, nullptr);
    }

    // Метод для вычисления хеша
    int hash(int key) 
    {
        return ((a[0] * key + b[0]) % tableSize + tableSize) % tableSize;
    }

    // Метод для добавления книги в хеш-таблицу
    void addBook(const Book& book) 
    {
        int key = book.bookNumber;
        int index = hash(key);

        if (table[index] == nullptr) 
        {
            table[index] = new Book(book);
        }
        else 
        {
            // Предотвращение коллизий
            cout << "Конфликт хешей. Книга с номером " << key << " не может быть добавлена." << endl;
        }
    }

    // Метод для поиска книги по номеру
    Book* findBook(int key) 
    {
        int index = hash(key);

        if (table[index] != nullptr && table[index]->bookNumber == key) 
        {
            return table[index];
        }

        return nullptr;
    }

    // Метод для удаления книги по номеру
    void removeBook(int key) 
    {
        int index = hash(key);

        if (table[index] != nullptr && table[index]->bookNumber == key) 
        {
            delete table[index];

            table[index] = nullptr;

            cout << "Книга с номером " << key << " удалена." << endl;
        }
        else 
        {
            cout << "Книга с номером " << key << " не найдена." << endl;
        }
    }

    // Метод для вывода всех книг в таблице
    void printBooks() 
    {
        for (int i = 0; i < tableSize; i++) 
        {
            if (table[i] != nullptr) 
            {
                cout << "Строка " << i << ": Номер: " << table[i]->bookNumber << ", Название: " << table[i]->bookName << endl;
            }
        }
    }
};

int main() 
{
    setlocale(0, "ru");

    int tableSize = 100;  // Размер таблицы

    HashTable library(tableSize);

    int choice;

    do 
    {
        cout << "Меню:" << endl;
        cout << "1. Вывести все книги" << endl;
        cout << "2. Добавить книгу" << endl;
        cout << "3. Найти книгу" << endl;
        cout << "4. Удалить книгу" << endl;
        cout << "0. Выйти" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) 
        {

        case 1: 
        {
            cout << "Книги в библиотеке:" << endl;

            library.printBooks();
            break;
        }
        case 2: 
        {
            int bookNumber;

            string bookName;

            cout << "Введите номер книги: ";
            cin >> bookNumber;

            cin.ignore();  // Очистка буфера ввода перед чтением строки

            cout << "Введите название книги: ";
            getline(cin, bookName);

            Book book;

            book.bookNumber = bookNumber;
            book.bookName = bookName;

            library.addBook(book);
            break;
        }
        case 3: 
        {
            int bookNumber;

            cout << "Введите номер книги: ";
            cin >> bookNumber;

            Book* foundBook = library.findBook(bookNumber);

            if (foundBook != nullptr) 
            {
                cout << "Найдена книга: Номер: " << foundBook->bookNumber << ", Название: " << foundBook->bookName << endl;
            }
            else 
            {
                cout << "Книга с номером " << bookNumber << " не найдена." << endl;
            }
            break;
        }
        case 4: 
        {
            int bookNumber;

            cout << "Введите номер книги: ";
            cin >> bookNumber;

            library.removeBook(bookNumber);
            break;
        }
        case 0:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите пункт меню снова." << endl;
            break;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}