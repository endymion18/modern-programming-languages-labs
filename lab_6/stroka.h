#ifndef STROKA_H
#define STROKA_H

#include <iostream>

class Stroka
{
    char *str;
    int maxLen;

public:
    Stroka(const char *);
    Stroka();
    Stroka(const Stroka &);
    Stroka(int);
    ~Stroka();

    Stroka &operator=(const Stroka &);
    Stroka &operator+(const Stroka &);
    int operator==(const Stroka &);

    int dlina();
    void vvod();
    void vyvod();
};

#endif