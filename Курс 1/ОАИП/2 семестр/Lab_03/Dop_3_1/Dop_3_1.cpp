#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
    setlocale(0, "ru");

    // Открываем файлы
    ifstream inFile("FILE1.txt");
    ofstream outFile("FILE2.txt");

    // Проверяем удалось ли открыть файл
    if (!inFile.is_open() || !outFile.is_open())
    {
        cerr << "Ошибка открытия файлов." << endl;
        exit(1);
    }

    string line;
    int lineCount = 0;
  
    while (getline(inFile, line)) // Читаем каждую строку из FILE1
    {
        lineCount++;

        if (lineCount % 2 == 0) // Проверяем четность строки
        {
            outFile << line << endl;
        }
    }

    // Закрытие файлов
    inFile.close();
    outFile.close();

    // Подсчет размера файлов
    ifstream inFile2("FILE1.txt", ios::binary | ios::ate);
    ifstream outFile2("FILE2.txt", ios::binary | ios::ate);

    cout << "Размер файла FILE1 в байтах: " << inFile2.tellg() << endl;
    cout << "Размер файла FILE2 в байтах: " << outFile2.tellg() << endl;

    return 0;
}