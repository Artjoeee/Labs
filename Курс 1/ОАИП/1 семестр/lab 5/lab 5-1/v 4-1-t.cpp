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

	a % 2 == 0 && b % 2 == 0 ? cout << "Есть два чётных числа" << endl : a % 2 == 0 && c % 2 == 0 ? cout << "Есть два чётных числа" << endl : b % 2 == 0 && c % 2 == 0 ? cout << "Есть два чётных числа" << endl : cout << "Двух чётных чисел нет" << endl;

	return 0;
}