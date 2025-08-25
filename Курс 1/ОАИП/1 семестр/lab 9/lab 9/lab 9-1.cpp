#include <iostream>

using namespace std;

int main()
{
	int n = 200;
	double a = 2, b = 3, x = a, h, s = 0;

	h = (b - a) / n;

	while (x <= (b - h))
	{
		s = s + h * ((exp(x) - 1 / x) + (exp(x + h) - 1 / (x + h))) / 2;
		x = x + h;
	}

	cout << "s = " << s << endl;

	return 0;
}