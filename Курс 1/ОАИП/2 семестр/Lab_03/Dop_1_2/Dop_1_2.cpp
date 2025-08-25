#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

// Прототипы
void writeTextToFile(const string& text);
string findShortestGroup(const string& file);

// Функция для записи строки в файл
void writeTextToFile(const string& text)
{
    ofstream outFile("file.txt");

    if (!outFile.is_open())
    {
        cerr << "Не удалось открыть файл для записи." << endl;

        exit(1); // Завершить программу с кодом ошибки 1
    }

    outFile << text; // Записать строку в файл

    outFile.close(); // Закрыть файл
}

// Функция для поиска самой короткой группы в файле
string findShortestGroup(const string& file)
{
    ifstream inFile(file);

    if (!inFile.is_open())
    {
        cerr << "Не удалось открыть файл для чтения." << endl;

        exit(1); // Завершить программу с кодом ошибки 1
    }

    string line;
    string shortestGroup;

    int minLength = INT_MAX; // Инициализируем длину самой короткой группы значением INT_MAX
    
    while (inFile >> line) // Чтение строки из файла
    {
        int currentLength = 0; // Длина текущей группы

        string currentGroup;

        istringstream iss(line); // Создание потока для разбора строки

        char currentChar;

        while (iss >> currentChar) // Читаем данные по одному символу из файла
        {
            if (currentChar == '0' || currentChar == '1') 
            {
                currentLength++;
                currentGroup += currentChar;
            }
            else
            {
                if (currentLength < minLength && !currentGroup.empty())
                {
                    minLength = currentLength;
                    shortestGroup = currentGroup;
                }

                currentLength = 0;
                currentGroup = "";
            }
        }

        if (currentLength < minLength && !currentGroup.empty())
        {
            minLength = currentLength;
            shortestGroup = currentGroup;
        }
    }

    inFile.close(); // Закрыть файл

    return shortestGroup;
}

int main()
{
    setlocale(0, "ru");

    string inputString;

    cout << "Введите строку из групп цифр и нулей: ";
    getline(cin, inputString);

    writeTextToFile(inputString); // Записать строку в файл

    string shortestGroup = findShortestGroup("file.txt"); // Найти самую короткую группу в файле

    cout << "Самая короткая группа: " << shortestGroup << endl; 

    return 0;
}