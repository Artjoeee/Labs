#pragma once

#define IN_MAX_LEN_TEXT 1024*1024		// ������������ ������ ��������� ���� = 1MB
#define IN_CODE_ENDL '\n'				// ������ ����� ������		

// ������� �������� ������� ����������, ������ = ��� (Windows-1251) �������
// �������� IN::F - ����������� ������, IN::T - ����������� ������, IN::I -������������ (�� �������),
// ���� 0 <= �������� < 256 - �� �������� ������ ��������

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
    '-', IN::F, IN::F, IN::F, IN::F, IN::F, '�', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    '�', IN::F, IN::F, IN::F, '�', '�', IN::F, IN::F, IN::F, '�', IN::F, IN::F, '�', IN::F, '�', IN::F, \
    '�', IN::F, '�', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	}


namespace In
{
	struct IN                       // �������� ������
	{
		enum { T = 1024, F = 2048, I = 4096 };          // T - ���������� ������, F - ������������, I - ������������, ����� ��������  

		int size;                                       // ������ ��������� ����
		int lines;                                      // ���������� �����
		int ignor;                                      // ���������� ����������������� ��������
		unsigned char* text;                            // �������� ��� (Windows - 1251)

		int code[256] = IN_CODE_TABLE;                  // ������� ��������: �, F, I ����� ��������
	};

	IN getin(wchar_t infile[]);		// ������ � ��������� ������� �����
};