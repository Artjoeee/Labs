#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    const int MAX_SIZE = 100;
    int matrix[MAX_SIZE][MAX_SIZE]{};
    int n, m;

    cout << "Введите количество строк матрицы: ";

    cin >> n;

    cout << "Введите количество столбцов матрицы: ";

    cin >> m;

    cout << "\nВведите элементы матрицы:\n";

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nМатрица:";

    for (int i = 0; i < n; i++)
    {
        cout << "\n";

        for (int j = 0; j < m; j++) 
        {
            cout << " " << matrix[i][j] << " ";
        }
    }
    
    cout << "\n\n";

    // Вычисляем среднее арифметическое всех элементов матрицы
    int sum = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            sum += matrix[i][j];
        }
    }

    double average = static_cast<double>(sum) / (n * m);

    // Находим количество элементов матрицы, больших среднего арифметического
    int count = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (matrix[i][j] > average) 
            {
                count++;
            }
        }
    }

    cout << "Количество элементов матрицы, больших среднего арифметического ("
        << average << "), равно: " << count << endl;

    return 0;
}