#include <iostream>

using namespace std;

int countColumnsWithoutZeros(int **matrix, int rows, int columns) 
{
    int count = 0;

    for (int j = 0; j < columns; ++j) 
    {
        bool hasZero = false;

        for (int i = 0; i < rows; ++i) 
        {
            if (matrix[i][j] == 0) 
            {
                hasZero = true;

                break;
            }
        }
        if (!hasZero) 
        {
            count++;
        }
    }

    return count;
}

int main() 
{
    setlocale(LC_ALL, "RU");

    int rows, columns;

    cout << "������� ���������� �����: ";

    cin >> rows;

    cout << "������� ���������� ��������: ";

    cin >> columns;

    int **matrix = new int *[rows];

    for (int i = 0; i < rows; ++i) 
    {
        matrix[i] = new int[columns];
    }

    cout << "������� �������� �������:\n";

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\n�������:";

    for (int i = 0; i < rows; i++)
    {
        cout << "\n";

        for (int j = 0; j < columns; j++)
        {
            cout << " " << matrix[i][j] << " ";
        }
    }

    int count = countColumnsWithoutZeros(matrix, rows, columns);

    cout << "\n\n���������� �������� ��� �����: " << count << endl;

    for (int i = 0; i < rows; ++i) 
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}