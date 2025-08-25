#include <iostream>
#include <fstream>

using namespace std;

// Структура односвязного списка
struct Node
{
    float number;
    Node* next;
};

// Прототипы функций
void insert(Node*& head, float value);
float del(Node*& head, float value);
int isEmpty(Node* head);
void printList(Node* head);
void toFile(Node* head);
void fromFile(Node*& head);
void sum9(Node* head);
void menu();

int main()
{
    setlocale(0, "ru");

    Node* head = nullptr;  // Обнуление указателей
    int choice;
    float value;

    menu();  // Вывод меню выбора действий

    cout << "Ваш выбор: ";
    cin >> choice;

    // Цикл обработки выбора действий
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите число для добавления: ";
            cin >> value;

            insert(head, value);  // Вызов функции для вставки элемента
            printList(head);  // Вывод списка после вставки
            break;
        case 2:
            if (!isEmpty(head))
            {
                cout << "Введите число для удаления: ";
                cin >> value;

                float deletedValue = del(head, value);  // Вызов функции для удаления элемента

                if (deletedValue != 0)
                {
                    cout << "Удалено число " << deletedValue << endl;
                }
                else
                {
                    cout << "Число не найдено" << endl;
                }

                printList(head);  // Вывод списка после удаления
            }
            else
            {
                cout << "Список пуст" << endl;
            }
            break;
        case 3:
            sum9(head);  // Вызов функции для подсчета суммы элементов, меньших 9
            break;
        case 4:
            printList(head);  // Вызов функции для вывода списка на экран
            break;
        case 5:
            toFile(head);  // Запись списка в файл
            break;
        case 6:
            fromFile(head);  // Считывание списка из файла
            break;
        default:
            cout << "Неправильный выбор" << endl;

            menu();
            break;
        }

        cout << "Ваш выбор: ";
        cin >> choice;
    }

    return 0;
}

// Функция добавления элемента в начало списка
void insert(Node*& head, float value)
{
    Node* newNode = new Node;
    newNode->number = value;
    newNode->next = head;
    head = newNode;
}

// Функция удаления элемента из списка
float del(Node*& head, float value)
{
    Node* previous = nullptr;
    Node* current = head;

    if (current != nullptr && current->number == value)
    {
        head = current->next;

        delete current;

        return value;
    }

    while (current != nullptr && current->number != value)
    {
        previous = current;
        current = current->next;
    }

    if (current != nullptr)
    {
        previous->next = current->next;

        float deletedValue = current->number;

        delete current;

        return deletedValue;
    }

    return 0;
}

// Функция проверки списка 
int isEmpty(Node* head)
{
    return head == nullptr;
}

// Функция вывода списка на экран
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
            cout << "-->" << current->number;
            current = current->next;
        }
        cout << "-->NULL" << endl;
    }
}

// Функция записи списка в файл
void toFile(Node* head)
{
    ofstream file("number.txt");

    if (file.is_open())
    {
        Node* current = head;
        while (current != nullptr)
        {
            file << current->number << " ";
            current = current->next;
        }

        file.close();
        cout << "Список записан в файл number.txt" << endl;
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}

// Функция чтения списка из файла
void fromFile(Node*& head)
{
    ifstream file("number.txt");

    if (file.is_open())
    {
        float value;
        while (file >> value)
        {
            insert(head, value);
        }

        file.close();
        cout << "Список считан из файла number.txt" << endl;
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}

// Функция нахождения суммы элементов, меньших 9
void sum9(Node* head)
{
    float sum = 0;
    Node* current = head;

    while (current != nullptr)
    {
        if (current->number < 9)
        {
            sum += current->number;
        }

        current = current->next;
    }

    cout << "Сумма элементов, меньших 9: " << sum << endl;
}

// Функция вывода пользовательского меню
void menu()
{
    cout << "Сделайте выбор:" << endl;
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Удалить элемент" << endl;
    cout << "3 - Найти сумму элементов, меньших 9" << endl;
    cout << "4 - Вывести список" << endl;
    cout << "5 - Записать список в файл" << endl;
    cout << "6 - Считать список из файла" << endl;
    cout << "0 - Выход из программы" << endl;
}