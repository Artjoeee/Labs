#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int A, B, C, sum = 0;

	cout << "������� A: ";
	cin >> A;

	cout << "������� B: ";
	cin >> B;

	cout << "������� C: ";
	cin >> C;

	A % 5 == 0 ? sum = sum + A : sum = sum + 0;
	B % 5 == 0 ? sum = sum + B : sum = sum + 0;
	C % 5 == 0 ? sum = sum + C : sum = sum + 0;

	sum == 0 ? cout << "Error" : cout << "����� �����, ������� ������� �� 5= " << sum;

	return 0;
}