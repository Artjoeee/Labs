#include <iostream>
#include <vector>

using namespace std;

// Создаем класс BinaryHeap
template<typename T>
class BinaryHeap
{
private:
    template<typename T>
    class Node
    {
    public:
        T data;
        int key;
        int level;  // Новое поле для хранения уровня узла

        Node(T data, int key, int level)
        {
            this->data = data;
            this->key = key;
            this->level = level;
        }
    };

    Node<T>** heapArray;  // Массив для хранения элементов кучи

    int capacity;  // Максимальная вместимость кучи
    int size;  // Текущий размер кучи

public:
    BinaryHeap(int capacity);
    ~BinaryHeap();

    void insert(T data, int key);
    void print();
};

template<typename T>
BinaryHeap<T>::BinaryHeap(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->heapArray = new Node<T>*[capacity];  // Выделение памяти для массива кучи
}

template<typename T>
BinaryHeap<T>::~BinaryHeap()
{
    delete[] heapArray;  // Освобождение памяти, занятой массивом кучи
}

template<typename T>
void BinaryHeap<T>::insert(T data, int key)
{
    if (size >= capacity)
    {
        cout << "Куча заполнена!" << endl;

        return;
    }

    int level = 0;

    if (size > 0)
    {
        level = heapArray[(size - 1) / 2]->level + 1;  // Вычисление уровня нового узла
    }

    Node<T>* newNode = new Node<T>(data, key, level);  // Создание нового узла

    heapArray[size] = newNode;  // Добавление узла в массив кучи

    int current = size;
    int parent = (current - 1) / 2;

    // Восстановление свойств кучи: перемещение нового узла вверх по дереву
    while (current > 0 && heapArray[parent]->key < newNode->key)
    {
        heapArray[current] = heapArray[parent];
        current = parent;
        parent = (parent - 1) / 2;
    }

    heapArray[current] = newNode;
    size++;
}

template<typename T>
void BinaryHeap<T>::print()
{
    vector<vector<Node<T>*>> levels;  // Вектор уровней

    for (int i = 0; i < size; i++)
    {
        int level = heapArray[i]->level;

        if (level >= levels.size())
        {
            levels.resize(level + 1);  // Если уровень еще не существует, добавляем его
        }

        levels[level].push_back(heapArray[i]);  // Добавляем узел в соответствующий уровень
    }

    // Вывод уровней по порядку
    for (int i = 0; i < levels.size(); i++)
    {
        for (int j = 0; j < levels[i].size(); j++)
        {
            if (i == 0)
            {
                cout << "Корень: " << "Ключ: " << levels[i][j]->key << ", Значение: " << levels[i][j]->data << endl;
            }
            else
            {
                cout << "Уровень: " << i << ", Ключ: " << levels[i][j]->key << ", Значение: " << levels[i][j]->data << endl;
            }
        }
    }
}

void getHeap()
{
    BinaryHeap<int> heap(10);

    heap.insert(19, 5);
    heap.insert(21, 10);
    heap.insert(17, 15);
    heap.insert(23, 20);
    heap.insert(15, 25);
    heap.insert(25, 30);
    heap.insert(13, 35);
    heap.insert(27, 40);
    heap.insert(11, 45);

    heap.print();
}

int main()
{
    setlocale(0, "ru");

    getHeap();

    return 0;
}