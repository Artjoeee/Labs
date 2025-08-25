#pragma once

#include <cstring>
#define CRT_SECURE_N0_WARNINGS
#define DICTNAMEMAXSIZE 20  // Максимальный размер имени словаря
#define DICTMAXSIZE 100  // Максимальная емкость словаря
#define ENTRYNAMEMAXSIZE 30  // Максимальная длина имени в словаре
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной емкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary
{
	struct Entry  // Элемент словаря
	{
		int id;  // Идентификатор (уникальный)
		char name[ENTRYNAMEMAXSIZE];  // Символьная информация
	};

	struct Instance  // Экземпляр словаря
	{
		char name[DICTNAMEMAXSIZE];  // Наименование словаря
		int maxsize;  // Максимальная емкость словаря
		int size;  // Текущий размер словаря < DICTNAMEMAXSIZE
		Entry* dictionary;  // Массив элементов словаря
	};

	// Создать словарь
	Instance Create(
		const char name[DICTNAMEMAXSIZE], // Имя словаря
		int size  // Емкость словаря < DICTNAMEMAXSIZE
	);

	// Добавить элемент словаря
	void AddEntry(
		Instance& inst,  // Экземпляр слова
		Entry ed  // Элемент словаря
	);

	// Удалить элемент словаря
	void DelEntry(
		Instance& inst,  // Экземпляр слова
		int id  // Идентификатор удаляемого элемента (уникальный)
	);

	// Изменить элемент словаря
	void UpdEntry(
		Instance& inst,  // Экземпляр слова
		int id,  // Идентификатор заменяемого элемента
		Entry new_ed  // Новый элемент словаря
	);

	// Получить элемент словаря
	Entry GetEntry(
		Instance inst,  // Экземпляр слова
		int id  // Идентификатор получаемого элемента
	);

	void Print(Instance d);  // Печать словаря
	void Delete(Instance& d);  // Удалить словарь
};