#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    const int N = 100;
    int n, k, mas[N]{};

    cout << "¬ведите количество элементов массива: ";
    cin >> n;

    srand((unsigned)time(NULL));

    for (int i = 1; i <= n; i++) // заполнение исходного массива случайными числами от 0 до 99
    {
        mas[i] = rand() % 100;
        cout << mas[i] << " ";
    }
    cout << endl;

    cout << "¬ведите номер удал€емого элемента: ";
    cin >> k;

    for (int i = k; i < n - 1; i++) // удаление элемента k
    {
        mas[i] = mas[i + 1];
    }
    n--;

    for (int i = 1; i <= n; i++) // подстановка 0 после четных элементов массива
    {
        cout << mas[i] << " ";
        if (i % 2 == 0) 
        {
            cout << "0 ";
        }
    }

    return 0;
}