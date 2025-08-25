.586
.model flat,stdcall
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.stack 4096
.const
.data
myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h 
myDoubles DWORD 1, 2, 3, 4, 5, 6
myPointer DWORD myDoubles
Arr BYTE 5, 9, 6, 4, 1, 7, 3
MB_OK	EQU 0  

STR1	DB "������� ���� ��������", 0 
STR2	DB "������ �������� ������� �������", 0 
STR3	DB "������ �� �������� ������� �������", 0 
HW		DD ?  

.code

main PROC
START:
	mov EDI, 2
	mov AX, [myWords + EDI]
	mov BX, myWords[0]

	xor EAX, EAX  ; ��������� �������� EAX.
	xor EBX, EBX  ; ��������� �������� EBX.

	add AL, [Arr]    
	add AL, [Arr + 1]
	add AL, [Arr + 2]
	add AL, [Arr + 3]
	add AL, [Arr + 4]
	add AL, [Arr + 5]
	add AL, [Arr + 6]

	xor EAX, EAX  ; ��������� �������� EAX.
	mov ECX, LENGTHOF Arr  ; �������� ����� ������� ������ � ������� ECX.
	mov EBX, 1  ; ��������� �������� EBX � 1.

CYCLE:
	cmp [Arr + EAX], 0  ; ��������� �������� �������� ������� ������ � 0.
	je TRUE  ; ���� ����� 0, ������� � ����� TRUE.
	jne FALSE  ; ���� �� ����� 0, ������� � ����� FALSE.

TRUE:
	mov EBX, 0  ; ��������� �������� EBX � 0.
	invoke MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK 
	jmp ENDOFCYCLE  ; ������� � ����� ENDOFCYCLE.

FALSE:
	add EAX, 1  ; ���������� �������� �������� EAX �� 1.
	loop CYCLE  ; ���������� �����, ���� �������� �������� ECX �� ������ ������ 0.

ENDOFCYCLE:

	cmp EBX, 1  ; ��������� �������� EBX � 1.
	je CHECKF  ; ���� ����� 1, ������� � ����� CHECKF.
	jne CHECKT  ; ���� �� ����� 1, ������� � ����� CHECKT.

CHECKF:
	invoke MessageBoxA, HW, OFFSET STR3, OFFSET STR1, MB_OK  

CHECKT:

	push 0  
	CALL ExitProcess 

main ENDP 
end main
