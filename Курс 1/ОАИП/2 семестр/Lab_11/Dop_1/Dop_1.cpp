#include <iostream>
#include <string.h>

using namespace std;

template<typename T>

// Создаем шаблонный класс Tree
class Tree
{
private:
	
	template<typename T>

	// Создаем шаблонный класс Node - элемент дерева
	class Node
	{
	public:
		
		Node<T>* right;  // Указатель на правый элемент
		Node<T>* left;  // Указатель на левый элемент

		// Данные
		T dataF;
		T dataS;

		int key;
		int sum;

		// Конструктор для узла дерева
		Node(T dataF, T dataS, int key, Node<T>* right = nullptr, Node<T>* left = nullptr) 
		{
			// Записываем данные в экземпляр объекта Node
			this->dataF = dataF;
			this->dataS = dataS;
			this->key = key;
			this->right = right;
			this->left = left;
			this->sum = dataS + dataF;
		}
	};

	int Size;

	Node<T>* Root;  // Указатель на корень дерева

public:
	
	Tree();  // Конструктор основного класса

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
	void insert(T dataF, T dataS, int key);
	void del(int key);
	void findMax(Node<T>* current);

	int MAX;
	int index;
};

template<typename T>

// Конструктор главного класса
Tree<T>::Tree()
{
	// Задаем начальные значения
	Root = nullptr;
	Size = 0;
	MAX = 0;
	index = 0;
}

template<typename T>

// Метод поиска максимального значения
void Tree<T>::findMax(Node<T>* current)
{
	// Проверка на пустоту дерева
	if (current != nullptr)
	{
		// Рекурсивно перебираем элементы справа и слева и с помощью условия находим максимальную сумму
		findMax(current->left);

		if (MAX < current->sum)
		{
			MAX = current->sum;
			index = current->key;
		}

		findMax(current->right);
	}
}

template<typename T>

// Метод удаления вершины
void Tree<T>::del(int key)
{
	Node<T>* Del, * Prev_Del, * R, * Prev_R;

	Del = Root;
	Prev_Del = NULL;

	while (Del != NULL && Del->key != key)  // Поиск элемента и его родителя 
	{
		Prev_Del = Del;

		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}

	if (Del == NULL)  // Элемент не найден
	{
		puts("\nНет такого ключа");

		return;
	}

	if (Del->right == NULL)  // Поиск элемента R для замены
		R = Del->left;
	else
	{ 
		if (Del->left == NULL)
			R = Del->right;
		else
		{
			// Поиск самого правого элемента в левом поддереве
			Prev_R = Del;  
			R = Del->left;

			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}

			// Найден элемент для замены R и его родителя Prev_R
			if (Prev_R == Del)   
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	}

	if (Del == Root) 
		Root = R;  // Удаление корня и замена его на R
	else
	{ 
		// Поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
		{ 
			Prev_Del->left = R;  // На левую ветвь 
		}
		else
			Prev_Del->right = R;  // На правую ветвь
	}

	int tmp = Del->key;

	cout << "\nУдален элемент с ключом " << tmp << endl;

	delete Del;

	Size--;
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
			cout << "            ";

		cout << t->key << " (" << t->dataF << " " << t->dataS << ")" << endl;

		print(t->right, level + 1);
	}
}

template<typename T>

// Метод добавления нового элемента в дерево
void Tree<T>::insert(T dataF, T dataS, int key)
{
	// Создаем временные переменные на текунщий и на предыдущий элементы
	Node<T>* current = Root;
	Node<T>* prev = nullptr;

	// Проверка на пустоту дерева
	if (Root == nullptr)
	{
		// Записываем в корень первый элемент
		Root = new Node<T>(dataF, dataS, key);
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
			prev->right = new Node<T>(dataF, dataS, key);
		}
		else 
		{
			prev->left = new Node<T>(dataF, dataS, key);
		}
	}

	Size++;
}

// Удаление вершины с максимальной суммой 2 целых значений узла
void deleteMax()
{
	Tree<int> tree;

	tree.insert(10, 11, 19);
	tree.insert(16, 15, 21);
	tree.insert(13, 5, 17);
	tree.insert(14, 16, 23);
	tree.insert(11, 6, 15);
	tree.insert(12, 18, 25);
	tree.insert(17, 7, 13);
	tree.insert(17, 7, 27);
	tree.insert(17, 7, 11);

	tree.print(tree.getRoot(), 0);

	cout << endl << endl;
	
	tree.findMax(tree.getRoot());
	tree.del(tree.index);

	cout << endl;

	tree.print(tree.getRoot(), 0);
}

int main()
{
	setlocale(0, "ru");

	deleteMax();

	return 0;
}