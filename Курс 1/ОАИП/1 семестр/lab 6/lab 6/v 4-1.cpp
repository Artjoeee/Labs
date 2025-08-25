#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    double b = 2.5, a = 1.4e-3, m = 3, j, y, z;
    
    for (int i = 0; i < 3; i++) 
    {
        cout << "¬ведите j: ";
        cin >> j;

        y = (m * j) / (tan(a) - exp(10 * m));
        z = 2 * y * b + sqrt(a + b);

        cout << "y = " << y << endl;
        cout << "z = " << z << endl << endl;
    }

    return 0;
}

