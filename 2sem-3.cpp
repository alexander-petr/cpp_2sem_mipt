#include <iostream>

class Car {
public:
    Car() {
        std::cout << "Car constructed" << std::endl;
    }
};

class Truck : virtual public Car {
public:
    Truck() {std::cout << "Truck constructed" << std::endl;}
    Truck(int id) {
        std::cout << "Truck constructed with id " << id << std::endl;
    }
};

class Sedan : virtual public Car {
public:
    Sedan() {std::cout << "Sedan constructed" << std::endl;}
    Sedan(int id) {
        std::cout << "Sedan constructed with id " << id << std::endl;
    }
};

class Pickup : virtual public Sedan, virtual public Truck {
public:
    Pickup() {std::cout << "Pickup constructed" << std::endl;}
    Pickup(int id) : Sedan(id), Truck(id) {
        std::cout << "Pickup constructed with id " << id << std::endl;
    }
};

int main(){
    Pickup p(42);
}
