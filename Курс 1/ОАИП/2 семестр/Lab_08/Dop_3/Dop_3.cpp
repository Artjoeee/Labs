#include <iostream>
#include <fstream>

using namespace std;

struct Queue
{
	char data[255];  // Массив данных
	int head;  // Указатель на начало
};

void createQueue(Queue* Q)  // Создание очереди Q
{
	Q->head = NULL;
}

bool isEmpty(Queue* Q)  // Проверка очереди на пустоту
{
	if (Q->head == 0)
		return true;
	else
		return false;
}

void showQueue(Queue* Q)
{
	ofstream fout("g.txt", ios_base::app);  // Открытие файла для записи

	// Вывод содержимого очереди в файл
	for (int i = 0; i < Q->head; i++)
	{
		fout << Q->data[i];
	}

	Q->head = 0;

	fout.close();  // Закрытие файла
}

void addToQueue(Queue* Q, char value)  // Добавление элемента в очередь
{
	Q->data[Q->head++] = value;
}

ifstream fin("f.txt");  // Открытие файла для чтения

int main()
{
	ofstream fout("g.txt", ios_base::trunc);  // Открытие файла для записи

	fout.close();  // Закрытие файла

	setlocale(LC_ALL, "Rus");

	Queue Q1, Q2;

	createQueue(&Q1);  // Создание очереди Q1
	createQueue(&Q2);  // Создание очереди Q2

	while (!fin.eof())
	{
		char s[255] = "";
		fin.getline(s, 253);  // Чтение строки из файла

		// Разделение символов на две очереди
		for (int i = 0; i < strlen(s); i++)
		{
			if ((s[i] < '0') || (s[i] > '9'))  // Если символ не является цифрой
			{
				addToQueue(&Q1, s[i]);
			}
			else
			{
				addToQueue(&Q2, s[i]);
			}
		}

		showQueue(&Q1);  // Вывод содержимого очереди Q1 в файл
		showQueue(&Q2);  // Вывод содержимого очереди Q2 в файл

		ofstream fout("g.txt", ios_base::app);

		fout << endl;
		fout.close();
	}

	fin.close();

	return 0;
}