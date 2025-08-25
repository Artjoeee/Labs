#include "stdafx.h"
#include "Auxil.h"								// Вспомогательные функции 
#include "Fibonachi.h"
#include <iostream>
#include <ctime>
#include <locale>

#define  CYCLE  1000000							// Количество циклов  

using namespace std;
using namespace auxil;

int main(int argc, char* argv[])
{
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(0, "RU");

	start();									// Старт генерации 

	t1 = clock();								// Фиксация времени 

	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)iget(-100, 100);			// Сумма случайных чисел 
		av2 += dget(-100, 100);					// Сумма случайных чисел 
	}

	t2 = clock();								// Фиксация времени 

	cout << "\nКоличество циклов:         " << CYCLE;
	cout << "\nСреднее значение (int):    " << av1 / CYCLE;
	cout << "\nСреднее значение (double): " << av2 / CYCLE;
	cout << "\nПродолжительность (у.е):   " << (t2 - t1);
	cout << "\n                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);

	cout << endl;

	system("pause");

	cout << "\nФункция чисел Фиббоначи";

	clock_t  t3 = 0, t4 = 0; 
	int a;

	cout << "\nВведите N-ое число: ";
	cin >> a;

	t3 = clock();

	long double result = fibonachi(a);

	cout << endl << a << " число Фиббоначи = " << result;

	t4 = clock();

	cout << "\nПродолжительность (у.е):   " << (t4 - t3);
	cout << "\n                  (сек):   "
		<< ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC);

	cout << endl;

	system("pause");

	return 0;
}