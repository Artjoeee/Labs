#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int SIZE = 100;
    int  quantity, number, arr[SIZE]{};

    cout << "¬ведите количество элементов массива: ";

    cin >> quantity;

    srand((unsigned)time(NULL));

    for (int i = 1; i <= quantity; i++) // заполнение исходного массива случайными числами от 0 до 99
    {
        arr[i] = rand() % 100;

        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "¬ведите номер удал€емого элемента: ";

    cin >> number;

    for (int i = number; i < quantity - 1; i++) // удаление элемента k
    {
        arr[i] = arr[i + 1];
    }

    quantity--;

    for (int i = 1; i <= quantity; i++) // подстановка 0 после четных элементов массива
    {
        cout << arr[i] << " ";

        if (i % 2 == 0)
        {
            cout << "0 ";
        }
    }

    return 0;
}