#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    double d;
    double n;

    cout << "¬ведите начальную цену: ";
    cin >> d;
    cout << "¬ведите количество лет: ";
    cin >> n;

    double a = d + d * 0.15;
    double s = a - a * 0.15;
    double g = (s - d) * n;

    cout << "»зменение цены за указанное количество лет: " << g << endl;

    return 0;

}
