#include <iostream>
#include <bitset>

using namespace std;

unsigned long ip, mask;

unsigned long CharToLong(char* ip_)
{
    unsigned long out = 0;
    char* buff;
    buff = new char[3];

    for (int i = 0, j = 0, k = 0; ip_[i] != '\0'; i++, j++)
    {
        if (ip_[i] != '.')
            buff[j] = ip_[i];

        if (ip_[i] == '.' || ip_[i + 1] == '\0')
        {
            out <<= 8;
            if (atoi(buff) > 255)
                return NULL;
            out += (unsigned long)atoi(buff);
            k++;
            j = -1;
            delete[]buff;
            buff = new char[3];
        }
    }

    return out;
}

bool CheckAddress(char* ip_)
{
    int points = 0, numbers = 0;

    char* buff = new char[3];

    for (int i = 0; ip_[i] != '\0'; i++)
    {
        if (ip_[i] <= '9' && ip_[i] >= '0')
        {
            if (numbers > 3) 
                return false;

            buff[numbers++] = ip_[i];
        }
        else
            if (ip_[i] == '.')
            {
                if (atoi(buff) > 255)
                    return false;

                if (numbers == 0)
                    return false;

                numbers = 0;
                points++;
                delete[]buff;
                buff = new char[3];
            }
            else 
                return false;
    }
    if (points != 3)
        return false;

    if (numbers == 0 || numbers > 3)
        return false;

    return true;
}

bool checkMask(char* mask_)
{
    int points = 0, numbers = 0;
    char* buff = new char[3];

    for (int i = 0; mask_[i] != '\0'; i++)
    {
        if (mask_[i] <= '9' && mask_[i] >= '0')
        {
            if (numbers > 3) 
                return false;

            buff[numbers++] = mask_[i];
        }
        else
            if (mask_[i] == '.' || mask_[i] == '\0')
            {
                if (atoi(buff) > 255)
                    return false;

                if (numbers == 0)
                    return false;

                numbers = 0;
                points++;
                delete[]buff;
                buff = new char[3];
            }
            else 
                return false;
    }

    unsigned long mask = CharToLong(mask_);
    bitset<32> bytemask = (bitset<32>(mask));

    if (points != 3)
        return false;

    if (numbers == 0 || numbers > 3)
        return false;

    for (size_t i = 31; i >= 1; i--)
    {
        if (bytemask[i] == 0 && bytemask[i - 1] == 1)
            return false;

    }

    return true;
}

int main()
{
    setlocale(0, "");

    unsigned long ip, mask;
    char* ip_ = new char[16], * mask_ = new char[16]; 
    bool flag = true;

    do
    {
        if (!flag) 
            cout << "Неверно введён IP-адрес!" << endl;

        cout << "Введите ваш IP-адрес: ";
        cin >> ip_;

    } while (!(flag = CheckAddress(ip_)));

    do
    {
        if (!flag) 
            cout << "Неверно введена маска!" << endl;

        cout << "Введите маску в формате через точку: ";
        cin >> mask_;

    } while (!(flag = checkMask(mask_)));

    mask = CharToLong(mask_);
    ip = CharToLong(ip_);

    bitset<32> byteip = (bitset<32>(ip));
    bitset<32> bytemask = (bitset<32>(mask));

    bitset<32>subnet = byteip & bytemask;
    bitset<32>host = byteip & ~bytemask;
    bitset<32> broadcast = (byteip & bytemask | ~bytemask);

    bitset<8> byte1, byte2, byte3, byte4, byte5, byte6, byte7, byte8;
    bitset<8> broadcast1, broadcast2, broadcast3, broadcast4;

    for (short i = 31, j = 7; i >= 24; i--, j--)
    {
        byte1[j] = subnet[i];
        byte2[j] = subnet[i - 8];
        byte3[j] = subnet[i - 16];
        byte4[j] = subnet[i - 24];

        byte5[j] = host[i];
        byte6[j] = host[i - 8];
        byte7[j] = host[i - 16];
        byte8[j] = host[i - 24];

        broadcast1[j] = broadcast[i];
        broadcast2[j] = broadcast[i - 8];
        broadcast3[j] = broadcast[i - 16];
        broadcast4[j] = broadcast[i - 24];

    }

    cout << "Ваш Network ID: " << byte1.to_ulong() << "." << byte2.to_ulong() << "." << byte3.to_ulong() << "." << byte4.to_ulong() << endl;
    cout << "Ваш Host ID: " << byte5.to_ulong() << "." << byte6.to_ulong() << "." << byte7.to_ulong() << "." << byte8.to_ulong() << endl;

    cout << "Ваш Broadcast ID: " << broadcast1.to_ulong() << "." << broadcast2.to_ulong() << "." << broadcast3.to_ulong() << "." << broadcast4.to_ulong() << endl;

    return 0;
}
