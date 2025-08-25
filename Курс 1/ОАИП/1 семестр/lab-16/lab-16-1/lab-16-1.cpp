#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Функция вычитания предыдущей строки из каждой строки массива
void subtractPreviousRows(int **array, int n) 
{
    int *previousRow = new int[n];

    copy(array[n - 1], array[n - 1] + n, previousRow);

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            array[i][j] -= previousRow[j];
        }

        copy(array[i], array[i] + n, previousRow);
    }

    delete[] previousRow;
}

// Функция нахождения суммы чисел в строке
int sumOfNumbers(const string &str) 
{
    int sum = 0;

    istringstream iss(str);

    string word;

    while (iss >> word) 
    {
        if (isdigit(word[0])) 
        {
            sum += stoi(word);
        }
    }

    return sum;
}

int main() 
{
    setlocale(LC_ALL, "RU");

    int choice;

    cout << "Выберите программу:\n";

    cout << "1. Вычитание предыдущей строки из каждой строки массива.\n";

    cout << "2. Нахождение суммы чисел в строке.\n";

    cin >> choice;

    switch (choice) 
    {
        case 1: 
        {
            int n;

            cout << "Введите размерность массива: ";

            cin >> n;

            int **array = new int *[n];

            for (int i = 0; i < n; ++i) 
            {
                array[i] = new int[n];
            }

            cout << "Введите элементы массива:\n";

            for (int i = 0; i < n; ++i) 
            {
                for (int j = 0; j < n; ++j) 
                {
                    cin >> array[i][j];
                }
            }

            subtractPreviousRows(array, n);

            cout << "Результат:\n";

            for (int i = 0; i < n; ++i) 
            {
                for (int j = 0; j < n; ++j) 
                {
                    cout << array[i][j] << " ";
                }

                cout << "\n";
            }

            // Освобождаем выделенную память
            for (int i = 0; i < n; ++i) 
            {
                delete[] array[i];
            }

            delete[] array;

            break;
        }

        case 2: 
        {
            cin.ignore();

            string inputString;

            cout << "Введите строку (в начале и в конце поставтьте пробел): ";

            getline(cin, inputString);

            int sum = sumOfNumbers(inputString);

            cout << "Сумма чисел: " << sum << "\n";

            break;
        }

        default:
            cout << "Неправильный выбор.\n";

            break;
    }

    return 0;
}