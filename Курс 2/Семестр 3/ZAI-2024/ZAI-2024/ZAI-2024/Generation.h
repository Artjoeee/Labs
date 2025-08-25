#include "stdafx.h"

#define BEGIN ".586\n"\
".model flat, stdcall\n\n"\
"includelib libucrt.lib\n"\
"includelib kernel32.lib\n"\
"includelib \"../Debug/LIB.lib\"\n\n"\
".stack 4096\n"

#define END "INVOKE ExitProcess,0\nEXIT_DIV_ON_NULL:\nINVOKE ExitProcess,-1\nmain ENDP\nend main"

#define EXTERN "ExitProcess PROTO :DWORD\n\
outw PROTO : DWORD\n\
outwf PROTO : DWORD\n\
len PROTO : DWORD\n\
comp PROTO : DWORD, : DWORD\n"

#define ITENTRY(x)  tables.idtable.table[tables.lextable.table[x].idxTI]
#define LEXEMA(x)   tables.lextable.table[x].lexema

#define CONST ".const\n\tnewline byte 13, 10, 0\n\ttrue_str db 'true', 0\n\tfalse_str db 'false', 0"
#define DATA "\n.data\n\ttemp sword ?\n\tbuffer byte 256 dup(0)"
#define CODE "\n.code\n\t\
int_to_char PROC uses eax ebx ecx edi esi,\n\t\t\
pstr: dword, ; ��������� �� ������\n\t\t\
intfield : sdword; ����� ��� �������������� � ������\n\t\t\
push ebx\n\t\t\
push ecx\n\t\t\
push edx\n\t\t\
mov edi, pstr; ��������� �� ������ ������\n\t\t\
mov eax, intfield\n\t\t\
cdq\n\t\t\
; �������� �� ������������� �����\n\t\t\
test eax, 80000000h\n\t\t\
jz positive\n\t\t\
neg eax\n\t\t\
neg edx\n\t\t\
mov byte ptr[edi], '-'\n\t\t\
inc edi; �������� ��������� �� ��������� �������\n\t\t\
positive :\n\t\t\
; �������������� ����� � ������\n\t\t\
mov ebx, 10\n\t\t\
xor ecx, ecx\n\t\t\
convert_loop:\n\t\t\
xor edx, edx\n\t\t\
div ebx; ����� ����� �� 10, ��������� � eax, ������� � edx\n\t\t\
add dl, '0'; ����������� ������� � ASCII\n\t\t\
push dx\n\t\t\
inc ecx; ����������� ������� ����\n\t\t\
test eax, eax; ���������, �� ����� �� �� ����\n\t\t\
jnz convert_loop; ���� �� ����, ���������� ������\n\t\t\
; ������ ���� � ������\n\t\t\
write_digits :\n\t\t\
pop dx; ��������� ����� �� �����\n\t\t\
mov[edi], dl; ���������� � � ������\n\t\t\
inc edi\n\t\t\
loop write_digits; ��������� ��� ���� ����\n\t\t\
; ��������� ������ ����\n\t\t\
mov byte ptr[edi], 0\n\t\t\
pop edx\n\t\t\
pop ecx\n\t\t\
pop ebx\n\t\t\
ret\n\t\
int_to_char ENDP\n"

namespace Gener
{
	void CodeGeneration(Lex::LEX& tables, Parm::PARM& parm, Log::LOG& log);
};