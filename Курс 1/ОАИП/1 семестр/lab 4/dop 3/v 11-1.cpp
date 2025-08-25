#include <iostream>
#include <iomanip> 
int main()
{

	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';

	cout << "Введите символ ";
	cin >> c;
	cout << setw(1012) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	

	return 0;
}