#include <iostream>
#include <cstdio>
#include <cstring>

void task_1(const char *name)
{
    FILE *in;
    char ch;

    if ((in = fopen(name, "r")) == NULL)
        std::cout << "Файл " << name << " не открыт" << std::endl;
    else
    {
        while ((ch = fgetc(in)) != EOF)
            putchar(ch);

        fclose(in);
    }
}

void task_2(const char *name)
{
    FILE *in;
    char ch;
    int visible = 0;
    int invisible = 0;

    if ((in = fopen(name, "r")) == NULL)
    {
        std::cout << "Файл " << name << " не открыт" << std::endl;
        return;
    }

    while ((ch = fgetc(in)) != EOF)
    {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')
            invisible++;
        else
            visible++;
    }

    std::cout << "Видимых символов: " << visible << std::endl;
    std::cout << "Невидимых символов: " << invisible << std::endl;

    fclose(in);
}

void task_3(const char *name, const char *word)
{
    FILE *in, *out;
    char str[256];
    int line = 0;
    int found = 0;

    if ((in = fopen(name, "r")) == NULL)
    {
        std::cout << "Файл " << name << " не открыт" << std::endl;
        return;
    }

    out = fopen("search_result.txt", "w");

    while (fgets(str, 256, in) != NULL)
    {
        line++;
        if (strstr(str, word) != NULL)
        {
            std::cout << "Строка " << line << ": " << str;
            fprintf(out, "Строка %d: %s", line, str);
            found++;
        }
    }

    if (found == 0)
        std::cout << "Подстрока не найдена" << std::endl;

    fclose(in);
    fclose(out);
}

void task_4(const char *name)
{
    FILE *in, *out;
    char str[256];
    char prev[256] = "";
    int num;
    int has_prev = 0;

    if ((in = fopen(name, "r")) == NULL)
    {
        std::cout << "Файл " << name << " не открыт" << std::endl;
        return;
    }

    out = fopen("pages_result.txt", "w");

    while (fgets(str, 256, in) != NULL)
    {
        if (sscanf(str, "- %d -", &num) == 1)
        {
            if (has_prev)
            {
                fprintf(out, "%s %d\n", prev, num);
                has_prev = 0;
            }
        }
        else
        {
            int len = strlen(str);
            if (len > 0 && str[len - 1] == '\n')
                str[len - 1] = '\0';

            if (has_prev)
                fprintf(out, "%s\n", prev);

            strcpy(prev, str);
            has_prev = 1;
        }
    }

    if (has_prev)
        fprintf(out, "%s\n", prev);

    fclose(in);
    fclose(out);
}

void task_5(const char *in_name, const char *out_name, const char *key)
{
    FILE *in, *out;
    int ch;
    int i = 0;
    int key_len = strlen(key);

    if ((in = fopen(in_name, "rb")) == NULL)
    {
        std::cout << "Файл " << in_name << " не открыт" << std::endl;
        return;
    }

    if ((out = fopen(out_name, "wb")) == NULL)
    {
        std::cout << "Файл " << out_name << " не открыт" << std::endl;
        fclose(in);
        return;
    }

    while ((ch = fgetc(in)) != EOF)
    {
        fputc((unsigned char)ch ^ (unsigned char)key[i], out);
        i++;
        if (i == key_len)
            i = 0;
    }

    fclose(in);
    fclose(out);
}

void task_6(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Недостаточно параметров" << std::endl;
        return;
    }

    task_5(argv[1], "encoded.txt", argv[2]);
    task_5("encoded.txt", "decoded.txt", argv[2]);

    std::cout << "Файл зашифрован и расшифрован" << std::endl;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    std::cout << "Задание 1:" << std::endl;
    task_1("input.txt");

    std::cout << "\nЗадание 2:" << std::endl;
    task_2("input.txt");

    std::cout << "\nЗадание 3:" << std::endl;
    task_3("input.txt", "строка");

    std::cout << "\nЗадание 4:" << std::endl;
    task_4("input.txt");

    std::cout << "\nЗадание 5:" << std::endl;
    task_5("input.txt", "encoded.txt", "key");
    task_5("encoded.txt", "decoded.txt", "key");

    std::cout << "\nЗадание 6:" << std::endl;
    task_6(argc, argv);

    return 0;
}