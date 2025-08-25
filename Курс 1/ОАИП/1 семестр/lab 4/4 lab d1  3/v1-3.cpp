#include <iostream>
using namespace std;


int main() 
{
    setlocale(LC_ALL, "RU");

    double d;

    cout << "¬ведите длину диагонали: ";
    cin >> d;
    
    double a = d / sqrt(2);
    double s = a * a;

    cout << "ѕлощадь квадрата равна: " << s << endl;

    return 0;

}
