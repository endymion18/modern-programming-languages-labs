#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Point
{
protected:
    int X;
    int Y;
    std::string Cv;

public:
    Point()
    {
        X = 0;
        Y = 0;
        Cv = "черный";
    }

    Point(int x, int y, std::string cv)
    {
        X = x;
        Y = y;
        Cv = cv;
    }

    void Init(int x, int y, std::string cv)
    {
        X = x;
        Y = y;
        Cv = cv;
    }

    // Чисто виртуальные функции делают класс абстрактным
    virtual void Show() = 0;
    virtual void Hide() = 0;

    void Move(int dx, int dy)
    {
        X += dx;
        Y += dy;
    }

    void Locat(int &x, int &y)
    {
        x = X;
        y = Y;
    }

    void Fly(int x, int y)
    {
        X = x;
        Y = y;
    }
};

class Krug : public Point
{
protected:
    int Radius;

public:
    Krug() : Point()
    {
        Radius = 0;
    }

    Krug(int x, int y, std::string cv, int r) : Point(x, y, cv)
    {
        Radius = r;
    }

    void Init(int x, int y, std::string cv, int r)
    {
        Point::Init(x, y, cv);
        Radius = r;
    }

    void Show() override
    {
        std::cout << "Круг: X = " << X
                  << ", Y = " << Y
                  << ", цвет = " << Cv
                  << ", радиус = " << Radius << std::endl;
    }

    void Hide() override
    {
        std::cout << "Круг скрыт" << std::endl;
    }
};

class Ring : public Krug
{
protected:
    int Width;

public:
    Ring() : Krug()
    {
        Width = 0;
    }

    Ring(int x, int y, std::string cv, int r, int w) : Krug(x, y, cv, r)
    {
        Width = w;
    }

    void Init(int x, int y, std::string cv, int r, int w)
    {
        Krug::Init(x, y, cv, r);
        Width = w;
    }

    void Show() override
    {
        std::cout << "Кольцо: X = " << X
                  << ", Y = " << Y
                  << ", цвет = " << Cv
                  << ", радиус = " << Radius
                  << ", ширина = " << Width << std::endl;
    }

    void Hide() override
    {
        std::cout << "Кольцо скрыто" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Krug k;
    Ring r;

    k.Init(10, 20, "красный", 15);
    r.Init(30, 40, "синий", 25, 5);

    std::cout << "Созданные объекты:" << std::endl;
    k.Show();
    r.Show();

    std::cout << std::endl;
    std::cout << "Проверка виртуальных функций через указатель на базовый класс:" << std::endl;

    Point *ptr;

    ptr = &k;
    ptr->Show();

    ptr = &r;
    ptr->Show();

    std::cout << std::endl;
    std::cout << "Перемещение кольца:" << std::endl;
    r.Move(5, 10);
    r.Show();

    std::cout << std::endl;
    std::cout << "Определение координат кольца:" << std::endl;
    int x, y;
    r.Locat(x, y);
    std::cout << "X = " << x << ", Y = " << y << std::endl;

    std::cout << std::endl;
    std::cout << "Перелет кольца в новую точку:" << std::endl;
    r.Fly(100, 200);
    r.Show();

    std::cout << std::endl;
    std::cout << "Скрытие объектов:" << std::endl;
    k.Hide();
    r.Hide();

    return 0;
}