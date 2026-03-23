#include <iostream>

std::tuple<int, int> obmen1(int a, int b)
{
    return std::tuple{b, a};
}

void obmen2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void obmen3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 2, b = 5;
    void obmen2(int *, int *);
    void obmen3(int &, int &);

    std::cout << "До обмена: a = " << a << " b = " << b << std::endl;
    // обменять значения переменных (без указателей или ссылок) возможно только если переприсвоить их через третью переменную
    std::tuple<int, int> new_values = obmen1(a, b);
    a = std::get<0>(new_values);
    b = std::get<1>(new_values);
    std::cout << "После обмена 1: a = " << a << " b = " << b << std::endl;
    obmen2(&a, &b);
    std::cout << "После обмена 2: a = " << a << " b = " << b << std::endl;
    obmen3(a, b);
    std::cout << "После обмена 3: a = " << a << " b = " << b << std::endl;
}