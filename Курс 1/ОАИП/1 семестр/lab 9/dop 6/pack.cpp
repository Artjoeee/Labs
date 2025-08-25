#include "pack.h"
#include <iostream>

int c = 0;

using namespace std;

int pack1()
{
	int n = 200;
	double a = 1, b = 5, x = a, h, s = 0;

	h = (b - a) / n;

	while (x <= (b - h))
	{
		s = s + h * ((1 + pow(x, 3)) + (1 + pow(x + h, 3))) / 2;
		x = x + h;
	}

	cout << "s = " << s << endl;

    return c;
}

int pack2()
{
	int n = 200, i = 1;
	double a = 1, b = 5, x, h, s1 = 0, s2 = 0, s;

	h = (b - a) / (2 * n);
	x = a + 2 * h;

	while (i < n)
	{
		s2 = s2 + (1 + pow(x, 3));
		x = x + h;
		s1 = s1 + (1 + pow(x, 3));
		x = x + h;
		i = i + 1;
	}

	s = (h / 3) * ((1 + pow(a, 3)) + 4 * (1 + pow(a + h, 3)) + 4 * s1 + 2 * s2 + (1 + pow(b, 3)));

	cout << "s = " << s << endl;

    return c;
}

int pack3()
{
	double a = 0, b = 0.25, e = 0.0001, x{};

	while (abs(a - b) > (2 * e))
	{
		x = (a + b) / 2;

		if ((5 * x - 1 + pow(x, 3)) * (5 * a - 1 + pow(a, 3)) <= 0)
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