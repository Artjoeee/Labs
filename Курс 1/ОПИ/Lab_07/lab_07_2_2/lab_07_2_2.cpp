#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int N = 100;
    int size;

    cout << "Введите размер массива: ";

    cin >> size;

    int mas[N]{}, digits[N]{}, others[N]{};
    int digitsCount = 0, othersCount = 0;

    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) // заполнение исходного массива случайными числами от 0 до 99
    {
        mas[i] = rand() % 100;

        cout << mas[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < size; i++) // разделение на два новых массива
    {
        if (mas[i] >= 0 && mas[i] <= 9)
        {
            digits[digitsCount] = mas[i];
            digitsCount++;
        }

        else
        {
            others[othersCount] = mas[i];
            othersCount++;
        }
    }

    cout << "Цифры: ";

    for (int i = 0; i < digitsCount; i++) // вывод новых массивов
    {
        cout << digits[i] << " ";
    }

    cout << endl << endl;

    cout << "Остальные символы: ";

    for (int i = 0; i < othersCount; i++)
    {
        cout << others[i] << " ";
    }

    cout << endl;

    return 0;
}