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

	a % 2 == 0 && b % 2 == 0 ? cout << "���� ��� ������ �����" << endl : a % 2 == 0 && c % 2 == 0 ? cout << "���� ��� ������ �����" << endl : b % 2 == 0 && c % 2 == 0 ? cout << "���� ��� ������ �����" << endl : cout << "���� ������ ����� ���" << endl;

	return 0;
}