#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s;
    int n;
    
    cout << "�������� ������� ������������� (1-4): ";

    cin >> n;
  
    switch (n)
    {
        case 1: puts("������� ������"); // ����������� ������� �������� ����� � ASCII ����� � ��������� � �������� ���������, ���� ������ ������ ���������� ��������

            cin >> s;

            if (s >= 'a' && s <= 'z')
            {
                int l, u, d;

                l = int(s);
                u = int(s - 32);
                d = u - l;

                cout << "������� �������� ����� � ASCII: " << d << endl;
            }

            else if (s >= 'A' && s <= 'Z')
            {
                int l, u, d;

                l = int(s + 32);
                u = int(s);
                d = u - l;

                cout << "������� �������� ����� � ASCII: " << d << endl;
            }

            else
            {
                cout << "������ ������, �� ���������� ��������� ������" << endl;
            }

            break;

        case 2: puts("������� ������"); // ����������� ������� �������� ����� � Windows-1251 ����� � ��������� � �������� ���������, ���� ������ ������ �������� ��������

            cin >> s;

            if (s >= '�' && s <= '�')
            {
                int l, u, d;

                l = int(s);
                u = int(s - 32);
                d = u - l;

                cout << "������� �������� ����� � Windows-1251: " << d << endl;
            }

            else if (s >= '�' && s <= '�')
            {
                int l, u, d;

                l = int(s + 32);
                u = int(s);
                d = u - l;

                cout << "������� �������� ����� � Windows-1251: " << d << endl;
            }

            else
            {
                cout << "������ ������, �� ���������� ������� ������" << endl;
            }

            break;

        case 3: puts("������� ������"); // ����� � ������� ���� �������, ���������������� ��������� �����

            cin >> s;

            if (s >= '0' && s <= '9')
            {
                int k;

                k = int(s);

                cout << "��� �������: " << k << endl;
            }

            else
            {
                cout << "������ ������, �� ���������� ������" << endl;
            }

            break;

        case 4: puts("����� ���������"); // ����� �� ���������

            break;

        default: puts("������� ������ ������� �������������");

            break;
    }
    
    return 0;
}