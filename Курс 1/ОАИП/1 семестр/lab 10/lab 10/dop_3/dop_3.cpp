#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int const N = 50;
	int mas[N]{}, max = 1, k = 1, n;

	cout << "������� ������ �������(�� 50): ";
	cin >> n;

	srand((unsigned)time(NULL));

	cout << "�������� �������: ";
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 2;
		cout << mas[i] << " ";
	}

	
	for (int i = 0; i < n; i++) 
	{
		if (mas[i] == mas[i - 1]) 
		{
			k++;
		}
		else 
		{
			if (k > max) 
			{
				max = k;
			}
			k = 1;
		}
	}

	if (k > max) 
	{
		max = k;
	}

	cout << endl << "���������� ����� ������ ������ ���������� ��������� " << max << endl;

	return 0;
}