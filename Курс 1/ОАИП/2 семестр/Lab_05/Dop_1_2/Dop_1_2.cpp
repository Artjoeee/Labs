#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Перечисление для определения происхождения книги
enum Origin 
{
    PURCHASE,
    THEFT,
    GIFT
};

// Структура для хранения информации о книге
struct Book 
{
    string author;
    string title;
    string publisher;
    string section;
    Origin origin;
    bool available;
};

// Функция для ввода информации о книге с клавиатуры
void inputBookDataFromConsole(Book& book) 
{
    cout << "Введите автора: ";
    getline(cin, book.author);

    cout << "Введите название книги: ";
    getline(cin, book.title);

    cout << "Введите издательство: ";
    getline(cin, book.publisher);

    cout << "Введите раздел библиотеки: ";
    getline(cin, book.section);

    int originInput;

    cout << "Выберите происхождение книги (0 - покупка, 1 - кража, 2 - подарок): ";  
    cin >> originInput;

    cin.ignore(); // Сбрасываем символ новой строки

    book.origin = static_cast<Origin>(originInput);

    cout << "Книга доступна в данный момент? (0 - Нет, 1 - Да): ";
    cin >> book.available;
    cin.ignore(); // Сбрасываем символ новой строки
}

// Функция для вывода информации о книге
void displayBookData(const Book& book) 
{
    string originString;
    switch (book.origin) 
    {
    case PURCHASE:
        originString = "Покупка";
        break;
    case THEFT:
        originString = "Кража";
        break;
    case GIFT:
        originString = "Подарок";
        break;
    }

    string availability = book.available ? "Да" : "Нет";

    cout << "Автор: " << book.author << endl;
    cout << "Название: " << book.title << endl;
    cout << "Издательство: " << book.publisher << endl;
    cout << "Раздел библиотеки: " << book.section << endl;
    cout << "Происхождение: " << originString << endl;
    cout << "Доступность: " << availability << endl;
    cout << endl;
}

// Функция для записи данных о книгах в файл
void writeLibraryToFile(const vector<Book>& library, const string& filename) 
{
    ofstream outFile(filename);

    if (outFile.is_open()) 
    {
        for (const Book& book : library) 
        {
            outFile << book.author << endl;
            outFile << book.title << endl;
            outFile << book.publisher << endl;
            outFile << book.section << endl;
            outFile << book.origin << endl;
            outFile << book.available << endl;
        }

        outFile.close();
        cout << "Данные успешно записаны в файл." << endl;
    }
    else 
    {
        cout << "Ошибка при открытии файла для записи." << endl;
    }
}

// Функция для поиска книг по автору
void searchBooksByAuthor(const vector<Book>& library, const string& author) 
{
    cout << "Результаты поиска по автору '" << author << "':" << endl;
    for (const Book& book : library) 
    {
        if (book.author == author) 
        {
            displayBookData(book);
        }
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Book> library;
    Book book;
    string filename = "library.txt";
    int choice;
    string authorToSearch;

    do 
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Найти книги по автору" << endl;
        cout << "3. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1:
            inputBookDataFromConsole(book);
            library.push_back(book);
            break;
        case 2:
            
            cout << "Введите автора книги для поиска: ";
            getline(cin, authorToSearch);
            searchBooksByAuthor(library, authorToSearch);
            break;
        case 3:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 3);

    // Запись библиотеки в файл
    writeLibraryToFile(library, filename);

    return 0;
}