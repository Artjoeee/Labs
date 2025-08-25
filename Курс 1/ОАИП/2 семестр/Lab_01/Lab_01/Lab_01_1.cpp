#include <iostream>

using namespace std;

// ���������
double func1(double);
double func2(double);
double dychotomy(double (*)(double), double, double, double);

double func1(double x) // ����������� ������� ��������� x^3 + 2x - 1
{
    return pow(x,3) + 2 * x - 1;
}

double func2(double x) // ����������� ������� ��������� e^x - 2
{
    return exp(x) - 2;
}

double dychotomy(double (*func)(double), double a, double b, double e) // ����������� ������� ���������� ������ ������� ��������� 
{
    if (func(a) * func(b) >= 0) // �������� ��������
    {
        cout << "����������� ������� ��������� ��������" << endl;

        return -1;  // ���������� -1, ���� �������� ������ �������
    }

    double c{};

    while (abs(a - b) > 2 * e)  // ����� ��������� ��� ���������� ����� ���������
    {
        c = (a + b) / 2;

        if (func(c) == 0) 
        {
            break;  // ������ ������ ������
        }
        else if (func(c) * func(a) <= 0) 
        {
            b = c;
        }
        else 
        {
            a = c;
        }
    }

    return c;   // ���������� ��������� ������
}

int main() 
{
    setlocale(0, "ru");

    double e = 0.001;
    double a1, b1, a2, b2;
    double r1, r2;

    cout << "������� ��������� ��� ��������� x^3 + 2x - 1 (a, b): ";
    cin >> a1 >> b1;

    cout << "������� ��������� ��� ��������� e^x - 2 (a, b): ";
    cin >> a2 >> b2;
   
    r1 = dychotomy(func1, a1, b1, e); // ������� ������ ��� ��������� x^3 + 2x - 1

    cout << "������ ��������� x^3 + 2x - 1: " << r1 << endl;

    r2 = dychotomy(func2, a2, b2, e);  // ������� ������ ��� ��������� e^x - 2

    cout << "������ ��������� e^x - 2: " << r2 << endl;

    return 0;
}