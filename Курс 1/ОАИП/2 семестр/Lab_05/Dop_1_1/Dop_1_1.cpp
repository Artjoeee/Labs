#include <iostream>
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

// Функция для ввода информации о книге
void inputBookData(Book& book) 
{
    cout << "Введите автора: ";
    getline(cin, book.author);

    cout << "Введите название книги: ";
    getline(cin, book.title);

    cout << "Введите издательство: ";
    getline(cin, book.publisher);

    cout << "Введите раздел библиотеки: ";
    getline(cin, book.section);

    cout << "Выберите происхождение книги (0 - покупка, 1 - кража, 2 - подарок): ";
    int originInput;
    cin >> originInput;
    cin.ignore();
    book.origin = static_cast<Origin>(originInput);

    cout << "Книга доступна в данный момент? (0 - Нет, 1 - Да): ";
    cin >> book.available;
    cin.ignore();
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
    default:
        originString = "Неизвестно";
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

// Функция для удаления книги из списка
void deleteBook(vector<Book>& library, const string& title) 
{
    for (auto it = library.begin(); it != library.end(); ++it) 
    {
        if (it->title == title) 
        {
            library.erase(it);

            cout << "Книга \"" << title << "\" удалена из библиотеки.\n";
            return;
        }
    }
    cout << "Книга с названием \"" << title << "\" не найдена в библиотеке.\n";
}

// Функция для поиска книги по году издания
void findBookByYear(const vector<Book>& library, int year) 
{
    bool found = false;

    for (const Book& book : library) 
    {
        // Предположим, что год издания можно извлечь из названия книги
        if (book.title.find(to_string(year)) != string::npos) 
        {
            displayBookData(book);
            found = true;
        }
    }
    if (!found) {
        cout << "Издания книг за " << year << " год не найдено.\n";
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Book> library;
    int choice;
    string title;
    int year;
    Book newBook;

    do 
    {
        cout << "\n1. Добавить книгу\n";
        cout << "2. Вывести информацию о книгах в библиотеке\n";
        cout << "3. Удалить книгу\n";
        cout << "4. Найти книги по году издания\n";
        cout << "5. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1:
            inputBookData(newBook);
            library.push_back(newBook);
            break;
        case 2:
            cout << "Информация о книгах в библиотеке:\n";
            for (const Book& book : library) 
            {
                displayBookData(book);
            }
            break;
        case 3:
            cout << "Введите название книги для удаления: ";
            getline(cin, title);
            deleteBook(library, title);
            break;
        case 4:
            cout << "Введите год издания книг: ";
            cin >> year;
            findBookByYear(library, year);
            break;
        case 5:
            cout << "Завершение работы.\n";
            break;
        default:
            cout << "Некорректный выбор.\n";
        }
    } while (choice != 5);

    return 0;
}