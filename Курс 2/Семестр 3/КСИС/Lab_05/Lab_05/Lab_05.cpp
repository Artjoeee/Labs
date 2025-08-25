#define _WINSOCK_DEPRECATED_NO_WARNINGS // Отключаем предупреждения для устаревших функций WinSock
#include <iostream>
#include <winsock2.h>                   // Подключаем библиотеку для работы с WinSock API
#include <iphlpapi.h>                   // Подключаем библиотеку для работы с IP Helper API
#include <icmpapi.h>                    // Подключаем библиотеку для работы с ICMP API (пингование)
#include <conio.h>                      // Подключаем библиотеку для работы с функциями консоли
#include <cstring>

#pragma comment(lib, "iphlpapi.lib")    // Подключаем библиотеку IP Helper API
#pragma comment(lib, "ws2_32.lib")      // Подключаем библиотеку WinSock 2.0

// Определяем коды состояния ICMP, используемые в программе
#define IP_STATUS_BASE 11000
#define IP_SUCCESS 0
#define IP_DEST_NET_UNREACHABLE 11002
#define IP_DEST_HOST_UNREACHABLE 11003
#define IP_DEST_PROT_UNREACHABLE 11004
#define IP_DEST_PORT_UNREACHABLE 11005
#define IP_REQ_TIMED_OUT 11010
#define IP_BAD_REQ 11011
#define IP_BAD_ROUTE 11012
#define IP_TTL_EXPIRED_TRANSIT 11013

using namespace std;

// Функция Ping выполняет отправку ICMP-запросов для пингования указанного узла (хоста)
void Ping(const char* cHost, unsigned int Timeout, unsigned int RequestCount)
{
    HANDLE hIP = IcmpCreateFile(); // Создаем дескриптор для ICMP-запросов

    if (hIP == INVALID_HANDLE_VALUE) // Проверяем, удалось ли создать дескриптор
    {
        WSACleanup(); // Завершаем использование WinSock
        cerr << "Ошибка: не удалось создать ICMP-файл.\n";
        return;
    }

    char SendData[32] = "Data for ping"; // Данные, отправляемые в ICMP-запросе (не обязательное поле)

    int LostPacketsCount = 0; // Счетчик потерянных пакетов
    unsigned int MaxMS = 0;   // Максимальное время ответа (в миллисекундах)
    int MinMS = -1;           // Минимальное время ответа (инициализируется значением -1)

    // Выделяем память для структуры ICMP_ECHO_REPLY, где будут храниться ответы ICMP
    PICMP_ECHO_REPLY pIpe = (PICMP_ECHO_REPLY)GlobalAlloc(GHND, sizeof(ICMP_ECHO_REPLY) + sizeof(SendData));

    if (pIpe == 0) // Проверяем, удалось ли выделить память
    {
        IcmpCloseHandle(hIP); // Закрываем дескриптор ICMP
        WSACleanup();         // Очищаем ресурсы WinSock
        cerr << "Ошибка: не удалось выделить память для ответа.\n";
        return;
    }

    pIpe->Data = SendData;                 // Указываем данные, которые будут переданы в ICMP-запросе
    pIpe->DataSize = sizeof(SendData);     // Задаем размер данных для ICMP-запроса

    unsigned long ipaddr = inet_addr(cHost); // Преобразуем IP-адрес хоста в числовой формат

    // Структура опций IP: задаем TTL (Time-To-Live) равный 128
    IP_OPTION_INFORMATION option = { 64, 0, 0, 0, nullptr };

    for (unsigned int c = 0; c < RequestCount; c++) // Выполняем указанное количество запросов
    {
        // Отправляем ICMP-запрос и получаем результат
        int dwStatus = IcmpSendEcho(hIP, ipaddr, SendData, sizeof(SendData), &option, pIpe, sizeof(ICMP_ECHO_REPLY) + sizeof(SendData), Timeout);

        if (dwStatus > 0) // Если запрос успешен и получен ответ
        {
            for (int i = 0; i < dwStatus; i++) // Обрабатываем каждый ответ (если их несколько)
            {
                // Получаем IP-адрес в формате четырех байт
                unsigned char* pIpPtr = (unsigned char*)&pIpe->Address;

                cout << "Ответ от " << (int)*(pIpPtr) << "." << (int)*(pIpPtr + 1) << "." << (int)*(pIpPtr + 2) << "." << (int)*(pIpPtr + 3)
                    << ": число байт = " << pIpe->DataSize << " время = " << pIpe->RoundTripTime << " мс TTL = " << (int)pIpe->Options.Ttl << endl;

                // Обновляем значения минимального и максимального времени ответа
                MaxMS = (MaxMS > pIpe->RoundTripTime) ? MaxMS : pIpe->RoundTripTime;
                MinMS = (MinMS < (int)pIpe->RoundTripTime && MinMS >= 0) ? MinMS : pIpe->RoundTripTime;
            }
        }
        else // Если запрос завершился с ошибкой (ответ не получен)
        {
            LostPacketsCount++; // Увеличиваем счетчик потерянных пакетов

            // Обрабатываем код ошибки и выводим соответствующее сообщение
            switch (pIpe->Status)
            {
            case IP_DEST_NET_UNREACHABLE:
            case IP_DEST_HOST_UNREACHABLE:
            case IP_DEST_PROT_UNREACHABLE:
            case IP_DEST_PORT_UNREACHABLE:
                cout << "Remote host may be down." << endl;
                break;
            case IP_REQ_TIMED_OUT:
                cout << "Request timed out." << endl;
                break;
            case IP_TTL_EXPIRED_TRANSIT:
                cout << "TTL expired in transit." << endl;
                break;
            default:
                cout << "Error code: " << pIpe->Status << endl;
                break;
            }
        }
    }

    // Закрываем дескриптор ICMP и освобождаем ресурсы WinSock
    IcmpCloseHandle(hIP);
    WSACleanup();

    if (MinMS < 0) // Если минимальное время ответа не было установлено, задаем его равным 0
        MinMS = 0;

    unsigned char* pByte = (unsigned char*)&pIpe->Address; // Получаем IP-адрес для отображения статистики

    cout << "Статистика Ping " << (int)*(pByte) << "." << (int)*(pByte + 1) << "." << (int)*(pByte + 2) << "." << (int)*(pByte + 3) << std::endl;
    cout << "\tПакетов: отправлено = " << RequestCount
        << ", получено = " << RequestCount - LostPacketsCount
        << ", потеряно = " << LostPacketsCount
        << " <" << (int)(100 / (float)RequestCount) * LostPacketsCount << "% потерь>" << endl;

    cout << "Приблизительное время приема-передачи:\nМинимальное = " << MinMS
        << " мс, Максимальное = " << MaxMS
        << " мс, Среднее = " << (MaxMS + MinMS) / 2 << " мс" << endl;
}

int main(int argc, char** argv)
{
    setlocale(0, "RU");

    // Проверяем количество аргументов командной строки
    if (argc != 4)
    {
        std::cerr << "Использование: " << argv[0] << " <адрес хоста> <таймаут в мс> <кол-во запросов>\n";
        return 1;
    }

    // Считываем параметры: IP-адрес, таймаут и количество запросов
    const char* cHost = argv[1];
    unsigned int Timeout = static_cast<unsigned int>(atoi(argv[2]));
    unsigned int RequestCount = static_cast<unsigned int>(atoi(argv[3]));

    Ping(cHost, Timeout, RequestCount);

    return 0;
}
