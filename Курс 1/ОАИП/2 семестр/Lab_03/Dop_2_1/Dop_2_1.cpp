#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    setlocale(0, "ru");

    // Открытие файлов
    ifstream inFile("FILE1.txt");
    ofstream outFile("FILE2.txt");

    if (!inFile.is_open() || !outFile.is_open()) // Проверяем, удалось ли открыть файлы
    {
        cerr << "Не удалось открыть файлы." << endl;

        exit(1); // Завершаем программу с ошибкой
    }

    string line; // Переменная для хранения строки из файла
    int charCount = 0;
  
    while (getline(inFile, line)) // Читаем файл по строкам
    {
        bool oneWord = true;
       
        for (char c : line) // Проверяем каждый символ в строке
        {
            if (c == ' ') // Если найден пробел, значит это не одно слово
            {
                oneWord = false;
                break;
            }
        }

        // Если строка состоит из одного слова, записываем ее в выходной файл
        if (oneWord)
        {
            outFile << line << endl;
            charCount += line.length(); // Увеличиваем общее количество символов
        }
    }

    cout << "Количество символов в FILE2: " << charCount << endl;

    // Закрытие файлов
    inFile.close();
    outFile.close();

    return 0;
}