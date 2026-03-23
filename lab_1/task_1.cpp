#include <iostream>

int main()
{
    int i, k;
    int base; // переменная основания степени
    int power(int, int);

    std::cout << "Введите основание степени: ";
    std::cin >> base;

    for (i = 0; i < 10; i++)
    {
        k = power(base, i);
        std::cout << "i = " << i << " k = " << k << std::endl;
    }
}

int power(int x, int n)
{
    int i, p = 1;
    for (i = 0; i < n; i++)
        p *= x;
    return p;
}