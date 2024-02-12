#include <iostream>
using namespace std;

class Vehicle {
public:
    // ����� �� ������ �� ����
    virtual bool canDrive() const {
        return false;
    }

    // ����� �� �������
    virtual bool canSail() const {
        return false;
    }

    // ����� �� ������
    virtual bool canFly() const {
        return false;
    }

    virtual ~Vehicle() {};
};

class Car: public Vehicle {
public:
    bool canDrive() const {
        return true;
    }
};

class Ship: public Vehicle {
public:
    bool canSail() const {
        return true;
    }
};

class Plane: public Vehicle {
public:
    bool canFly() const {
        return true;
    }
};

class Truck: public Car {};

int main()
{
    cout << boolalpha;
    Vehicle* v;

    v = new Car();
    cout << "Car can drive: " << v->canDrive() << endl;
    cout << "Car can sail: " << v->canSail() << endl;
    cout << "Car can fly: " << v->canFly() << endl;
    delete v;

    v = new Ship();
    cout << "Ship can drive: " << v->canDrive() << endl;
    cout << "Ship can sail: " << v->canSail() << endl;
    cout << "Ship can fly: " << v->canFly() << endl;
    delete v;

    v = new Plane();
    cout << "Plane can drive: " << v->canDrive() << endl;
    cout << "Plane can sail: " << v->canSail() << endl;
    cout << "Plane can fly: " << v->canFly() << endl;
    delete v;

    Car* c = new Truck();
    cout << "Truck can drive: " << c->canDrive() << endl;
    cout << "Truck can sail: " << c->canSail() << endl;
    cout << "Truck can fly: " << c->canFly() << endl;
    delete c;

    return 0;
}
