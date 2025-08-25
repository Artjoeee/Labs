#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int arrayA[] = {1, 2, 3, 4, 5}, arrayB[] = {4, 6, 7, 8, 9};
    int n = sizeof(arrayA) / sizeof(arrayA[0]);
    int m = sizeof(arrayB) / sizeof(arrayB[0]);

	cout << "������ A: ";

	for (int i = 0; i < n; i++)
	{
		cout << arrayA[i] << " ";
	}

	cout << "\n";

	cout << "������ B: ";

	for (int i = 0; i < m; i++)
	{
		cout << arrayB[i] << " ";
	}

    cout << "\n";

    // ������� ���������� ������� � ������� A
    int maxA = *arrayA;  // ������ ������� ������� A

    for (int i = 1; i < n; ++i) 
    {
        if (*(arrayA + i) > maxA) 
        {
            maxA = *(arrayA + i);
        }
    }

    // ���������, ���������� �� ���������� ������� ������� A � ������� B
    bool containsMax = false;

    for (int j = 0; j < m; ++j) 
    {
        if (*(arrayB + j) == maxA) 
        {
            containsMax = true;  // ������� ����������
            break;
        }
    }

    // ������� ���������
    if (containsMax) 
    {
        cout << "���������� ������� ������� A ���������� � ������� B.\n";
    }
    else 
    {
        cout << "���������� ������� ������� A �� ���������� � ������� B.\n";
    }

    return 0;
}