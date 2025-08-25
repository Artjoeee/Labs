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

STR1	DB "Жамойдо Артём Игоревич", 0 
STR2	DB "Массив содержит нулевой элемент", 0 
STR3	DB "Массив не содержит нулевой элемент", 0 
HW		DD ?  

.code

main PROC
START:
	mov EDI, 2
	mov AX, [myWords + EDI]
	mov BX, myWords[0]

	xor EAX, EAX  ; Обнуление регистра EAX.
	xor EBX, EBX  ; Обнуление регистра EBX.

	add AL, [Arr]    
	add AL, [Arr + 1]
	add AL, [Arr + 2]
	add AL, [Arr + 3]
	add AL, [Arr + 4]
	add AL, [Arr + 5]
	add AL, [Arr + 6]

	xor EAX, EAX  ; Обнуление регистра EAX.
	mov ECX, LENGTHOF Arr  ; Загрузка длины массива байтов в регистр ECX.
	mov EBX, 1  ; Установка значения EBX в 1.

CYCLE:
	cmp [Arr + EAX], 0  ; Сравнение значения элемента массива байтов с 0.
	je TRUE  ; Если равно 0, переход к метке TRUE.
	jne FALSE  ; Если не равно 0, переход к метке FALSE.

TRUE:
	mov EBX, 0  ; Установка значения EBX в 0.
	invoke MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK 
	jmp ENDOFCYCLE  ; Переход к метке ENDOFCYCLE.

FALSE:
	add EAX, 1  ; Увеличение значения регистра EAX на 1.
	loop CYCLE  ; Повторение цикла, пока значение регистра ECX не станет равным 0.

ENDOFCYCLE:

	cmp EBX, 1  ; Сравнение значения EBX с 1.
	je CHECKF  ; Если равно 1, переход к метке CHECKF.
	jne CHECKT  ; Если не равно 1, переход к метке CHECKT.

CHECKF:
	invoke MessageBoxA, HW, OFFSET STR3, OFFSET STR1, MB_OK  

CHECKT:

	push 0  
	CALL ExitProcess 

main ENDP 
end main
