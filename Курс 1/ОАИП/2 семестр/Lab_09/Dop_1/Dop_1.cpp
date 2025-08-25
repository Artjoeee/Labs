#include <iostream>
#include <string.h>

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

using namespace std;

struct address
{
	string name;
	string sername;
	string klass;
	int scoreSub;  // Количество предметов


	address* next;
	address* prev;
};

// Функция для добавления элемента в список
void insert(address* e, address** phead, address** plast)
{
	address* p = *plast;

	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;

		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

// Функция для создания нового элемента
address* setelement()
{
	address* temp = new address();

	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}

	cout << "Введите имя: ";
	cin >> temp->name;

	cout << "Введите фамилию: ";
	cin >> temp->sername;

	cout << "Введите класс: ";
	cin >> temp->klass;

	cout << "Введите количество предметов: ";
	cin >> temp->scoreSub;

	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

// Функция для вывода списка на экран
void outputlist(address** phead, address** plast)
{
	address* t = *phead;

	if (t == NULL)
	{
		cout << "Список пуст." << endl;
	}

	while (t)
	{
		cout << "Фамилия: " << t->sername << endl;
		cout << "Имя: " << t->name << endl;
		cout << "Класс: " << t->klass << endl;
		cout << "Количество предметов: " << t->scoreSub << endl;

		t = t->next;
	}

	cout << "" << endl;
}

// Функция для поиска по имени в списке
void find(string name, address** phead)
{
	address* current = *phead;
	bool found = false;

	while (current)
	{
		if (current->name == name)
		{ 
			found = true;

			cout << "Фамилия: " << current->sername << endl;
			cout << "Имя: " << current->name << endl;
			cout << "Класс: " << current->klass << endl;
			cout << "Количество предметов: " << current->scoreSub << endl;
		}
		
		current = current->next;
	}
}

// Функция для подсчета количества элементов в списке
void countlist(address** phead, address** plast)
{
	address* t = *phead;
	int i = 0;

	while (t != NULL)
	{
		i++;
		t = t->next;
	}

	cout << "Количество элементов: " << i << endl;
}

// Функция для удаления всех элементов в списке
void deleteList(address** phead, address** plast)
{
	address* current = *phead;
	address* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}

	*phead = NULL;
	*plast = NULL;

	cout << "Список успешно удален!" << endl;
}

int main()
{
	address* head = NULL;
	address* last = NULL;

	setlocale(LC_CTYPE, "rus");

	int choice;
	char s[80]{}; 

	// Меню программы
	cout << endl;
	cout << "1. Ввод элемента" << endl;
	cout << "2. Вывод на экран" << endl;
	cout << "3. Поиск" << endl;
	cout << "4. Количество элементов" << endl;
	cout << "5. Очищение списка" << endl;
	cout << "6. Выход" << endl;
	cout << endl;

	for (;;)
	{
		cout << "Ваш выбор: ";
		cin >> choice;

		switch (choice)
		{
		case 1: insert(setelement(), &head, &last);
			break;
		case 2: outputlist(&head, &last);
			break;
		case 3: 
		{
			char fname[NAME_SIZE];

			cout << "Введите имя: ";
			cin >> fname;

			find(fname, &head);
		}
			  break;
		case 4: countlist(&head, &last);			
			  break;
		case 5: deleteList(&head, &last);			
			  break;
		case 6: exit(0);
		default: exit(1);
		}
	}

	return 0;
}