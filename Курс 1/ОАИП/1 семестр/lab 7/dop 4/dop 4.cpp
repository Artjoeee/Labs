#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    for (int i = 1000; i <= 9999; i++)  // �������������� ����� 
    {
        if (i % 2 == 0 && i % 7 == 0 && i % 11 == 0)    // �������� �� �������
        {
            int sum = 0;    // ����� ���� ���������� 
            int t = i;     // ����� ����� ������

            while (t > 0) 
            {
                sum += t % 10;  // ����������� ������� �� ������� �� 10
                t /= 10;      // ������� ����� �� 10
            }

            if (sum == 30) 
            {
                cout << "����� ������: " << i << endl;
                break;
            }
        }
    }

    return 0;
}
