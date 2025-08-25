#include <iostream>

using namespace std;

int main()
{
	double a = 1.25, b = 2.5, e = 0.0001, x{};

	while (abs(a - b) > (2 * e))
	{
		x = (a + b) / 2;

		if ((exp(x) - 3 - (1 / x)) * (exp(a) - 3 - (1 / a)) <= 0) 
		{
			b = x;
		}

		else
		{
			a = x;
		}
	}

	cout << "x = " << x << endl;

	return 0;
}