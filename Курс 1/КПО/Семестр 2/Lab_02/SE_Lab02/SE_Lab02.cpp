#include <iostream>
#include <windows.h>

using namespace std;

// �������, �� ������� ����� ��������� ��������� �� �������
int add(int a, int b) 
{
	return a + b;
}

int subtract(int a, int b) 
{
	return a - b;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;

	cout << "������� ���� ���������� ����� �� ������: ";
	cin >> n;

	int X = 9 + n, Y = 10 + n, Z = 11 + n;
	float S = 1.0 + n;

	cout << "�������� X:" << " " << X << endl;
	cout << "�������� Y:" << " " << Y << endl;
	cout << "�������� Z:" << " " << Z << endl;
	cout << "�������� S:" << " " << S << endl << endl;

	bool a = true; // a = 1 
	bool b = false; // b = 0

	char c = 'h'; // 68
	char d = '�'; // e0

	wchar_t e = L'z'; // 7a
	wchar_t f = L'�'; // 436

	short x1 = X; // x1 = d
	short x2 = -X; // x2 = fff3

	cout << "����������������� �������� X: 0x" << hex << x1 << endl;
	cout << "����������������� �������� -X: 0x" << hex << x2 << endl << endl;

	short smax = 0x7fff; // smax = 7fff 
	short smin = 0x8000; // smin = 8000

	unsigned short usmax = 0xffff; // usmax = ffff
	unsigned short usmin = 0x0000; // usmin = 0

	int y1 = Y; // y1 = e 
	int y2 = -Y; // y2 = fffffff2

	cout << "����������������� �������� Y: 0x" << hex << y1 << endl;
	cout << "����������������� �������� -Y: 0x" << hex << y2 << endl << endl;

	int imax = 0x7fffffff; // imax = 7fffffff 
	int imin = 0x80000000; // imin = 80000000

	unsigned int unimax = 0xffffffff; // unimax = ffffffff 
	unsigned int unimin = 0x00000000; // unimin = 0

	long z1 = Z; // z1 = f
	long z2 = -Z; // z2 = fffffff1

	cout << "����������������� �������� Z: 0x" << hex << z1 << endl;
	cout << "����������������� �������� -Z: 0x" << hex <<z2 << endl << endl;

	long lmax = 0x7fffffff; // lmax = 7fffffff 
	long lmin = 0x80000000; // lmin = 80000000

	unsigned long unlmax = 0xffffffff; // unlmax = ffffffff 
	unsigned long unlmin = 0x00000000; // unlmin = 0

	float s1 = S; // 40a00000
	float s2 = -S; // c0a00000

	// ���������� �������� ��� ��������� ����������� ��������
	double null = 0.0;
	float inf = 1.0 / null;
	float neg_inf = -1.0 / null;
	float ind = inf / neg_inf; 

	// ��������� �� ������ ���� ������
	char* ptr_c = &c; // 0x0000008e12eff214
	wchar_t* ptr_e = &e; // 0x0000008e12eff254
	short* ptr_x1 = &x1; // 0x0000008e12eff294
	int* ptr_y1 = &y1; // 0x0000008e12eff354
	float* ptr_s1 = &s1; // 0x0000008e12eff4d4
	float* ptr_inf = &inf; // 0x0000008e12eff534

	// ���������� �� 3
	ptr_c += 3;
	ptr_e += 3;
	ptr_x1 += 3;
	ptr_y1 += 3;
	ptr_s1 += 3;
	ptr_inf += 3;

	// ���������� ���������� �� ������� � ���������� int(*)(int, int)
	int (*functionPtr)(int, int);

	// ������������ ��������� ������� add
	functionPtr = &add; 

	// ����� ������� ����� ���������
	int result = functionPtr(5, 3);
	cout << "��������� ������ add(5, 3) ����� ��������� �� �������: " << result << endl;

	// ����� ��������� �� ������� subtract
	functionPtr = &subtract; 

	// ����� ������� ����� ���������� ���������
	result = functionPtr(10, 4);
	cout << "��������� ������ subtract(10, 4) ����� ��������� �� �������: " << result << endl;

	return 0;
}