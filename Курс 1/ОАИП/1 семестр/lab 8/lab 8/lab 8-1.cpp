#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	double k = 6, sum = 0, a, f, g;

	for (int i = 1; i <= 5; i++)
	{
		cout << "Введите a" << i << ": ";
		cin >> a;

		sum += a / i; // Нахождение суммы

	}
	
	while (k < 7.2)
	{
		f = k;

		g = f / sum;

		cout << "" << endl;
		cout << "k = " << k << endl;
		cout << "g = " << g << endl;

		k += 0.2;
	}

	return 0;
}
