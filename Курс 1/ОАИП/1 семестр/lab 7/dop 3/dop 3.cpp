#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    double c1, c2;
    int a = 0; // Переливания изначально 

    cout << "Объём воды в первом сосуде: ";
    cin >> c1;

    cout << "Объём воды во втором сосуде: ";
    cin >> c2;

    do
    {
        c1 /= 2;
        c2 += c1; // 1-ое переливание

        c2 /= 2;
        c1 += c2; // 2-ое переливание

        a++;

    } while (a != 6);

    cout << "Объём воды в первом сосуде после переливаний: " << c1 << endl;
    cout << "Объём воды во втором сосуде после переливаний: " << c2 << endl;

    return 0;
}