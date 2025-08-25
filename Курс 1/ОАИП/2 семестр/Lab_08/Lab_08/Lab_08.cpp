#include <iostream>

using namespace std;

struct Queue 
{
    char data;
    Queue* next;
};

// Функция для добавления элемента в очередь
void enqueue(char x, Queue*& front, Queue*& rear) 
{
    Queue* newNode = new Queue;
    newNode->data = x;
    newNode->next = nullptr;

    if (front == nullptr) 
    {
        front = rear = newNode;
    }
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Функция для удаления элемента из очереди
char dequeue(Queue*& front, Queue*& rear) 
{
    if (front == nullptr) 
    {
        cout << "Очередь пуста.\n";

        return '\0';
    }

    Queue* temp = front;
    char data = front->data;

    if (front == rear) 
    {
        front = rear = nullptr;  // Очищаем очередь, если в ней был один элемент
    }
    else 
    {
        front = front->next;  // Перемещаем front на следующий элемент
    }

    delete temp;

    return data;
}

// Функция для вывода элементов в очереди
void display(Queue* front) 
{
    if (front == nullptr) 
    {
        cout << "Очередь пуста.\n";

        return;
    }

    Queue* current = front;

    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

int main() 
{
    setlocale(0, "ru");

    Queue* front = nullptr;
    Queue* rear = nullptr;

    int maxSize;

    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    char input;

    while (maxSize > 0) 
    {
        cout << "Введите элемент очереди: ";
        cin >> input;

        if (rear != nullptr && input == rear->data) 
        {
            cout << "Совпадение с последним элементом. Удаление первого элемента.\n";

            enqueue(input, front, rear);  // Добавление нового элемента
            dequeue(front, rear);  // Удаление первого элемента
        }
        else 
        {
            enqueue(input, front, rear);
            maxSize--;
        }
    }

    cout << "Очередь после операций:\n";
    display(front);

    return 0;
}