#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int const N = 100;
    int n;

    cout << "¬ведите размер массива: ";
    cin >> n;

    int arr[2 * N + 1]{};

    srand((unsigned)time(NULL));

    cout << "Ёлементы массива: ";
    for (int i = 0; i < 2 * n + 1; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    int middle = arr[n];

    cout << "—редний элемент: " << middle << endl;

    return 0;
}