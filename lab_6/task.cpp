#include "stroka.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Stroka s1("qwert");
    Stroka s3;
    Stroka s4(s1);
    Stroka s5;

    s3.vvod();
    s3.vyvod();
    std::cout << std::endl;

    s5 = s1 + s3 + s4;

    std::cout << "длина s5 = " << s5.dlina() << std::endl;

    s5.vyvod();
    std::cout << std::endl;

    if (s1 == s5)
        std::cout << "строки s1 и s5 равны" << std::endl;
    else
        std::cout << "строки s1 и s5 не равны" << std::endl;

    if (s1 == s4)
        std::cout << "строки s1 и s4 равны" << std::endl;
    else
        std::cout << "строки s1 и s4 не равны" << std::endl;

    std::cout << "задание 4" << std::endl;
    Stroka s6(100);
    s6.vvod();
    s6.vyvod();
    std::cout << std::endl;
    std::cout << "длина s6 = " << s6.dlina() << std::endl;

    return 0;
}