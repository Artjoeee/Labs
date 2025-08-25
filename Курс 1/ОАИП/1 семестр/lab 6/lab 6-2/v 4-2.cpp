#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    double b = 2.5, a = 1.4e-3, j = 2.5, m = 3, y, z;

    while (j < 3.1)
    {             
        y = (m * j) / tan(a) - exp(10 * m);
        z = 2 * y * b + sqrt(a + b);

        cout << "j = " << j << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl << endl;

        j = j + 0.1;
    }

    return 0;
}