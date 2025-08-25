#pragma once

#define LEXEMA_FIXSIZE	1			// фиксированный размер лексемы
#define LT_MAXSIZE		4096		// максимальное количество строк в таблице лексем
#define LT_TI_NULLIDX	0xfffffff	// нет элемента таблицы идентификаторов
#define LEX_SHORT		't'
#define LEX_CHAR		't'
#define LEX_BOOL		't'
#define LEX_STRING		't'
#define LEX_ID			'i'
#define LEX_LITERAL		'l'
#define LEX_FUNCTION	'f'
#define LEX_RETURN		'r'
#define LEX_SHOW		'p'
#define LEX_SHOWLINE	'z' 
#define LEX_MAIN		'm'
#define LEX_SEMICOLON	';'
#define LEX_TWOPOINT	':'
#define LEX_COMMA		','
#define LEX_LEFTBRACE	'{'
#define LEX_BRACELET	'}'
#define LEX_LEFTTHESIS	'('
#define LEX_RIGHTTHESIS	')'
#define LEX_PLUS		'v'	// +
#define LEX_MINUS		'v'	// -
#define LEX_STAR		'v'	// *
#define LEX_DIRSLASH	'v'	// /
#define LEX_PROC		'v' // %
#define LEX_OPERATOR	'v'	// оператор
#define LEX_LOGOPERATOR 'q' // логический оператор
#define LEX_SMALL		'q' // <
#define LEX_BIG			'q' // >
#define LEX_AND			'&' // &
#define LEX_EXL			'q' // !
#define LEX_TILDA		'q' // ~
#define LEX_EQUAL		'=' // =
#define LEX_ASK			'?' // ?
#define LEX_IF			'w' // лексема улови€
#define LEX_VOID		'n' // лексема void
#define LEX_ENDIF		'|' // конец услови€
#define LEX_AT			'@' // вызов функции
#define TI_NULLIDX		0xffffffff

namespace LT
{
	enum operations
	{
		OPLUS = 1,
		OMINUS,
		OMUL,
		ODIV,
		OMORE,
		OLESS,
		ONOTEQUALS,
		OPROC
	};

	struct Entry	// строка таблицы лексем
	{
		unsigned char lexema;	// лексема

		int sn;					// номер строки в исходном тексте
		int idxTI = TI_NULLIDX;		// индекс в таблице идентификаторов или LT_TI_NULLIDX
		int priority;

		operations op;
	};

	struct LexTable		// экземпл€р таблицы лексем
	{
		int max_size;		// емкость таблицы лексем < LT_MAXSIZE
		int size;			// текущий размер таблицы лексем < max_size

		Entry* table;		// массив строк таблицы лексем
	};

	LexTable Create(
		int size			// емкость таблицы лексем < LT_MAXSIZE
	);

	void Add(
		LexTable& lextable,	// экземпл€р таблицы лексем
		Entry entry			// строка таблицы лексем
	);

	void Add(LexTable& lextable, Entry entry, int i);

	Entry GetEntry(			// получить строку таблицы лексем
		LexTable& lextable,	// экземпл€р таблицы лексем
		int n				// номер получаемой строки
	);

	void Delete(LexTable& lextable);	// удалить таблицу лексем

	Entry writeEntry(			// заполнить строку таблицы лексем
		Entry& entry,
		unsigned char lexema,
		int indx,
		int line
	);

	void writeLexTable(std::ostream* stream, LT::LexTable& lextable);

	void showTable(LexTable lextable, std::ostream* fout);

};