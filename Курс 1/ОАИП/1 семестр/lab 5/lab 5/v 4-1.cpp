#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int a, b, c;

	cout << "������� a: ";
	cin >> a;

	cout << "������� b: ";
	cin >> b;

	cout << "������� c: ";
	cin >> c;
	cout << "" << endl;

	if (a % 2 == 0 && b % 2 == 0)
	{
		cout << "���� ��� ������ �����" << endl;
	}

	else if (a % 2 == 0 && c % 2 == 0)
	{
		cout << "���� ��� ������ �����" << endl;
	}

	else if (b % 2 == 0 && c % 2 == 0)
	{
		cout << "���� ��� ������ �����" << endl;
	}

	else
	{
		cout << "���� ������ ����� ���" << endl;
	}

		return 0;
}