#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int a;

    cout << "������� ����� A: ";

    cin >> a;

    if ((a & 3) == 0) 
    {
        cout << "����� A ������ 4\n";
    }
    else 
    {
        cout << "����� A �� ������ 4\n";
    }

    return 0;
}
