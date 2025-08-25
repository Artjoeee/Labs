#include <iostream>
#include "myStack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int choice;
    char x;

	Stack* myStk = new Stack;  // ��������� ������ ��� �����

	myStk = NULL;  // ������������� ������� ��������	

    for (;;)
    {
        cout << "�������� �������:" << endl;
        cout << "1 - ���������� �������� � ����" << endl;
        cout << "2 - ���������� �������� �� �����" << endl;
        cout << "3 - ������ � ����" << endl;
        cout << "4 - ������ �� �����" << endl;
        cout << "5 - ����� �����" << endl;
        cout << "6 - ������� �����" << endl;
        cout << "7 - �������� ������� �������� ������� ����������" << endl;
        cout << "0 - �����" << endl;

        cout << "\n��� �����: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n������� �������: ";
            cin >> x;

            cout << endl;

            push(x, myStk);

            break;
        case 2:
            cout << "\n����������� �������: " << pop(myStk) << endl << endl;

            break;
        case 3:
            toFile(myStk);

            break;
        case 4:
            fromFile(myStk);

            break;
        case 5:
            show(myStk);

            break;
        case 6:
            clear(myStk);

            break;
        case 7:
            if (hasEqualNextElement(myStk)) // true
            {
                cout << "\n� ����� ���� �������, ������ ���������� �� ���.\n" << endl;
            }
            else if (!hasEqualNextElement(myStk)) // false
            {
                cout << "\n� ����� ��� ���������, ������ ���������� �� ���.\n" << endl;
            }

            break;
        case 0:
            return 0;
        }
    }

	return 0;
}