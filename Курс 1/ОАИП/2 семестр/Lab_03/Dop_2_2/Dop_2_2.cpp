#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

// Прототипы
void writeText(const string& str1, const string& str2);
void findWords(string& shortestWord, string& longestWord);

// Функция для записи строк в файл
void writeText(const string& str1, const string& str2)
{
    ofstream outFile("file.txt");

    // Проверяем удалось ли открыть файл
    if (!outFile.is_open())
    {
        cerr << "Не удалось открыть файл для записи." << endl;
        exit(1);
    }

    outFile << str1 << endl;
    outFile << str2 << endl;

    // Закрываем файл
    outFile.close();
}

// Функция для чтения строк из файла
void findWords(string& shortestWord, string& longestWord)
{
    ifstream inFile("file.txt");

    // Проверяем удалось ли открыть файл
    if (!inFile.is_open())
    {
        cerr << "Не удалось открыть файл для чтения." << endl;
        exit(1);
    }

    string line1, line2;

    // Читаем строки из файла
    if (getline(inFile, line1) && getline(inFile, line2))
    {
        // Находим самое короткое слово в первой строке
        istringstream iss1(line1);
        iss1 >> shortestWord;

        string word;
        while (iss1 >> word)
        {
            if (word.length() < shortestWord.length())
            {
                shortestWord = word;
            }
        }

        // Находим самое длинное слово во второй строке
        istringstream iss2(line2);
        iss2 >> longestWord;

        while (iss2 >> word)
        {
            if (word.length() > longestWord.length())
            {
                longestWord = word;
            }
        }
    }

    // Закрываем файл
    inFile.close();
}

int main()
{
    setlocale(0, "ru");

    string input1, input2;

    cout << "Введите первую строку: ";
    getline(cin, input1);

    cout << "Введите вторую строку: ";
    getline(cin, input2);

    // Запись строк в файл
    writeText(input1, input2); // Запись строк в файл

    string shortestWord, longestWord;

    // Чтение строк из файла и поиск самых короткого и длинного слова
    findWords(shortestWord, longestWord);

    cout << "Самое короткое слово в первой строке: " << shortestWord << endl;
    cout << "Самое длинное слово во второй строке: " << longestWord << endl;

    return 0;
}