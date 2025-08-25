#include "FST.h"

namespace FST
{
    // Конструктор структуры RELATION
    RELATION::RELATION(char c, short ns) : symbol(c), nnode(ns) {}
    // Инициализирует поле symbol символом c и nnode коротким целым значением ns.

    // Конструктор по умолчанию для NODE
    NODE::NODE() : n_relation(0), relations(nullptr) {}
    // Инициализирует n_relation равным 0 (без связей) и relations равным nullptr (память не выделена).

    // Конструктор для NODE с переменным количеством связей
    NODE::NODE(short n, RELATION rel, ...)
    {
        n_relation = n;                 // Устанавливаем количество связей
        relations = new RELATION[n];    // Выделяем память для массива связей.

        va_list args;                   // Объявляем переменный список аргументов.
        va_start(args, rel);            // Инициализируем список аргументов первым отношением.
        relations[0] = rel;             // Сохраняем первое отношение.

        for (short i = 1; i < n; ++i)   // Проходим по оставшимся связям
        {
            relations[i] = va_arg(args, RELATION);      // Получаем и сохраняем остальные отношения.
        }

        va_end(args);                   // Завершаем работу со списком переменных аргументов.
    }

    // Конструктор для FST
    FST::FST(char* s, short ns, NODE n, ...)
    {
        string = s;                 // Устанавливаем входную строку.
        position = 0;               // Инициализируем текущую позицию в строке.
        nstates = ns;               // Устанавливаем количество состояний.
        nodes = new NODE[ns];       // Выделяем память для массива узлов.

        va_list args;               // Объявляем переменный список аргументов.
        va_start(args, n);          // Инициализируем список аргументов первым узлом.
        nodes[0] = n;               // Сохраняем первый узел.

        for (short i = 1; i < ns; ++i)          // Проходим по оставшимся узлам
        {
            nodes[i] = va_arg(args, NODE);      // Получаем и сохраняем дополнительные узлы.
        }

        va_end(args);           // Завершаем работу со списком переменных аргументов.

        rstates = new short[ns];            // Выделяем память для представления активных состояний.
        for (short i = 0; i < ns; ++i)      // Инициализируем состояния
        {
            rstates[i] = -1;                // Устанавливаем -1 для неактивного состояния.
        }
        rstates[0] = 0;             // Активируем начальное состояние.
    }

    // Функция execute для разбора строки с помощью недетерминированного автомата
    bool execute(FST& fst)
    {
        short* current_states = new short[fst.nstates];         // Массив для хранения текущих активных состояний.
        short* next_states = new short[fst.nstates];            // Массив для хранения следующих состояний.

        // Инициализируем текущие состояния
        for (short i = 0; i < fst.nstates; ++i)
        {
            current_states[i] = fst.rstates[i];         // Копируем активные состояния из FST.
        }

        short string_length = strlen(fst.string);       // Получаем длину входной строки.

        for (fst.position = 0; fst.position < string_length; ++fst.position)        // Проходим по каждому символу строки
        {
            char current_char = fst.string[fst.position];       // Получаем текущий символ из строки.

            // Инициализируем следующий массив состояний
            for (short i = 0; i < fst.nstates; ++i)
            {
                next_states[i] = -1;        // Сбрасываем все значения на -1 (неактивные состояния).
            }

            // Проходим по текущим состояниям
            for (short i = 0; i < fst.nstates; ++i)
            {
                if (current_states[i] != -1)            // Если состояние активно
                {
                    NODE& current_node = fst.nodes[i];      // Получаем текущий узел.

                    // Проверяем все переходы из текущего состояния
                    for (short j = 0; j < current_node.n_relation; ++j)
                    {
                        RELATION& rel = current_node.relations[j];      // Получаем текущее отношение.

                        // Если символ перехода совпадает с текущим символом строки
                        if (rel.symbol == current_char)
                        {
                            next_states[rel.nnode] = fst.position + 1;      // Устанавливаем следующее состояние.
                        }
                    }
                }
            }

            // Обновляем текущие состояния для следующей итерации
            for (short i = 0; i < fst.nstates; ++i)
            {
                current_states[i] = next_states[i];         // Переходим к следующим состояниям.
            }
        }

        // Успех: если последнее состояние соответствует длине строки
        bool success = (current_states[fst.nstates - 1] == string_length);

        delete[] current_states;        // Освобождаем память для массива текущих состояний.
        delete[] next_states;           // Освобождаем память для массива следующих состояний.

        return success;         // Возвращаем статус успеха.
    }
}