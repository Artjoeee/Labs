#pragma once

#define ID_MAXSIZE		30			// максимальное количество символов в идентификаторе
#define TI_MAXSIZE		4096		// максимальное количество строк в таблице идентификаторов
#define TI_INT_DEFAULT	0x00000000	// значение по умолчанию дл€ типа char
#define TI_CHAR_DEFAULT '\0'		// значение по умолчанию дл€ char
#define TI_BOOL_DEFAULT false		// значение по умолчанию дл€ bool
#define TI_STR_DEFAULT	0x00		// значение по умолчанию дл€ типа string
#define TI_NULLIDX		0xffffffff	// нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE	255			// максимальный размер строки

#define TABLE *log << setw(15) << left << table.table[i].id << "| ";\
                if (table.table[i].idtype == OP || table.table[i].idtype == LO) *log << setw(10) << left << "-" << " | ";\
                else if (table.table[i].iddatatype == SHR) {*log << setw(10) << left << "short" << " | ";}\
                else if (table.table[i].iddatatype == STR)  *log << setw(10) << left << "string" << " | ";\
                else if (table.table[i].iddatatype == CHR)  *log << setw(10) << left << "char" << " | ";\
                else if (table.table[i].iddatatype == BOOL) *log << setw(10) << left << "bool" << " | ";\
                else if (table.table[i].iddatatype == VOI)  *log << setw(10) << left << "void" << " | ";\
                else if (table.table[i].nums == 16)        *log << setw(10) << left << "short(16)" << " | ";\
                else if (table.table[i].nums == 2)         *log << setw(10) << left << "short(2)" << " | ";\
                *log << setw(16) << left << table.table[i].idxfirstLE << " | ";\
                if (table.table[i].idtype == L) {\
                    if (table.table[i].iddatatype == SHR) {*log << table.table[i].value.vint;}\
                    else if (table.table[i].iddatatype == STR) *log << '[' << table.table[i].value.vstr.len << ']' << table.table[i].value.vstr.str;\
                    else if (table.table[i].iddatatype == CHR) *log << '\'' << table.table[i].value.vchar << '\'';\
                    else if (table.table[i].iddatatype == BOOL) *log << (table.table[i].value.vbool ? "true" : "false");\
                    else if (table.table[i].nums == 16 || table.table[i].nums == 2) *log << table.table[i].value.vstr.str;\
                } else *log << "-";\
                *log << endl;


#include "Parm.h"
#include "Log.h"

namespace IT
{
	enum IDDATATYPE { SHR = 1, STR = 2, SHR16 = 1, SHR2 = 1, NUL = 6, VOI = 4, CHR = 5, BOOL = 6 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, OP = 5, LO = 6 };

	struct Entry	// строка таблицы идентификаторов
	{
		int			idxfirstLE;			// индекс первой строки в таблице лексем
		unsigned char	id[ID_MAXSIZE];		// индентификатор (автоматически усекаетс€ до ID_MAXSIZE)

		IDDATATYPE	iddatatype = NUL;
		IDTYPE		idtype;

		int parm = 0;
		int nums = 0;

		union
		{
			short vint;

			char vchar;

			bool vbool;

			struct
			{
				int len;
				unsigned char str[TI_STR_MAXSIZE - 1];

			} vstr;

		} value;	// значение идентификатора
	};

	struct IdTable				// экземпл€р таблицы идентификаторов
	{
		int max_size;			// емкость таблицы идентификаторов < TI_MAXSIZE
		int size;				// текущий размер таблицы идентификаторов < maxsize
		Entry* table;			// массив строк таблицы идентификаторов
	};

	IdTable Create(
		int size				// емкость таблицы идентификаторов < TI_MAXSIZE
	);

	void Add(
		IdTable& idtable,	// экземпл€р таблицы идентификаторов
		Entry entry			// строка таблицы идентификаторов
	);

	void Add(IdTable& idtable, Entry entry, int i);

	Entry GetEntry(			// получить строку таблицы идентификаторов
		IdTable& idtable,	// экземпл€р таблицы идентификаторов
		int n				// номер получаемой строки
	);

	int IsId(				// возврат: номер строки (если есть), TI_NULLIDX (если нет)
		IdTable& idtable,	// экземпл€р таблицы идентификаторов
		unsigned char id[ID_MAXSIZE]	// идентификатор
	);

	void Delete(IdTable& idtable);	// удалить таблицу лексем (освободить пам€ть)

	void showITable(IdTable& table, ostream* log);	// вывод таблицы лексем
};