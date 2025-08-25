#include <iostream>

using namespace std;

struct Item 
{
    int data;
    Item* next;
};

Item* head = nullptr;  // Указатель на начало очереди
Item* tail = nullptr;  // Указатель на конец очереди

// Проверка, пуста ли очередь
bool isNull() 
{
    return (head == nullptr);  
}

// Удаление элемента из начала очереди
void deletFirst() 
{
    if (isNull()) 
    {
        cout << "Очередь пуста" << endl;
    }
    else 
    {
        Item* p = head;
        head = head->next;

        delete p;  
    }
}

// Вывод элемента из начала очереди
void getFromHead() 
{
    if (isNull()) 
    {
        cout << "Очередь пуста" << endl;
    }
    else {
        cout << "Начало = " << head->data << endl; 
    }
}

void insertWithPriority(int x) 
{
    Item* p = new Item;
    p->data = x;
    p->next = nullptr;

    if (isNull()) 
    {
        head = tail = p;  // Вставка в пустую очередь
    }
    else if (x <= head->data) // Вставка в начало очереди
    {  
        p->next = head;
        head = p;
    }
    else 
    {
        Item* prev = head;
        Item* current = head->next;

        // Находим место для вставки с учетом приоритета
        while (current != nullptr && x > current->data) 
        {
            prev = current;
            current = current->next;
        }

        // Вставка элемента
        p->next = current;
        prev->next = p;

        if (current == nullptr) 
        {
            tail = p; // Обновление указателя на конец очереди
        }
    }
}

void printQueue() 
{
    Item* p = head;

    if (isNull()) 
    {
        cout << "Очередь пуста" << endl;
    }
    else 
    {
        cout << "Очередь = ";

        while (p != nullptr) 
        {
            cout << p->data << " ";
            cout << "->";
            p = p->next;
        }

        cout << "NULL" << endl;
    }
}

void clrQueue() 
{
    while (!isNull()) 
    {
        deletFirst(); // Очистка очереди путем удаления всех элементов
    }
}

int main() 
{
    setlocale(LC_CTYPE, "Russian");

    int choice = 1, z;

    head = nullptr;
    tail = nullptr;

    while (choice != 0) 
    {
        cout << "1 - добавить элемент" << endl;
        cout << "2 - получить элемент с начала" << endl;
        cout << "3 - извлечь элемент с начала" << endl;
        cout << "4 - вывести элементы" << endl;
        cout << "5 - очистить очередь" << endl;
        cout << "0 - выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Введите элемент:  ";
            cin >> z;

            insertWithPriority(z); // Вставка элемента с учетом приоритета
            printQueue(); // Вывод элементов после вставки
            break;
        case 2:
            getFromHead(); // Вывод элемента из начала очереди
            break;
        case 3:
            deletFirst(); // Извлечение элемента из начала очереди
            break;
        case 4:
            printQueue(); // Вывод всех элементов очереди
            break;
        case 5:
            clrQueue(); // Очистка очереди
            break;
        }
    }

    return 0;
}