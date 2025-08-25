#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int a;

    cout << "Введите число A: ";

    cin >> a;

    if ((a & 3) == 0) 
    {
        cout << "Число A кратно 4\n";
    }
    else 
    {
        cout << "Число A не кратно 4\n";
    }

    return 0;
}
