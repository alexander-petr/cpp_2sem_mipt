
#include <iostream>

const int TAX_VALUE = 100;

class Engine {
public:
    Engine(int hp): hp(hp) {}
    int get_hp() {
        return hp;
    }
private:
    const int hp;
};

class Car {
public:
    Car(Engine e) : e(e) {}

    int get_tax() {
     return TAX_VALUE * e.get_hp();
    }
private:
    Engine e;
};



int main() {
    Engine e(150);

    std::cout << e.get_hp() << std::endl;

    Car c(e);

    std::cout << c.get_tax() << std::endl;
}

