#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
int main()
{ 
	double p, q, t = 6, y = -1.2, x = 0.4e+6;
	p = 2.6 * t + cos(y / (3 * x + y));
	q = sin(t) / cos(t);
	printf("p=");
	cout << p << " ";
	printf("q=");
	cout << q;
}
