#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    int c = 0; // �������� ������ ����������

    for (int i = 0; i <= 2; i++)  // 50 ���
    {
        for (int j = 0; j <= 5; j++) // 20 ���
        {
            for (int k = 0; k <= 20; k++) // 5 ���
            {
                for (int l = 0; l <= 50; l++) // 2 ���
                {
                    if (i * 50 + j * 20 + k * 5 + l * 2 == 100) 
                    {
                        c++; // ����������� ������� ������
                    }
                }
            }
        }
    }

    cout << "���������� �������� ������: " << c << endl;

    return 0;
}
