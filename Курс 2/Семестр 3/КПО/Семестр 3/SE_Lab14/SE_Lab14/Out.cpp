#include "stdafx.h"
#include "Out.h"

namespace Out 
{
    // Создание и открытие файла
    OUT getout(wchar_t outfile[]) 
    {
        OUT out{};

        out.streamOut = new ofstream;
        out.streamOut->open(outfile);

        if (!out.streamOut->is_open())
        {
            throw ERROR_THROW(110);
        }

        wcscpy_s(out.outfile, outfile);

        return out;
    }

    // Вывод ошибки
    void WriteErrorOut(OUT out, Error::ERROR error) 
    {
        *out.streamOut << "Ошибка " << error.id << ":" << error.message << endl;

        if (error.inext.line != -1)
        {
            *out.streamOut << "Строка " << error.inext.line << " Позиция: " << error.inext.col << endl << endl;
        }
    }

    // Запись в файл
    void WriteInOut(OUT out, In::IN in) 
    {
        *out.streamOut << in.text << endl;
    }

    // Закрытие потока
    void Close(OUT out) 
    {
        out.streamOut->close();

        delete out.streamOut;
    }
};