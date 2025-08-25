#include "FST.h"

namespace FST
{
    // ����������� ��������� RELATION
    RELATION::RELATION(char c, short ns) : symbol(c), nnode(ns) {}
    // �������������� ���� symbol �������� c � nnode �������� ����� ��������� ns.

    // ����������� �� ��������� ��� NODE
    NODE::NODE() : n_relation(0), relations(nullptr) {}
    // �������������� n_relation ������ 0 (��� ������) � relations ������ nullptr (������ �� ��������).

    // ����������� ��� NODE � ���������� ����������� ������
    NODE::NODE(short n, RELATION rel, ...)
    {
        n_relation = n;                 // ������������� ���������� ������
        relations = new RELATION[n];    // �������� ������ ��� ������� ������.

        va_list args;                   // ��������� ���������� ������ ����������.
        va_start(args, rel);            // �������������� ������ ���������� ������ ����������.
        relations[0] = rel;             // ��������� ������ ���������.

        for (short i = 1; i < n; ++i)   // �������� �� ���������� ������
        {
            relations[i] = va_arg(args, RELATION);      // �������� � ��������� ��������� ���������.
        }

        va_end(args);                   // ��������� ������ �� ������� ���������� ����������.
    }

    // ����������� ��� FST
    FST::FST(char* s, short ns, NODE n, ...)
    {
        string = s;                 // ������������� ������� ������.
        position = 0;               // �������������� ������� ������� � ������.
        nstates = ns;               // ������������� ���������� ���������.
        nodes = new NODE[ns];       // �������� ������ ��� ������� �����.

        va_list args;               // ��������� ���������� ������ ����������.
        va_start(args, n);          // �������������� ������ ���������� ������ �����.
        nodes[0] = n;               // ��������� ������ ����.

        for (short i = 1; i < ns; ++i)          // �������� �� ���������� �����
        {
            nodes[i] = va_arg(args, NODE);      // �������� � ��������� �������������� ����.
        }

        va_end(args);           // ��������� ������ �� ������� ���������� ����������.

        rstates = new short[ns];            // �������� ������ ��� ������������� �������� ���������.
        for (short i = 0; i < ns; ++i)      // �������������� ���������
        {
            rstates[i] = -1;                // ������������� -1 ��� ����������� ���������.
        }
        rstates[0] = 0;             // ���������� ��������� ���������.
    }

    // ������� execute ��� ������� ������ � ������� �������������������� ��������
    bool execute(FST& fst)
    {
        short* current_states = new short[fst.nstates];         // ������ ��� �������� ������� �������� ���������.
        short* next_states = new short[fst.nstates];            // ������ ��� �������� ��������� ���������.

        // �������������� ������� ���������
        for (short i = 0; i < fst.nstates; ++i)
        {
            current_states[i] = fst.rstates[i];         // �������� �������� ��������� �� FST.
        }

        short string_length = strlen(fst.string);       // �������� ����� ������� ������.

        for (fst.position = 0; fst.position < string_length; ++fst.position)        // �������� �� ������� ������� ������
        {
            char current_char = fst.string[fst.position];       // �������� ������� ������ �� ������.

            // �������������� ��������� ������ ���������
            for (short i = 0; i < fst.nstates; ++i)
            {
                next_states[i] = -1;        // ���������� ��� �������� �� -1 (���������� ���������).
            }

            // �������� �� ������� ����������
            for (short i = 0; i < fst.nstates; ++i)
            {
                if (current_states[i] != -1)            // ���� ��������� �������
                {
                    NODE& current_node = fst.nodes[i];      // �������� ������� ����.

                    // ��������� ��� �������� �� �������� ���������
                    for (short j = 0; j < current_node.n_relation; ++j)
                    {
                        RELATION& rel = current_node.relations[j];      // �������� ������� ���������.

                        // ���� ������ �������� ��������� � ������� �������� ������
                        if (rel.symbol == current_char)
                        {
                            next_states[rel.nnode] = fst.position + 1;      // ������������� ��������� ���������.
                        }
                    }
                }
            }

            // ��������� ������� ��������� ��� ��������� ��������
            for (short i = 0; i < fst.nstates; ++i)
            {
                current_states[i] = next_states[i];         // ��������� � ��������� ����������.
            }
        }

        // �����: ���� ��������� ��������� ������������� ����� ������
        bool success = (current_states[fst.nstates - 1] == string_length);

        delete[] current_states;        // ����������� ������ ��� ������� ������� ���������.
        delete[] next_states;           // ����������� ������ ��� ������� ��������� ���������.

        return success;         // ���������� ������ ������.
    }
}