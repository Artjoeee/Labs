#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	double y = 2.7, a = -5.5e-4, j, x, z;

	cout << "¬ведите j: ";
	cin >> j;

	x = pow(cos(y), 2) / (j + 2 * a * y);

	if (x >= sqrt(y))
	{
		z = exp(-j);
	}
	else
	{
		z = pow(0.5 * y / j, 2);
	}

	cout << "y = " << x << endl;
	cout << "z = " << z << endl;

	return 0;
}