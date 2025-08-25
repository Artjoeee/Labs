#include "case.h"
#include <iostream>

using namespace std;

int c = 0;

int case1()
{
	int n = 200;
	double a = 1, b = 3, x = a, h, s = 0;

	h = (b - a) / n;

	while (x <= (b - h))
	{
		s = s + h * ((pow(x, 3) - 3) + (pow(x + h, 3) - 3)) / 2;
		x = x + h;
	}

	cout << "s = " << s << endl;

    return c;
}

int case2()
{
	int n = 200, i = 1;
	double a = 1, b = 3, x, h, s1 = 0, s2 = 0, s;

	h = (b - a) / (2 * n);
	x = a + 2 * h;

	while (i < n)
	{
		s2 = s2 + (pow(x, 3) - 3);
		x = x + h;
		s1 = s1 + (pow(x, 3) - 3);
		x = x + h;
		i = i + 1;
	}

	s = (h / 3) * ((pow(a, 3) - 3) + 4 * (pow(a + h, 3) - 3) + 4 * s1 + 2 * s2 + (pow(b, 3) - 3));

	cout << "s = " << s << endl;

    return c;
}

int case3()
{
	double a = 1, b = 1.25, e = 0.0001, x{};

	while (abs(a - b) > (2 * e))
	{
		x = (a + b) / 2;

		if ((pow(x, 3) + x - 3) * (pow(a, 3) + a - 3) <= 0)
		{
			b = x;
		}

		else
		{
			a = x;
		}
	}

	cout << "x = " << x << endl;

    return c;
}
