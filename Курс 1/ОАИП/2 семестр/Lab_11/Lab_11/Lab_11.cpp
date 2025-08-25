#include <iostream>
#include <string.h>

using namespace std;

// Cоздаем шаблонный класс Tree
template<typename T>

class Tree
{
private:

	template<typename T>

	// Cоздаем шаблонный класс Node - элемент дерева
	class Node
	{
	public:
		// Указатель на правый элемент
		Node<T>* right;

		// Указатель на левый элемент
		Node<T>* left;

		// Данные
		T data;

		// Ключ
		int key;

		// Конструктор для узла дерева
		Node(T data, int key, Node<T>* right = nullptr, Node<T>* left = nullptr) 
		{
			// Записываем данные в экземпляр объекта Node
			this->data = data;
			this->key = key;
			this->right = right;
			this->left = left;
		}
	};

	// Указатель на корень дерева
	Node<T>* Root;

public:
	// Конструктор основного класса
	Tree();

	// Методы класса для работы с деревом
	Node<T>* getRoot()
	{ 
		return Root;
	}

	int getSize() 
	{ 
		return Size; 
	}

	void print(Node<T>* t, int level);
	void insert(T data, int key);
	void findMax(Node<T>* current, int key, int level);

	int Size;

	T sum;
};

template<typename T>

// Конструктор главного класса
Tree<T>::Tree()
{
	// Задаем начальные значения
	Root = nullptr;
	Size = 0;
}

template<typename T>

// Метод поиска максимального значения
void Tree<T>::findMax(Node<T>* current, int key, int level)
{
	// Проверка на пустоту дерева
	if (current != nullptr)
	{
		findMax(current->left, key, level + 1);

		if (current->key == key)
		{
			cout << "Количество ветвей: " << level;
		}

		findMax(current->right, key, level + 1);
	}
}

template<typename T>

// Метод вывода элементов дерева
void Tree<T>::print(Node<T>* t, int level)
{
	// Проверка на пустоту
	if (t != nullptr)
	{
		// Рекунрсивно выводим элементы дерева с отступами, в зависимости от занчения level
		print(t->left, level + 1);

		for (int i = 0; i < level; i++) 
			cout << "         ";

		cout << t->key << " " << t->data << endl;

		print(t->right, level + 1);
	}
}

template<typename T>

// Метод добавления нового элемента в дерево
void Tree<T>::insert(T data, int key)
{
	// Создаем временные переменные на текущий и предыдущий элементы
	Node<T>* current = Root;
	Node<T>* prev = nullptr;

	// Проверка на пустоту дерева
	if (Root == nullptr)
	{
		// Записываем в корень первый элемент
		Root = new Node<T>(data, key);
	}
	else 
	{
		// Перебираем дерево, пока не дойдем до конца
		while (current != nullptr)
		{
			// Записываем в prev текущее значение и в зависимости от значения ключа смещаем current
			prev = current;

			if (key > current->key)
			{
				current = current->right;
			}
			else 
			{
				current = current->left;
			}
		}

		// Сравнения значения ключа последнего элемента с текущим и создаение нового
		if (key > prev->key)
		{
			prev->right = new Node<T>(data, key);
		}
		else 
		{
			prev->left = new Node<T>(data, key);
		}
	}

	Size++;
}

// Подсчет числа ветвей от корня до ближайшей вершины
void countBranches()
{
	Tree<string> tree;

	tree.insert("Artiom", 19);
	tree.insert("Ivan", 17);
	tree.insert("Stepan", 21);
	tree.insert("Gleb", 15);
	tree.insert("Alex", 23);
	tree.insert("Egor", 13);
	tree.insert("Anton", 25);
	tree.insert("Petr",11);
	tree.insert("Stas", 27);

	tree.print(tree.getRoot(), 0);

	cout << endl << endl;

	int N;

	cout << "Введите ключ для подсчета ветвей до элемента: ";
	cin >> N;

	tree.findMax(tree.getRoot(), N, 1);
}

int main()
{
	setlocale(0, "ru");

	countBranches();

	return 0;
}