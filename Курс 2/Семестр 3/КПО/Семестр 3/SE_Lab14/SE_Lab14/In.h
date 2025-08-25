#pragma once

#define IN_MAX_LEN_TEXT 1024*1024		// Максимальный размер исходного кода = 1MB
#define IN_CODE_ENDL '\n'				// Символ конца строки		

// Таблица проверки входной информации, индекс = код (Windows-1251) символа
// Значения IN::F - заперщенный символ, IN::T - разрешенный символ, IN::I -игнорировать (не вводить),
// Если 0 <= значение < 256 - то вводится данное значение

#define IN_CODE_TABLE {\
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, '|', IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    ' ', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    '0', IN::F, '2', IN::F, IN::F, '5', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, 'A', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::F, 'Z', IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, 'a', IN::F, IN::F, 'd', IN::F, IN::F, IN::F, 'h', 'i', IN::F, IN::F, IN::F, 'm', IN::F, 'o', \
    IN::F, IN::F, 'r', 's', 't', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, '|', IN::F, IN::F, IN::F, \
																													\
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, '-', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    '-', IN::F, IN::F, IN::F, IN::F, IN::F, 'Ж', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    'а', IN::F, IN::F, IN::F, 'д', 'е', IN::F, IN::F, IN::F, 'й', IN::F, IN::F, 'м', IN::F, 'о', IN::F, \
    'р', IN::F, 'т', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	}


namespace In
{
	struct IN                       // Исходные данные
	{
		enum { T = 1024, F = 2048, I = 4096 };          // T - допустимый символ, F - недопустимый, I - игнорировать, иначе заменить  

		int size;                                       // Размер исходного кода
		int lines;                                      // Количество строк
		int ignor;                                      // Количество проигнорированных символов
		unsigned char* text;                            // Исходный код (Windows - 1251)

		int code[256] = IN_CODE_TABLE;                  // Таблица проверки: Т, F, I новое значение
	};

	IN getin(wchar_t infile[]);		// Ввести и проверить входной поток
};