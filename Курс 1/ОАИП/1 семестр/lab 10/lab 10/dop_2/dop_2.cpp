#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "RU");

	int const N = 50;
	int mas[N]{}, n = 0;

	srand((unsigned)time(NULL));

	cout << "�������� �������: ";
	for (int i = 0; i < 20; i++)
	{
		mas[i] = rand() % 20;
		cout << mas[i] << " ";
	}	

	for (int i = 0; i < 20; i++)
	{
		if (mas[i] == mas[i + 1])
		{
			n++;
		}
	}

	cout << endl << "���������� ��� �������� ��������� ������� � ����������� ����������: " << n << endl;

	return 0;
}