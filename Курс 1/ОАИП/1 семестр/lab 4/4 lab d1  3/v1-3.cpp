#include <iostream>
using namespace std;


int main() 
{
    setlocale(LC_ALL, "RU");

    double d;

    cout << "������� ����� ���������: ";
    cin >> d;
    
    double a = d / sqrt(2);
    double s = a * a;

    cout << "������� �������� �����: " << s << endl;

    return 0;

}
