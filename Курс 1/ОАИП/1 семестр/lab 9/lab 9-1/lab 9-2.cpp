#include <iostream>

using namespace std;

int main()
{
	int n = 200, i = 1;
	double a = 2, b = 3, x, h, s1 = 0, s2 = 0, s;

	h = (b - a) / (2 * n);
	x = a + 2 * h;

	while (i < n)
	{
		s2 = s2 + (exp(x) - 1 / x);
		x = x + h;
		s1 = s1 + (exp(x) - 1 / x);
		x = x + h;
		i = i + 1;
	}

	s = (h / 3) * ((exp(a) - 1 / a) + 4 * (exp(a + h) - 1 / (a + h)) + 4 * s1 + 2 * s2 + (exp(b) - 1 / b));

	cout << "s = " << s << endl;

	return 0;
}