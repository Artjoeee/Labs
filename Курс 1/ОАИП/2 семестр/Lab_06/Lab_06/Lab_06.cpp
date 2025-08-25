#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// Структура односвязного списка
struct Node
{
    char data;
    Node* next;
};

// Прототипы функций
void insert(Node*& head, char value);
void remove(Node*& head, char value);
void searchAndPrintNext(Node* head, char value);
void printList(Node* head);
void toFile(Node* head);
void fromFile(Node*& head);
void menu();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head = nullptr;  // Обнуление указателей
    int choice;
    char value;

    menu();  // Вывод меню выбора действий

    cout << "Ваш выбор: ";
    cin >> choice;

    // Цикл обработки выбора действий
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите символ: ";
            cin >> value;

            insert(head, value);  // Вызов функции для вставки элемента
            printList(head);  // Вывод списка после вставки
            break;
        case 2:
            cout << "Введите символ для удаления: ";
            cin >> value;

            remove(head, value);  // Вызов функции для удаления элемента
            printList(head);  // Вывод списка после удаления
            break;
        case 3:
            cout << "Введите символ для поиска и вывода следующего: ";
            cin >> value;

            searchAndPrintNext(head, value);  // Вызов функции для поиска и печати следующего элемента
            break;
        case 4:
            printList(head);  // Вывод текущего списка
            break;
        case 5:
            toFile(head);  // Запись списка в файл
            break;
        case 6:
            fromFile(head);  // Чтение списка из файла
            break;
        default:
            cout << "Неправильный выбор" << endl;

            menu();  // Вывод меню выбора действий
            break;
        }

        cout << "Ваш выбор: ";
        cin >> choice;
    }

    return 0;
}

// Функция для вставки элемента в начало списка
void insert(Node*& head, char value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Функция для удаления элемента из списка
void remove(Node*& head, char value)
{
    Node* current = head;
    Node* previous = nullptr;  // Обнуление указателей

    while (current != nullptr)
    {
        if (current->data == value)
        {
            if (previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "Символ не найден для удаления" << endl;
}

// Функция для поиска и печати следующего элемента списка
void searchAndPrintNext(Node* head, char value)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value && current->next != nullptr)
        {
            cout << "Найденный символ: " << current->data << ", Следующий символ: " << current->next->data << endl;
            return;
        }

        current = current->next;
    }

    cout << "Символ не найден или отсутствует следующий символ" << endl;
}

// Функция для вывода элементов списка
void printList(Node* head)
{
    if (head == nullptr)
    {
        cout << "Список пуст" << endl;
    }
    else
    {
        cout << "Список:" << endl;
        Node* current = head;

        while (current != nullptr)
        {
            cout << "-->" << current->data;
            current = current->next;
        }

        cout << "-->NULL" << endl;
    }
}

// Функция для записи списка в файл
void toFile(Node* head)
{
    ofstream file("symbol.txt");

    if (file.is_open())
    {
        Node* current = head;

        while (current != nullptr)
        {
            file << current->data << " ";
            current = current->next;
        }

        file.close();

        cout << "Список записан в файл symbol.txt" << endl;
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}

// Функция для чтения списка из файла
void fromFile(Node*& head)
{
    ifstream file("symbol.txt");

    if (file.is_open())
    {
        char value;

        while (file >> value)
        {
            insert(head, value);
        }

        file.close();

        cout << "Список считан из файла symbol.txt" << endl;
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}

// Функция для вывода меню выбора действий
void menu()
{
    cout << "Сделайте выбор:" << endl;
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Удалить элемент" << endl;
    cout << "3 - Поиск и вывод следующего элемента" << endl;
    cout << "4 - Вывести список" << endl;
    cout << "5 - Записать список в файл" << endl;
    cout << "6 - Считать список из файла" << endl;
    cout << "0 - Выход из программы" << endl;
}