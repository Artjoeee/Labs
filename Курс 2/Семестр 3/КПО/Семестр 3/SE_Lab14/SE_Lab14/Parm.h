#pragma once

#include "stdafx.h"

#define PARM_IN L"-in:"					// Ключ для файла исходного кода
#define PARM_OUT L"-out:"				// Ключ для файла объектного кода
#define PARM_LOG L"-log:"				// Ключ для файла журнала
#define PARM_MAX_SIZE 300				// Максимальная длина строки параметра 
#define PARM_OUT_DEFAULT_EXT L".out"	// Расширение файла объектного кода по умолчанию
#define PARM_LOG_DEFAULT_EXT L".log"	// Расширение файла протокола по умолчанию

namespace Parm 
{
	struct PARM 
	{
		wchar_t in[PARM_MAX_SIZE];		// -in: имя файла исходного кода
		wchar_t out[PARM_MAX_SIZE];		// -out: имя файла объектного кода
		wchar_t log[PARM_MAX_SIZE];		// -log: имя файла проокола
	};

	PARM getparm(int argc, _TCHAR* argv[]);
}