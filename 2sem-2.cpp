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

class Car : private Engine {
public:
    Car(int hp) : Engine(hp) {}

    int get_tax() {
     return TAX_VALUE * get_hp();
    }
};

int main() {
    Engine e(150);

    std::cout << e.get_hp() << std::endl;

    Car c(150);

    std::cout << c.get_tax() << std::endl;
}

