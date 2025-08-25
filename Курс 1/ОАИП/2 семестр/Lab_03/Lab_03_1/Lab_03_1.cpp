#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

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

    
    string line;  // Функция для копирования строк без цифр из одного файла в другой

    int count = 0;

    while (getline(file1, line))  // Проверка на содержание цифр
    {
        bool hasDigit = false;

        for (char c : line) // Проверка каждого символа в строке
        {
            if (isdigit(c)) 
            {
                hasDigit = true;

                break;
            }
        }
        
        if (!hasDigit) // Если строка не содержит цифр, копируем ее в файл FILE2
        {
            file2 << line << endl;

            if (!line.empty() && toupper(line[0]) == 'A') // Подсчет строк, начинающихся на букву 'A'
            {
                count++;
            }
        }
    }

    //Закрытие файлов
    file1.close();
    file2.close();

    cout << "Количество строк, начинающихся на букву 'A' в файле FILE2: " << count << endl;

    return 0;
}