#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int a, b;

	puts("������! (1-����������, 2-�������)");
	cin >> a;

	switch (a)
	{
		case 1: puts("��� ����? (1-�� ������, 2-�� �����..., 3-�� ��� ����!)");
			cin >> b;

			switch (b)
			{
				case 1: puts("�������! ��� �� ����!");
					break;

				case 2: puts("��� ������");
					break;

				case 3: puts("������...");
					break;

				default: puts("��� �� ������?");
					break;
			}

			break;

		case 2: puts("�� �����");
			break;

		default: puts("� ���� �� �������");
			break;
	}

	return 0;
}