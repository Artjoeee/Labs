#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArray(int *arr, int size) 
{
    srand(time(NULL));

    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 200 + 1;
    }
}

int sumOddElements(const int *arr, int size) 
{
    int sum = 0;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] % 2 != 0) 
        {
            sum += arr[i];
        }
    }

    return sum;
}

void printArray(const int *arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void changeSigns(int **matrix, int rows, int cols, int row) 
{
    for (int i = 0; i < cols; i++) 
    {
        matrix[row][i] *= -1;
    }
}

int findPositiveRow(const int **matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        bool hasPositive = false;

        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] > 0) 
            {
                hasPositive = true;

                break;
            }
        }

        if (hasPositive) 
        {
            return i;
        }
    }

    return -1;
}

int main() 
{
    setlocale(LC_ALL, "RU");

    int choice;

    cout << "Выберите программу: " << endl;

    cout << "1. Одномерный массив" << endl;

    cout << "2. Матрица" << endl;

    cin >> choice;

    switch (choice) 
    {
        case 1:
        {
            const int arraySize = 15;
            int *arr = new int[arraySize];

            fillArray(arr, arraySize);

            cout << "Сгенерированный массив: ";

            printArray(arr, arraySize);

            int sumOfOddElements = sumOddElements(arr, arraySize);

            cout << "Сумма нечетных элементов: " << sumOfOddElements << endl;

            delete[] arr;

            break;
        }
        case 2:
        {
            int rows, cols;

            cout << "Введите количество строк и столбцов: ";

            cin >> rows >> cols;

            int **matrix = new int *[rows];

            for (int i = 0; i < rows; i++) 
            {
                matrix[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++) 
            {
                cout << "Введите элементы " << i << "-й строки: ";

                for (int j = 0; j < cols; j++) 
                {
                    cin >> matrix[i][j];
                }
            }

            int positiveRow = findPositiveRow((const int**)matrix, rows, cols);

            if (positiveRow != -1) 
            {
                cout << "В матрице есть строка с положительным элементом." << endl;

                cout << "Номер строки: " << positiveRow << endl;
            }
            else 
            {
                cout << "В матрице нет строк с положительными элементами." << endl;
            }

            if (positiveRow > 0) 
            {
                changeSigns(matrix, rows, cols, positiveRow - 1);

                cout << "Знаки элементов предыдущей строки изменены на противоположные." << endl;

                cout << "Обновленная матрица:" << endl;

                for (int i = 0; i < rows; i++) 
                {
                    for (int j = 0; j < cols; j++) 
                    {
                        cout << matrix[i][j] << " ";
                    }

                    cout << endl;
                }
            }

            for (int i = 0; i < rows; i++) 
            {
                delete[] matrix[i];
            }

            delete[] matrix;

            break;
        }

        default:
            cout << "Неверный выбор программы." << endl;

            break;
    }

    return 0;
}