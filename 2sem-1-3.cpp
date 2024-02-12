#include <iostream>

class Cylinder
{
public:

    const int pi = 3.14;

    Cylinder(int radius, int height){
        this->radius = radius;
        this->height = height;
    }

    double volume() const{
        return pi * radius * radius * height;
    }

    double square() const{
        return pi * radius * radius * 2 + 2 * pi * height;
    }

private:
    int radius;
    int height;

};

int main()
{
    int radius, height;
    std::cin >> radius >> height;
    Cylinder t(radius, height);
    std::cout << t.volume() << ' ' << t.surface() << std::endl;
}
