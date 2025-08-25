#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

const int TABLE_SIZE = 16; // Размер хэш-таблицы

struct Record 
{
    int phoneNumber;
    string ownerName;
};

class HashTable 
{
private:
    vector<list<Record>> table;

    int hashFunction(int key) 
    {
        return key % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(int phoneNumber, const string& ownerName) 
    {
        int index = hashFunction(phoneNumber);

        Record newRecord = { phoneNumber, ownerName };

        table[index].push_back(newRecord);
    }

    void remove(int phoneNumber) 
    {
        int index = hashFunction(phoneNumber);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) 
        {
            if (it->phoneNumber == phoneNumber) 
            {
                table[index].erase(it);

                break;
            }
        }
    }

    Record* search(int phoneNumber) 
    {
        int index = hashFunction(phoneNumber);

        for (auto& record : table[index]) 
        {
            if (record.phoneNumber == phoneNumber) 
            {
                return &record;
            }
        }

        return nullptr;
    }

    void display() 
    {
        for (int i = 0; i < TABLE_SIZE; ++i) 
        {
            cout << "Хэш " << i << ": ";

            for (auto& record : table[i]) 
            {
                cout << record.phoneNumber << " " << record.ownerName << " | ";
            }

            cout << endl;
        }
    }
};

int main() 
{
    setlocale(0, "ru");

    HashTable hashTable;

    hashTable.insert(1234567, "Иванов");
    hashTable.insert(9876543, "Петров");
    hashTable.insert(5558888, "Сидоров");

    cout << "Вывод всей таблицы:" << endl;
    hashTable.display();

    cout << "Поиск элементов:" << endl;
    Record* record = hashTable.search(1234567);

    if (record) 
    {
        cout << "Найден: " << record->phoneNumber << " " << record->ownerName << endl;
    }
    else 
    {
        cout << "Элемент не найден" << endl;
    }

    cout << "Удаление элемента:" << endl;
    hashTable.remove(9876543);

    cout << "Вывод всей таблицы после удаления:" << endl;
    hashTable.display();

    // Исследование времени поиска
    const int NUM_SEARCHES = 100000;
    vector<int> searchNumbers = { 1234567, 5558888 };

    auto start = high_resolution_clock::now();

    for (int i = 0; i < NUM_SEARCHES; ++i) 
    {
        for (int number : searchNumbers) 
        {
            hashTable.search(number);
        }
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << "Время поиска " << NUM_SEARCHES << " элементов: " << duration.count() << " мкс" << endl;

    return 0;
}