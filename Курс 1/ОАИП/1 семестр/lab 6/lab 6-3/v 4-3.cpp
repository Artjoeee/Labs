#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	double b = 2.5, a = 1.4e-3, j, m, y, z;

	for (int i = 0; i < 3; i++)
	{
		cout << "¬ведите m: ";
		cin >> m;
		cout << "" << endl;

		for (int k = 0; k < 4; k++)
		{
			cout << "¬ведите j: ";
			cin >> j;

			y = (m * j) / tan(a) - exp(10 * m);
			z = 2 * y * b + sqrt(a + b);

			cout << "y = " << y << endl;
			cout << "z = " << z << endl << endl;
		}
		
	}
	
	return 0;
}