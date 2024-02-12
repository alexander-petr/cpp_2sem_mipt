#include <cmath>
#include <iostream>

class Point
{
protected:
    int x;
    int y;

public:
    Point(int x, int y): x(x), y(y) {}

    Point operator+(const Point& a) const {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }

    double dist() const {
        return sqrt(x * x + y * y);
    }
};

class Triangle
{
public:
    // Создать треугольник из трёх точек
    Triangle(const Point& a, const Point& b, const Point& c){
        this->a = (b - a).dist();
        this->b = (c - b).dist();
        this->c = (a - c).dist();
    }

    // Посчитать и вернуть периметр треугольника
    double perimeter() const{
        return a + b + c;
    }

private:
    double a, b, c;
};


int main()
{
    Point a(0, 0), b(0, 5), c(5, 0);
    Triangle t(a, b, c);
    std::cout << t.perimeter() << std::endl;
    return 0;
}
