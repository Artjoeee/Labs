.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO :DWORD
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096

.DATA
TEXT_MESSAGE DB "ASM Output", 0
LONG_STR DB "longVar:    ", 0
BYTE_STR DB "uint8Literal:   ", 0

longVar QWORD 1234567890
uint8Literal BYTE 36

.CODE
main PROC
    mov eax, DWORD PTR longVar
    mov edx, DWORD PTR longVar + 4

    mov ecx, 10
    lea esi, LONG_STR + 9
    mov ebx, eax
    xor edx, edx
conv_long:
    div ecx
    add dl, '0'
    dec esi
    mov [esi], dl
    xor edx, edx
    test eax, eax
    jnz conv_long

    invoke MessageBoxA, 0, esi, ADDR TEXT_MESSAGE, 0

    movzx eax, uint8Literal
    mov ecx, 10
    lea esi, BYTE_STR + 13
    xor edx, edx
conv_byte:
    div ecx
    add dl, '0'
    dec esi
    mov [esi], dl
    xor edx, edx
    test eax, eax
    jnz conv_byte

    invoke MessageBoxA, 0, esi, ADDR TEXT_MESSAGE, 0

    push 0
    call ExitProcess
main ENDP
END main
