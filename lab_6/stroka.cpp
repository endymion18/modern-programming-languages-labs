#include "stroka.h"

// свои функции вместо библиотечных
int myStrlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void myStrcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int myStrcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;

    return s1[i] - s2[i];
}

void myStrcat(char *dest, const char *src)
{
    int i = 0;
    while (dest[i] != '\0')
        i++;

    int j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

// конструктор из строки
Stroka::Stroka(const char *s)
{
    maxLen = myStrlen(s) + 1;
    str = new char[maxLen];
    myStrcpy(str, s);
}

// пустой конструктор
Stroka::Stroka()
{
    maxLen = 256;
    str = new char[maxLen];
    str[0] = '\0';
}

// конструктор копирования
Stroka::Stroka(const Stroka &s)
{
    maxLen = s.maxLen;
    str = new char[maxLen];
    myStrcpy(str, s.str);
}

// конструктор с размером
Stroka::Stroka(int size)
{
    maxLen = size;
    str = new char[maxLen];
    str[0] = '\0';
}

// деструктор
Stroka::~Stroka()
{
    delete[] str;
}

// оператор присваивания
Stroka &Stroka::operator=(const Stroka &s)
{
    if (this == &s)
        return *this;

    delete[] str;
    maxLen = s.maxLen;
    str = new char[maxLen];
    myStrcpy(str, s.str);

    return *this;
}

// оператор конкатенации
Stroka &Stroka::operator+(const Stroka &s)
{
    int newLen = myStrlen(str) + myStrlen(s.str) + 1;

    if (newLen > maxLen)
    {
        char *temp = new char[newLen];
        myStrcpy(temp, str);
        delete[] str;
        str = temp;
        maxLen = newLen;
    }

    myStrcat(str, s.str);
    return *this;
}

// оператор сравнения
int Stroka::operator==(const Stroka &s)
{
    if (myStrcmp(str, s.str) == 0)
        return 1;
    else
        return 0;
}

// длина строки
int Stroka::dlina()
{
    return myStrlen(str);
}

// ввод строки
void Stroka::vvod()
{
    std::cout << "Введите строку: ";
    std::cin.getline(str, maxLen);
}

// вывод строки
void Stroka::vyvod()
{
    std::cout << str;
}