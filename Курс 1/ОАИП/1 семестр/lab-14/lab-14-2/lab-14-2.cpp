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

    cout << "������� �������� �������:\n";

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

    int count = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 1; j < m - 1; ++j) 
        {
            bool leftSmaller = true;
            bool rightGreater = true;

            int* curr = &matrix[i][j];

            // ��������� ����� ����� �� �������� ��������
            for (int k = 0; k < j; ++k) 
            {
                if (*(curr - k) <= *curr) 
                {
                    leftSmaller = false;                   
                }
            }

            // ��������� ����� ������ �� �������� ��������
            for (int k = 1; k < m - j; ++k) 
            {
                if (*(curr + k) <= *curr) 
                {
                    rightGreater = false;                  
                }
            }

            if (leftSmaller && rightGreater) 
            {
                count++;
            }
        }
    }

    cout << "���������� ��������� �������, � ������� � ������ ����� ��������� ����� �������, "
        << "� ������ � �������, �����: " << count << endl;

    return 0;
}