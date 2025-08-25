#include <iostream>
#include <fstream>
#include <cstdint>

struct Data 
{
    long longVar;           // Переменная типа long
    uint8_t uint8Literal;   // Беззнаковый целочисленный литерал (1 байт)
};

void generateAsm(const Data& data, const std::string& asmFile) 
{
    std::ofstream outFile(asmFile);

    if (!outFile) 
    {
        std::cerr << "Ошибка открытия файла для записи ASM!" << std::endl;
        return;
    }

    outFile << ".586P\n"
        << ".MODEL FLAT, STDCALL\n"
        << "includelib kernel32.lib\n\n"
        << "ExitProcess PROTO :DWORD\n"
        << "MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD\n\n"
        << ".STACK 4096\n\n"
        << ".DATA\n"
        << "TEXT_MESSAGE DB \"ASM Output\", 0\n"
        << "LONG_STR DB \"longVar:    \", 0\n"
        << "BYTE_STR DB \"uint8Literal:   \", 0\n\n"
        << "longVar QWORD " << data.longVar << "\n"
        << "uint8Literal BYTE " << static_cast<int>(data.uint8Literal) << "\n\n"
        << ".CODE\n"
        << "main PROC\n"
        << "    mov eax, DWORD PTR longVar\n"
        << "    mov edx, DWORD PTR longVar + 4\n\n"
        << "    mov ecx, 10\n"
        << "    lea esi, LONG_STR + 9\n"
        << "    mov ebx, eax\n"
        << "    xor edx, edx\n"
        << "conv_long:\n"
        << "    div ecx\n"
        << "    add dl, '0'\n"
        << "    dec esi\n"
        << "    mov [esi], dl\n"
        << "    xor edx, edx\n"
        << "    test eax, eax\n"
        << "    jnz conv_long\n\n"
        << "    invoke MessageBoxA, 0, esi, ADDR TEXT_MESSAGE, 0\n\n"
        << "    movzx eax, uint8Literal\n"
        << "    mov ecx, 10\n"
        << "    lea esi, BYTE_STR + 13\n"
        << "    xor edx, edx\n"
        << "conv_byte:\n"
        << "    div ecx\n"
        << "    add dl, '0'\n"
        << "    dec esi\n"
        << "    mov [esi], dl\n"
        << "    xor edx, edx\n"
        << "    test eax, eax\n"
        << "    jnz conv_byte\n\n"
        << "    invoke MessageBoxA, 0, esi, ADDR TEXT_MESSAGE, 0\n\n"
        << "    push 0\n"
        << "    call ExitProcess\n"
        << "main ENDP\n"
        << "END main\n";

    outFile.close();
    std::cout << "Код успешно сгенерирован в файл '" << asmFile << "'." << std::endl;
}


int main() 
{
    setlocale(0, "RU");
    // Чтение данных из файла
    std::ifstream inFile("C:\\Users\\HomeUser\\Desktop\\КПО\\SE_Asm04\\SE_Asm04\\data.bin", std::ios::binary);

    if (!inFile) 
    {
        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
        return 1;
    }

    Data data;

    // Десериализация данных
    inFile.read(reinterpret_cast<char*>(&data), sizeof(Data));
    inFile.close();

    // Проверяем данные
    std::cout << "Десериализованные данные:\n";
    std::cout << "longVar: " << data.longVar << "\n";
    std::cout << "uint8Literal: " << static_cast<int>(data.uint8Literal) << "\n";

    // Генерация ASM кода
    generateAsm(data, "output.asm");

    return 0;
}
