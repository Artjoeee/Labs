#include <iostream>
#include <iomanip> 

int main()
{

	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';

	cout << "Введите символ ";
	cin >> c;
	cout << setw(1019) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(56) << setfill(probel) << probel;
	cout << setw(13) << setfill(c) << c << endl;
	cout << setw(54) << setfill(probel) << probel;
	cout << setw(17) << setfill(c) << c << endl;
	cout << setw(53) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(52) << setfill(probel) << probel;
	cout << setw(21) << setfill(c) << c << endl;

	return 0;

}