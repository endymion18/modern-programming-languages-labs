#include <iostream>
#include <fstream>
#include <string>

class Stroka
{
private:
    std::string str;

public:
    Stroka()
    {
        str = "";
    }

    Stroka(std::string s)
    {
        str = s;
    }

    int dlina()
    {
        return str.length();
    }

    void vyvod()
    {
        std::cout << str;
    }

    // Перегрузка вывода в поток
    friend std::ostream &operator<<(std::ostream &out, const Stroka &s)
    {
        out << s.str;
        return out;
    }

    // Перегрузка ввода из потока
    friend std::istream &operator>>(std::istream &in, Stroka &s)
    {
        in >> s.str;
        return in;
    }
};

// Шифрование/дешифрование файла через потоки
void shifr(std::string in_name, std::string out_name, std::string key)
{
    std::ifstream fin(in_name, std::ios::binary);
    std::ofstream fout(out_name, std::ios::binary);

    if (!fin.is_open())
    {
        std::cout << "Файл " << in_name << " не открыт" << std::endl;
        return;
    }

    if (!fout.is_open())
    {
        std::cout << "Файл " << out_name << " не открыт" << std::endl;
        fin.close();
        return;
    }

    int i = 0;
    int key_len = key.length();
    char ch;

    while (fin.get(ch))
    {
        ch = ch ^ key[i];
        fout.put(ch);

        i++;
        if (i == key_len)
            i = 0;
    }

    fin.close();
    fout.close();
}

// Проверка состояния потока
void proverka_potoka(std::string file_name)
{
    std::ifstream fin(file_name);

    std::cout << "Проверка состояния потока для файла " << file_name << ":" << std::endl;

    if (fin.good())
        std::cout << "Поток в хорошем состоянии" << std::endl;

    if (fin.fail())
        std::cout << "Ошибка чтения файла" << std::endl;

    if (fin.bad())
        std::cout << "Критическая ошибка потока" << std::endl;

    if (fin.eof())
        std::cout << "Достигнут конец файла" << std::endl;

    char ch;
    while (fin.get(ch))
        std::cout << ch;

    std::cout << std::endl;

    if (fin.eof())
        std::cout << "После чтения: достигнут конец файла" << std::endl;

    fin.close();
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "Работа с классом Stroka:" << std::endl;
    Stroka s1("Пример");
    Stroka s2;

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "Введите строку s2: ";
    std::cin >> s2;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "Длина s2 = " << s2.dlina() << std::endl;

    std::cout << std::endl;
    std::cout << "Шифрование файла:" << std::endl;
    shifr("input.txt", "encoded.txt", "key");
    shifr("encoded.txt", "decoded.txt", "key");
    std::cout << "Файлы encoded.txt и decoded.txt созданы" << std::endl;

    std::cout << std::endl;
    proverka_potoka("input.txt");

    return 0;
}