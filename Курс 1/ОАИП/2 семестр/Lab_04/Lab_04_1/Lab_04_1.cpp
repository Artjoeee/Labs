#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

// Прототипы
void addBook();
void displayBooks();
void deleteBook();
void searchByAuthor();
void saveToFile();
void readFromFile();

// Структура для представления информации о книге
struct Book 
{
    string author;
    string title;
    string publisher;
    string category;
    string origin;
    bool available;
};

// Вектор для хранения информации о книгах в библиотеке
vector<Book> library;

// Функция для добавления книги в библиотеку
void addBook() 
{
    Book newBook;

    // Ввод информации о книге
    cout << "Введите автора: ";
    getline(cin, newBook.author);

    cout << "Введите название: ";
    getline(cin, newBook.title);

    cout << "Введите издателя: ";
    getline(cin, newBook.publisher);

    cout << "Введите категорию: ";
    getline(cin, newBook.category);

    cout << "Введите происхождение (покупка/кража/подарок): ";
    getline(cin, newBook.origin);

    cout << "Доступна ли книга в данный момент? (0 - Нет, 1 - Да): ";
    cin >> newBook.available;

    cin.ignore(); // Игнорируем символ новой строки

    library.push_back(newBook); // Добавляем новую книгу в библиотеку
}

// Функция для добавления книги в библиотеку
void displayBooks() 
{
    for (int i = 0; i < library.size(); ++i) 
    {
        // Перебираем все книги в библиотеке и выводим информацию о каждой
        cout << "Книга " << i + 1 << endl;
        cout << "Автор: " << library[i].author << endl;
        cout << "Название: " << library[i].title << endl;
        cout << "Издатель: " << library[i].publisher << endl;
        cout << "Категория: " << library[i].category << endl;
        cout << "Происхождение: " << library[i].origin << endl;
        cout << "Наличие: " << (library[i].available ? "Есть" : "Нет") << endl << endl;
    }
}

// Функция для удаления выбранной книги из библиотеки
void deleteBook() 
{
    int index;

    cout << "Введите индекс книги для удаления: ";
    cin >> index;

    // Удаляем книгу из библиотеки по указанному индексу
    if (index >= 0 && index < library.size()) 
    {
        library.erase(library.begin() + index);
        cout << "Книга успешно удалена" << endl;
    }
    else 
    {
        cout << "Неверный индекс" << endl;
    }
}

// Функция для поиска книги по автору
void searchByAuthor() 
{
    string searchAuthor;

    cout << "Введите автора для поиска: ";
    getline(cin, searchAuthor);

    bool found = false;

    // Ищем книги по заданному автору и выводим информацию
    for (const Book& book : library) 
    {
        if (book.author == searchAuthor) 
        {
            cout << "Книга найдена:" << endl;
            cout << "Автор: " << book.author << endl;
            cout << "Название: " << book.title << endl;
            cout << "Издатель: " << book.publisher << endl;
            cout << "Категория: " << book.category << endl;
            cout << "Происхождение: " << book.origin << endl;
            cout << "Наличие: " << (book.available ? "Есть" : "Нет") << endl << endl;
            
            found = true;
        }
    }

    if (!found) 
    {
        cout << "Книга автора " << searchAuthor << " не найдена" << endl;
    }
}

// Функция для сохранения данных о книгах в файл
void saveToFile() 
{
    ofstream fout("library.txt");

    if (!fout.is_open()) 
    {
        cerr << "Ошибка открытия файла" << endl;
        exit(1);
    }

    // Записываем данные о книгах в файл
    for (const Book& book : library) 
    {
        fout << book.author << endl;
        fout << book.title << endl;
        fout << book.publisher << endl;
        fout << book.category << endl;
        fout << book.origin << endl;
        fout << book.available << endl;
    }

    fout.close();

    cout << "Данные сохранены в библиотеку" << endl;
}

// Функция для чтения данных о книгах из файла
void readFromFile() 
{
    ifstream fin("library.txt");

    if (!fin.is_open()) 
    {
        cerr << "Ошибка открытия файла" << endl;
        exit(1);
    }

    library.clear();

    Book book;

    // Читаем данные о книгах из файла
    while (getline(fin, book.author)) 
    {
        getline(fin, book.title);
        getline(fin, book.publisher);
        getline(fin, book.category);
        getline(fin, book.origin);

        fin >> book.available;

        fin.ignore(); // Игнорируем символ новой строки
        library.push_back(book);
    }

    fin.close();

    cout << "Данные успешно прочитаны из библиотеки" << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    // Основное меню программы
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавление книги" << endl;
        cout << "2. Вывод всех книг" << endl;
        cout << "3. Удаление книги" << endl;
        cout << "4. Поиск книг по автору" << endl;
        cout << "5. Сохранение данных в библиотеку" << endl;
        cout << "6. Чтение данных из библиотеки" << endl;
        cout << "0. Выход" << endl;

        cout << "Выбирите вариант: ";
        cin >> choice;

        cin.ignore(); // Игнорируем символ новой строки

        // Обработка выбора пользователя
        switch (choice) 
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            deleteBook();
            break;
        case 4:
            searchByAuthor();
            break;
        case 5:
            saveToFile();
            break;
        case 6:
            readFromFile();
            break;
        case 0:
            cout << "Завершение программы" << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова" << endl;
        }

    } while (choice != 0);

    return 0;
}