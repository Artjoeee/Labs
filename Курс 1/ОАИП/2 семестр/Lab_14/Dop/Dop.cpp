#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;  // Размер таблицы

struct HashNode 
{
    int key;
    HashNode* next;

    HashNode(int k) : key(k), next(nullptr) {}
};

// Класс хеш-таблицы
class HashTable 
{
public:
    
    HashTable();  // Конструктор
    ~HashTable();  // Диструктор

    // Прототипы методов
    void insert(int key);
    void print();
    bool search(int key);

private:
    
    HashNode** m_data;  // Массив хеш-таблицы

    // функция хеширования
    int hash(int key)
    {
        return key % TABLE_SIZE;
    }
};

// Конструктор
HashTable::HashTable() 
{
    m_data = new HashNode * [TABLE_SIZE];

    // Заполнение всех элементов таблицы пустыми ссылками
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        m_data[i] = nullptr;
    }
}

// Диструктор
HashTable::~HashTable() 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        HashNode* node = m_data[i];

        while (node != nullptr) 
        {
            HashNode* prev = node;

            node = node->next;

            delete prev;
        }
    }

    delete[] m_data;
}

// Метод вывода таблицы
void HashTable::print()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (m_data[i] != nullptr)
        {
            cout << m_data[i]->key << endl;
        }
    }
}

// Метод добавления элементов
void HashTable::insert(int key) 
{
    int index = hash(key);

    // Создание нового элемента по ключу
    HashNode* node = new HashNode(key);

    if (m_data[index] != nullptr) 
    {
        node->next = m_data[index];
    }

    m_data[index] = node;
}

// Метод поиска
bool HashTable::search(int key) 
{
    int index = hash(key);

    // Создание временной переменнной
    HashNode* node = m_data[index];

    // Проверка всех элементов списка
    while (node != nullptr) 
    {
        if (node->key == key)
        {
            return true;
        }
    }

    return false;
}

// Фукнция чтения чисел из файла
void readNumbers(const string& filename, HashTable& table) 
{
    ifstream file(filename);  // Открытие файла

    if (!file) 
    {
        cerr << "Ошибка открытия файла " << filename << endl;

        return;
    }

    int number;

    while (file >> number) 
    {
        table.insert(number);
    }

    file.close();  // Закрытие файла
}

int main()
{
    setlocale(0, "ru");

    string path = "file.txt";

    HashTable table;

    readNumbers(path, table);

    table.print();  // Вывод таблицы

    int num;

    cout << "Введите число: "; 
    cin >> num;

    if (table.search(num))
    {
        cout << "Элемент " << num << " найден" << endl;
    }
    else
    {
        cout << "Элемент " << num << " не найден" << endl;
    }

    return 0;
}