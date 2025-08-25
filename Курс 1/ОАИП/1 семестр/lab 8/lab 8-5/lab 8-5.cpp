#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	double sum = 0, d = 12.5e-4, a, h;
	int n = 5;

	for (int i = 1; i <= n; i++)
	{
		cout << "Введите a" << i << ": ";
		cin >> a;

		sum += pow(a, 2); // Нахождение суммы
	}

	h = d + sum;

	cout << "" << endl;
	cout << "h = " << h << endl;

	return 0;
}