#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int a, b, c;

	cout << "Введите a: ";
	cin >> a;

	cout << "Введите b: ";
	cin >> b;

	cout << "Введите c: ";
	cin >> c;
	cout << "" << endl;

	if (a % 2 == 0 && b % 2 == 0)
	{
		cout << "Есть два чётных числа" << endl;
	}

	else if (a % 2 == 0 && c % 2 == 0)
	{
		cout << "Есть два чётных числа" << endl;
	}

	else if (b % 2 == 0 && c % 2 == 0)
	{
		cout << "Есть два чётных числа" << endl;
	}

	else
	{
		cout << "Двух чётных чисел нет" << endl;
	}

		return 0;
}