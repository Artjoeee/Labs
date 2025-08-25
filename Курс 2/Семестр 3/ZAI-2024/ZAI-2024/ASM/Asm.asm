.586
.model flat, stdcall

includelib libucrt.lib
includelib kernel32.lib
includelib "../Debug/LIB.lib"

.stack 4096

ExitProcess PROTO :DWORD
outw PROTO : DWORD
outwf PROTO : DWORD
len PROTO : DWORD
comp PROTO : DWORD, : DWORD

.const
	newline byte 13, 10, 0
	true_str db 'true', 0
	false_str db 'false', 0
	L1 byte 'Это программа на языке ZAI-2024', 0
	L2 sword 5
	L3 byte 'Жамойдо Артем Игоревич', 0
	L4 byte 'Show', 0
	L5 byte 'Snow', 0
	L6 sword 0
	L7 byte 'Строки одинаковы', 0
	L8 byte 'Разные строки', 0
	L9 sword -1
	L10 sword 2
	L11 sword -20
	L12 sword 20
	L13 sword 3
	L14 sword 32000
	L15 sword 17
	L16 sword 32
	L17 byte 'a', 0
	L18 byte 1
	L19 sword 1
	L20 byte 'n', 0
	L21 byte 'P', 0
	L22 byte 0
	L23 sword 255
	L24 byte 'Длины строк совпадают', 0
	L25 byte 'Длины строк не совпадают', 0

.data
	temp sword ?
	buffer byte 256 dup(0)
	polish sword 0
	fio dword ?
	author dword ?
	str1 dword ?
	str2 dword ?
	answer1 sword 0
	answer2 sword 0
	math1 sword 0
	math2 sword 0
	math3 sword 0
	math4 sword 0
	math5 sword 0
	n sword 0
	check1 sword 0
	check2 sword 0
	result2 sword 0
	chr1 byte 0
	condition1 byte 0
	bin1 sword 0
	chr2 byte 0
	condition2 byte 0
	bin2 sword 0
	sum sword 0
	strc1 sword 0
	strc2 sword 0
	text dword ?
	left word ?
	right word ?
	result sword ?
	result_str byte 4 dup(0)

.code
	int_to_char PROC uses eax ebx ecx edi esi,
		pstr: dword, ; Указатель на строку
		intfield : sdword; Число для преобразования в строку
		push ebx
		push ecx
		push edx
		mov edi, pstr; Указатель на начало строки
		mov eax, intfield
		cdq
		; Проверка на отрицательное число
		test eax, 80000000h
		jz positive
		neg eax
		neg edx
		mov byte ptr[edi], '-'
		inc edi; Сдвигаем указатель на следующую позицию
		positive :
		; Преобразование числа в строку
		mov ebx, 10
		xor ecx, ecx
		convert_loop:
		xor edx, edx
		div ebx; Делим число на 10, результат в eax, остаток в edx
		add dl, '0'; Преобразуем остаток в ASCII
		push dx
		inc ecx; Увеличиваем счётчик цифр
		test eax, eax; Проверяем, не делим ли мы ноль
		jnz convert_loop; Если не ноль, продолжаем делить
		; Запись цифр в строку
		write_digits :
		pop dx; Извлекаем цифру из стека
		mov[edi], dl; Записываем её в строку
		inc edi
		loop write_digits; Повторяем для всех цифр
		; Завершаем строку нулём
		mov byte ptr[edi], 0
		pop edx
		pop ecx
		pop ebx
		ret
	int_to_char ENDP

show_text PROC 

push bx
push dx

INVOKE outwf, offset L1


pop dx
pop bx
ret
show_text ENDP

show_name PROC,
	show_namename : word  
push bx
push dx

pop dx
pop bx
mov ax, show_namename
ret
show_name ENDP


