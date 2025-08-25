#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int arrayA[] = {1, 2, 3, 4, 5}, arrayB[] = {4, 6, 7, 8, 9};
    int n = sizeof(arrayA) / sizeof(arrayA[0]);
    int m = sizeof(arrayB) / sizeof(arrayB[0]);

	cout << "Массив A: ";

	for (int i = 0; i < n; i++)
	{
		cout << arrayA[i] << " ";
	}

	cout << "\n";

	cout << "Массив B: ";

	for (int i = 0; i < m; i++)
	{
		cout << arrayB[i] << " ";
	}

    cout << "\n";

    // Находим наибольший элемент в массиве A
    int maxA = *arrayA;  // Первый элемент массива A

    for (int i = 1; i < n; ++i) 
    {
        if (*(arrayA + i) > maxA) 
        {
            maxA = *(arrayA + i);
        }
    }

    // Проверяем, содержится ли наибольший элемент массива A в массиве B
    bool containsMax = false;

    for (int j = 0; j < m; ++j) 
    {
        if (*(arrayB + j) == maxA) 
        {
            containsMax = true;  // Найдено совпадение
            break;
        }
    }

    // Выводим результат
    if (containsMax) 
    {
        cout << "Наибольший элемент массива A содержится в массиве B.\n";
    }
    else 
    {
        cout << "Наибольший элемент массива A не содержится в массиве B.\n";
    }

    return 0;
}