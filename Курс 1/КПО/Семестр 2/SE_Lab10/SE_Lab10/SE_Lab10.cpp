#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(0, "RU");

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1);

	cout << "число: " << target1 << " количество: " << num_items1 << "\n";

	int num_items3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });

	cout << "количество элементов, кратных 3: " << num_items3 << "\n";
	cout << "\n" << " Лямбда, захват переменных" << "\n";

	for (auto i : v) [i]() {if (i % 3 == 0) cout << i << " "; }();
	cout << "\n" << " Лямбда с параметрами" << "\n";

	for (auto i : v) [](auto i) {if (i % 3 == 0) cout << i << " "; }(i);
	cout << "\n" << " Лямбда без параметров" << "\n";

	for (auto i : v) [i] {if (i % 3 == 0) cout << i << " "; }();
}