main PROC
push L2
push L2
push L2
push L2
push L2
pop bx
pop ax
imul ax, bx
push ax
pop bx
pop ax
add ax, bx
push ax
push L2
push L2
pop bx
pop ax
imul ax, bx
push ax
pop bx
pop ax
add ax, bx
push ax
pop bx
pop ax
imul ax, bx
push ax
pop bx
pop ax
add ax, bx
push ax
push L2
push L2
pop bx
pop ax
imul ax, bx
push ax
pop bx
pop ax
add ax, bx
push ax

pop bx
mov polish, bx

mov ax, polish
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str


call show_text

mov fio, offset L3
mov ecx, fio
mov author, ecx

INVOKE outwf, author

mov str1, offset L4
mov str2, offset L5
push str1
push str2
call comp
push ax

pop bx
mov answer1, bx

push str1
push str1
call comp
push ax

pop bx
mov answer2, bx

mov ax, answer1
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, answer2
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

push answer2

pop bx
mov left, bx

push L6

pop bx
mov right, bx

mov dx, left
cmp dx, right

jg right1
jle wrong1
right1:

INVOKE outwf, offset L7


jmp next1
wrong1:

INVOKE outwf, offset L8

next1:
push L9
push L10
pop bx
pop ax
sub ax, bx
push ax

pop bx
mov math1, bx

push L11
push L10
pop bx
pop ax
add ax, bx
push ax

pop bx
mov math2, bx

push L12
push L13

pop bx
pop ax
test bx, bx
jz EXIT_DIV_ON_NULL
cdq
idiv bx
push dx

pop bx
mov math3, bx

push L12
push L10
pop bx
pop ax
imul ax, bx
push ax

pop bx
mov math4, bx

push L12
push L2

pop bx
pop ax
test bx, bx
jz EXIT_DIV_ON_NULL
cdq
idiv bx
push ax

pop bx
mov math5, bx

mov ax, math1
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, math2
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, math3
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, math4
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, math5
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

push L14

pop bx
mov n, bx

push L15

pop bx
mov check1, bx

push L16

pop bx
mov check2, bx

push check1
push check2
pop bx
pop ax
add ax, bx
push ax

pop bx
mov result2, bx

mov ax, check1
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, check2
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, result2
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov byte ptr [chr1], 'a'
mov byte ptr [chr1 + 1], 0
INVOKE outwf, offset chr1

mov al, byte ptr [L18]
mov [condition1], al

cmp condition1, 1
je print_true_condition1

mov text, offset false_str
INVOKE outwf, text
jmp done_condition1

print_true_condition1:
mov text, offset true_str
INVOKE outwf, text

done_condition1:

push L19

pop bx
mov bin1, bx

mov ax, bin1
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov byte ptr [chr2], 'n'
mov byte ptr [chr2 + 1], 0
mov byte ptr [chr2], 'P'
mov byte ptr [chr2 + 1], 0
INVOKE outwf, offset chr2

mov al, byte ptr [L22]
mov [condition2], al

cmp condition2, 1
je print_true_condition2

mov text, offset false_str
INVOKE outwf, text
jmp done_condition2

print_true_condition2:
mov text, offset true_str
INVOKE outwf, text

done_condition2:

push L23

pop bx
mov bin2, bx

mov ax, bin2
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

push bin1
push bin2
pop bx
pop ax
add ax, bx
push ax

pop bx
mov sum, bx

mov ax, sum
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

push str1
call len
push ax
push L19
pop bx
pop ax
add ax, bx
push ax

pop bx
mov strc1, bx

push str2
call len
push ax

pop bx
mov strc2, bx

mov ax, strc1
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

mov ax, strc2
mov result, ax
INVOKE int_to_char, offset result_str, result
INVOKE outwf, offset result_str

push strc1

pop bx
mov left, bx

push strc2

pop bx
mov right, bx

mov dx, left
cmp dx, right

jz right2
jnz wrong2
right2:
mov text, offset L24

jmp next2
wrong2:
mov text, offset L25
next2:

INVOKE outwf, text

INVOKE ExitProcess,0
EXIT_DIV_ON_NULL:
INVOKE ExitProcess,-1
main ENDP
end main
