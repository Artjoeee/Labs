#include <iostream>
#include <fstream>
#include <cstdint>

struct Data 
{
    long longVar;           // Переменная типа long
    uint8_t uint8Literal;   // Беззнаковый целочисленный литерал
};

int main() 
{
    // Создаем объект данных
    setlocale(0, "RU");
    Data data = { 1234567890, 36 };

    // Открываем файл для бинарной записи
    std::ofstream outFile("data.bin", std::ios::binary);

    if (!outFile) 
    {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return 1;
    }

    // Записываем данные в файл
    outFile.write(reinterpret_cast<char*>(&data), sizeof(Data));
    outFile.close();

    std::cout << "Данные успешно сериализованы в файл 'data.bin'." << std::endl;
    return 0;
}
