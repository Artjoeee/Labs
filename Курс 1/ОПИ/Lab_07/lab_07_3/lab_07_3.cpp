#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	char symbol;

	cout << "������� ������ Unicode: ";

	cin >> symbol;

	cout << "UTF-8: " << int(symbol) << endl;

	return 0;
}