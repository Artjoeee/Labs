#pragma once

#define ID_MAXSIZE		30			// ������������ ���������� �������� � ��������������
#define TI_MAXSIZE		4096		// ������������ ���������� ����� � ������� ���������������
#define TI_INT_DEFAULT	0x00000000	// �������� �� ��������� ��� ���� char
#define TI_CHAR_DEFAULT '\0'		// �������� �� ��������� ��� char
#define TI_BOOL_DEFAULT false		// �������� �� ��������� ��� bool
#define TI_STR_DEFAULT	0x00		// �������� �� ��������� ��� ���� string
#define TI_NULLIDX		0xffffffff	// ��� �������� ������� ���������������
#define TI_STR_MAXSIZE	255			// ������������ ������ ������

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

	struct Entry	// ������ ������� ���������������
	{
		int			idxfirstLE;			// ������ ������ ������ � ������� ������
		unsigned char	id[ID_MAXSIZE];		// �������������� (������������� ��������� �� ID_MAXSIZE)

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

		} value;	// �������� ��������������
	};

	struct IdTable				// ��������� ������� ���������������
	{
		int max_size;			// ������� ������� ��������������� < TI_MAXSIZE
		int size;				// ������� ������ ������� ��������������� < maxsize
		Entry* table;			// ������ ����� ������� ���������������
	};

	IdTable Create(
		int size				// ������� ������� ��������������� < TI_MAXSIZE
	);

	void Add(
		IdTable& idtable,	// ��������� ������� ���������������
		Entry entry			// ������ ������� ���������������
	);

	void Add(IdTable& idtable, Entry entry, int i);

	Entry GetEntry(			// �������� ������ ������� ���������������
		IdTable& idtable,	// ��������� ������� ���������������
		int n				// ����� ���������� ������
	);

	int IsId(				// �������: ����� ������ (���� ����), TI_NULLIDX (���� ���)
		IdTable& idtable,	// ��������� ������� ���������������
		unsigned char id[ID_MAXSIZE]	// �������������
	);

	void Delete(IdTable& idtable);	// ������� ������� ������ (���������� ������)

	void showITable(IdTable& table, ostream* log);	// ����� ������� ������
};