#include "Hash.h"
#include <iostream>

// ������� �������������� �����������
int HashFunction(int key, int size)
{
	// ��������� ��������� ������������� a � b
	int a = rand() % size + 1;
	int b = rand() % size - 1;

	int p = 10000001;

	// ���������� ���� � �������������� ������������� ���-�������
	return ((a * key + b) % p) % size;
}

//������� ���������� �����������
//int HashFunction(int key, int size)    
//{
//	return key % 32;
//}

// ������� ���������������
int Next_hash(int hash, int size)
{
	int p = 10000001;

	// ���������� ������ ���� � �������������� ������ ���������������
	return (hash + 1) % size;
}

// �������� ������� ���-�������
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}

// ����������� ������ Object
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;

	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];

	// ������������� ���-������� ������� �����������
	for (int i = 0; i < size; ++i)
	{
		data[i] = NULL;
	}
}

// ������� �������� � ���-�������
bool Object::insert(void* d)
{
	bool b = false;
	

	if (N != size)
	{ 
		// ����� ���������� ����� ��� ������� ��������
		for (int i = 0, t = getKey(d), j = HashFunction(t, size); i != size && !b; j = Next_hash(j, size))
		{
			if (data[j] == NULL || data[j] == DEL)
			{				
				data[j] = d;  // ������� ��������
				N++;  // ���������� �������� ���������

				b = true;
			}
		}
	}

	return b;  // ����������� ���������� �������
}

// ����� ������� �������� �� �����
int Object::searchInd(int key)
{
	bool find = false;

	int hash_index = HashFunction(key, size);

	// ���� ������ ��������
	while (!find)
	{
		if (data[hash_index] != NULL && data[hash_index] != DEL && getKey(data[hash_index]) == key)
		{
			find = true;

			return hash_index;  // ����������� ���������� �������
		}

		hash_index = Next_hash(hash_index, size);  // ������� � ���������� ����
	}
}

// ����� �������� �� �����
void* Object::search(int key)
{
	int t = searchInd(key);

	return(t >= 0) ? (data[t]) : (NULL);  // ����������� ���������� �������� ��� NULL
}

// �������� �������� �� �����
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);

	void* t = data[i];  // ���������� ���������� ��������

	if (t != NULL)
	{
		data[i] = DEL;  // ������� �������� ��� ����������
		N--;  // ���������� �������� ���������
	}

	return t;  // ����������� ���������� ��������
}

// �������� �������� �� ��������
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);  // �������� �������� �� �����
}

// �������� ���� ��������� � ���-�������
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		cout << " ������� " << i;

		if ((this->data)[i] == NULL)
		{
			cout << "  �����" << endl;  // ����� ���������� � ������ �����
		}
		else
		{
			if ((this->data)[i] == DEL)
			{
				cout << "  ������" << endl;  // ����� ���������� � ��������� ��������
			}
			else
			{	
				f((this->data)[i]);  // ����� ���������������� ������� ��� ���������� ��������
			}	
		}
	}
}