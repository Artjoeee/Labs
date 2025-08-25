#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//Прототипы
void writeText(const string& text);
int findLongestWord(const string& file);

void writeText(const string& text)  // Функция для записи текста в файл
{
    ofstream outFile("file.txt");

    if (!outFile.is_open()) 
    {
        cerr << "Не удалось открыть файл для записи." << endl;

        exit(1);  // Завершить программу с кодом ошибки 1
    }

    outFile << text;  // Записать текст в файл

    outFile.close();  // Закрыть файл
}

int findLongestWord(const string& file)  // Функция для поиска длины самого длинного слова в файле
{
    ifstream inFile(file);

    if (!inFile.is_open()) 
    {
        cerr << "Не удалось открыть файл для чтения." << endl;

        exit(1);  // Завершить программу с кодом ошибки 1
    }

    string line;

    string word;

    int maxLength = 0;

    while (inFile >> line)  // Чтение из файла по словам и нахождение самого длинного слова
    {
        istringstream iss(line);  // Создание потока для разбора строки на слова

        while (iss >> word) 
        {
            int length = word.length();  // Длина текущего слова

            if (length > maxLength) 
            {
                maxLength = length;
            }
        }
    }

    inFile.close();  // Закрыть файл

    return maxLength;
}

int main() 
{
    setlocale(0, "ru");

    string inputString;

    cout << "Введите строку: ";

    getline(cin, inputString);  // Считать строку от пользователя

    writeText(inputString);  // Записать введенную строку в файл

    int maxLength = findLongestWord("file.txt"); 
    
    cout << "Самое длинное слово содержит " << maxLength << " символов." << endl;
    
    return 0;
}