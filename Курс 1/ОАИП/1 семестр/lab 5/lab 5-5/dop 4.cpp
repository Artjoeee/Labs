#include<iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    double r, p, q;

    cout << "¬ведите значение радиуса (r): ";
    cin >> r;

    cout << "¬ведите значение диагонали (p): ";
    cin >> p;

    cout << "¬ведите значение диагонали (q): ";
    cin >> q;

    if ((p * q) / (2 * sqrt(pow(p, 2) + pow(q, 2))) < r)
    {
        cout << "Ўар не пройдЄт!" << endl;
    }

    else
    {
        cout << "Ўар пройдЄт!" << endl;
    }

    return 0;
}