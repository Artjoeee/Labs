#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Прототипы
void writeText(const string& data, const string& filename);
string readOddNumbers(const string& filename);

// Функция для записи строки в файл
void writeText(const string& data, const string& filename)
{
    ofstream outFile(filename); 

    if (!outFile.is_open())
    {
        cerr << "Ошибка открытия файла." << endl;
        exit(1);
    }

    outFile << data; // Записываем данные в файл

    outFile.close();
}

// Функция для чтения данных из файла
string readOddNumbers(const string& filename)
{
    ifstream inFile(filename); // Открываем файл для чтения

    if (!inFile.is_open())
    {
        cerr << "Ошибка открытия файла." << endl;
        exit(1);
    }

    string data;

    getline(inFile, data); // Читаем строку из файла

    string result = "";
    string number;

    istringstream iss(data); // Создаем поток для чтения данных

    // Читаем числа из строки и проверяем на четность
    while (iss >> number) 
    {
        // Проверяем, содержит ли слово только цифры
        if (number.find_first_not_of("0123456789") == string::npos) 
        {
            int num = stoi(number);

            if (num % 2 != 0) 
            {
                result += number + " "; // Добавляем нечетное число к результату
            }
        }
    }

    inFile.close();

    return result;
}

int main()
{
    setlocale(0, "ru");

    string input;

    cout << "Введите строку символов: ";
    getline(cin, input);

    writeText(input, "file.txt"); // Записываем введенную строку в файл

    string oddNumbers = readOddNumbers("file.txt"); // Читаем нечетные числа из файла

    if (!oddNumbers.empty())
    {
        cout << "Нечетные числа строки: " << oddNumbers << endl;
    }
    else
    {
        cout << "В строке нет нечетных чисел." << endl;
    }

    return 0;
}