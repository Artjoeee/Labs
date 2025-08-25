#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int A, B, C, sum = 0;

	cout << "¬ведите A: ";
	cin >> A;

	cout << "¬ведите B: ";
	cin >> B;

	cout << "¬ведите C: ";
	cin >> C;

	A % 5 == 0 ? sum = sum + A : sum = sum + 0;
	B % 5 == 0 ? sum = sum + B : sum = sum + 0;
	C % 5 == 0 ? sum = sum + C : sum = sum + 0;

	sum == 0 ? cout << "Error" : cout << "—умма чисел, которые дел€тс€ на 5= " << sum;

	return 0;
}