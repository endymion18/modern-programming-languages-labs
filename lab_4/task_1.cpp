#include <string.h>
#include <iostream>

// Длина строки
int dlina1(char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        len++;
        s++;
    }
    return len;
}

// Рекурсивная длина строки
int dlina2(char *s)
{
    if (*s == '\0')
    {
        return 0;
    }
    return 1 + dlina2(s + 1);
}

// Длина строки через разность указателей
int dlina3(char *s)
{
    char *start = s;
    while (*s != '\0')
    {
        s++;
    }
    return s - start;
}

// Копирование строки
void kopir(char *str1, const char *str2)
{
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

// Сравнение строк
int sravn(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 < *str2)
        {
            return -1;
        }
        if (*str1 > *str2)
        {
            return 1;
        }
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0')
    {
        return 0;
    }
    if (*str1 == '\0')
    {
        return -1;
    }
    return 1;
}

void konkat(char *str1, char *str2)
{
    while (*str1 != '\0')
    {
        str1++;
    }

    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
}

int task_3()
{
    char *str1 = (char *)malloc(100);
    char *str2 = (char *)malloc(100);

    std::cout << "a[0] = " << (int)str1[0] << std::endl;
    std::cout << "b[0] = " << (int)str2[0] << std::endl;

    str1[0] = '\0'; // обнуляем строки, чтобы функции работали корректно
    str2[0] = '\0';

    std::cout << "длина1 str1 = " << dlina1(str1) << ", str2 = " << dlina1(str2) << std::endl;
    std::cout << "длина2 str1 = " << dlina2(str1) << ", str2 = " << dlina2(str2) << std::endl;
    std::cout << "длина3 str1 = " << dlina3(str1) << ", str2 = " << dlina3(str2) << std::endl;

    std::cout << "до конкатенации: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    konkat(str1, str2);
    std::cout << "после конкатенации str1 = " << str1 << std::endl;

    std::cout << "сравнение str1 и str2: " << sravn(str1, str2) << std::endl;

    free(str1);
    free(str2);
    return 0;
}

int task_4()
{
    char *str1 = (char *)calloc(100, sizeof(char));
    char *str2 = (char *)calloc(100, sizeof(char));

    std::cout << "длина1 str1 = " << dlina1(str1) << ", str2 = " << dlina1(str2) << std::endl;
    std::cout << "длина2 str1 = " << dlina2(str1) << ", str2 = " << dlina2(str2) << std::endl;
    std::cout << "длина3 str1 = " << dlina3(str1) << ", str2 = " << dlina3(str2) << std::endl;

    std::cout << "до конкатенации: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    konkat(str1, str2);
    std::cout << "после конкатенации str1 = " << str1 << std::endl;

    std::cout << "сравнение str1 и str2: " << sravn(str1, str2) << std::endl;

    free(str1);
    free(str2);
    return 0;
}

int main()
{
    char test1[] = "qwerty", test2[] = "1234567890";

    // strlen() возвращает длину строки
    std::cout << "strlen(\"qwerty\") = " << strlen(test1) << std::endl;
    std::cout << "strlen(\"1234567890\") = " << strlen(test2) << std::endl;

    // strcat() конкатенирует (склеивает) строки
    std::cout << "strcat(test1, test2) = " << strcat(test1, test2) << std::endl;

    char buff[100]; // буфер для копирования строк
    std::cout << "buff = " << buff << std::endl;
    std::cout << "strcpy(buff, test1) = " << strcpy(buff, test1) << std::endl;
    std::cout << "buff = " << buff << std::endl;
    strcpy(test1, buff); // восстанавливаем str1

    char str1[] = "qwerty", str2[] = "1234567890";

    std::cout << "длина1 str1 = " << dlina1(str1) << ", str2 = " << dlina1(str2) << std::endl;
    std::cout << "длина2 str1 = " << dlina2(str1) << ", str2 = " << dlina2(str2) << std::endl;
    std::cout << "длина3 str1 = " << dlina3(str1) << ", str2 = " << dlina3(str2) << std::endl;

    std::cout << "до копирования: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    kopir(str1, str2);
    std::cout << "после копирования: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    std::cout << "результат сравнения: " << sravn(str1, str2) << std::endl;

    std::cout << "до конкатенации: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    konkat(str1, str2);
    std::cout << "после конкатенации: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    std::cout << "\nmalloc() и free():" << std::endl;
    task_3();

    std::cout << "\ncalloc() и free():" << std::endl;
    task_4();

    // malloc() и calloc() оба выделяют динамическую память и требуют освобождения через free().
    // Разница в том, что malloc() выделяет неинициализированную память (мусор),
    // а calloc() заполняет выделенную память нулями.
    // Для строк это означает, что после calloc() указатель уже содержит пустую строку,
    // а после malloc() строку нужно инициализировать вручную, иначе работа со строкой некорректна.
}