#include <iostream>
using namespace std;
int main()
{
	double y, w, x = 1.4, m = 6, z = 00.5e-5;
	y = sqrt(1 + x) - cos(2 / m);
	w = 0.6 * z - 2 * exp(-2 * y * m);
	cout << "y=" << y << " " << "w=" << w;
}