#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

// ���������
void addBook();
void displayBooks();
void deleteBook();
void searchByAuthor();
void saveToFile();
void readFromFile();

// ��������� ��� ������������� ���������� � �����
struct Book 
{
    string author;
    string title;
    string publisher;
    string category;
    string origin;
    bool available;
};

// ������ ��� �������� ���������� � ������ � ����������
vector<Book> library;

// ������� ��� ���������� ����� � ����������
void addBook() 
{
    Book newBook;

    // ���� ���������� � �����
    cout << "������� ������: ";
    getline(cin, newBook.author);

    cout << "������� ��������: ";
    getline(cin, newBook.title);

    cout << "������� ��������: ";
    getline(cin, newBook.publisher);

    cout << "������� ���������: ";
    getline(cin, newBook.category);

    cout << "������� ������������� (�������/�����/�������): ";
    getline(cin, newBook.origin);

    cout << "�������� �� ����� � ������ ������? (0 - ���, 1 - ��): ";
    cin >> newBook.available;

    cin.ignore(); // ���������� ������ ����� ������

    library.push_back(newBook); // ��������� ����� ����� � ����������
}

// ������� ��� ���������� ����� � ����������
void displayBooks() 
{
    for (int i = 0; i < library.size(); ++i) 
    {
        // ���������� ��� ����� � ���������� � ������� ���������� � ������
        cout << "����� " << i + 1 << endl;
        cout << "�����: " << library[i].author << endl;
        cout << "��������: " << library[i].title << endl;
        cout << "��������: " << library[i].publisher << endl;
        cout << "���������: " << library[i].category << endl;
        cout << "�������������: " << library[i].origin << endl;
        cout << "�������: " << (library[i].available ? "����" : "���") << endl << endl;
    }
}

// ������� ��� �������� ��������� ����� �� ����������
void deleteBook() 
{
    int index;

    cout << "������� ������ ����� ��� ��������: ";
    cin >> index;

    // ������� ����� �� ���������� �� ���������� �������
    if (index >= 0 && index < library.size()) 
    {
        library.erase(library.begin() + index);
        cout << "����� ������� �������" << endl;
    }
    else 
    {
        cout << "�������� ������" << endl;
    }
}

// ������� ��� ������ ����� �� ������
void searchByAuthor() 
{
    string searchAuthor;

    cout << "������� ������ ��� ������: ";
    getline(cin, searchAuthor);

    bool found = false;

    // ���� ����� �� ��������� ������ � ������� ����������
    for (const Book& book : library) 
    {
        if (book.author == searchAuthor) 
        {
            cout << "����� �������:" << endl;
            cout << "�����: " << book.author << endl;
            cout << "��������: " << book.title << endl;
            cout << "��������: " << book.publisher << endl;
            cout << "���������: " << book.category << endl;
            cout << "�������������: " << book.origin << endl;
            cout << "�������: " << (book.available ? "����" : "���") << endl << endl;
            
            found = true;
        }
    }

    if (!found) 
    {
        cout << "����� ������ " << searchAuthor << " �� �������" << endl;
    }
}

// ������� ��� ���������� ������ � ������ � ����
void saveToFile() 
{
    ofstream fout("library.txt");

    if (!fout.is_open()) 
    {
        cerr << "������ �������� �����" << endl;
        exit(1);
    }

    // ���������� ������ � ������ � ����
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

    cout << "������ ��������� � ����������" << endl;
}

// ������� ��� ������ ������ � ������ �� �����
void readFromFile() 
{
    ifstream fin("library.txt");

    if (!fin.is_open()) 
    {
        cerr << "������ �������� �����" << endl;
        exit(1);
    }

    library.clear();

    Book book;

    // ������ ������ � ������ �� �����
    while (getline(fin, book.author)) 
    {
        getline(fin, book.title);
        getline(fin, book.publisher);
        getline(fin, book.category);
        getline(fin, book.origin);

        fin >> book.available;

        fin.ignore(); // ���������� ������ ����� ������
        library.push_back(book);
    }

    fin.close();

    cout << "������ ������� ��������� �� ����������" << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    // �������� ���� ���������
    do {
        cout << "����:" << endl;
        cout << "1. ���������� �����" << endl;
        cout << "2. ����� ���� ����" << endl;
        cout << "3. �������� �����" << endl;
        cout << "4. ����� ���� �� ������" << endl;
        cout << "5. ���������� ������ � ����������" << endl;
        cout << "6. ������ ������ �� ����������" << endl;
        cout << "0. �����" << endl;

        cout << "�������� �������: ";
        cin >> choice;

        cin.ignore(); // ���������� ������ ����� ������

        // ��������� ������ ������������
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
            cout << "���������� ���������" << endl;
            break;
        default:
            cout << "�������� �����. ���������� �����" << endl;
        }

    } while (choice != 0);

    return 0;
}