#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    const int MAX_SIZE = 100;
    int matrix[MAX_SIZE][MAX_SIZE]{};
    int n, m;

    cout << "������� ���������� ����� �������: ";

    cin >> n;

    cout << "������� ���������� �������� �������: ";

    cin >> m;

    cout << "\n������� �������� �������:\n";

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\n�������:";

    for (int i = 0; i < n; i++)
    {
        cout << "\n";

        for (int j = 0; j < m; j++) 
        {
            cout << " " << matrix[i][j] << " ";
        }
    }
    
    cout << "\n\n";

    // ��������� ������� �������������� ���� ��������� �������
    int sum = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            sum += matrix[i][j];
        }
    }

    double average = static_cast<double>(sum) / (n * m);

    // ������� ���������� ��������� �������, ������� �������� ���������������
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

    cout << "���������� ��������� �������, ������� �������� ��������������� ("
        << average << "), �����: " << count << endl;

    return 0;
}