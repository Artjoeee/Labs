#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    setlocale(0, "ru");

    // Открытие файлов
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");

    if (!file1.is_open() || !file2.is_open())  // Проверяем, удалось ли открыть файлы
    {
        cerr << "Не удалось открыть файлы." << endl;

        exit(1);  // Завершить программу с кодом ошибки 1
    }

    string line;  // Функция для копирования строк из одного файла в другой

    string word;

    int count = 0;

    while (getline(file1, line))
    {       
        if (!line.empty() && toupper(line[0]) == 'A') // Проверка строк, начинающихся на букву 'A'
        {
            file2 << line << endl;

            istringstream iss(line);  // Создание потока для разбора строки на слова

            while (iss >> word)
            {
                count++;
            }
        }  
    }

    //Закрытие файлов
    file1.close();
    file2.close();

    cout << "Количество слов в файле FILE2: " << count << endl;

    return 0;
}