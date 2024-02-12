#include <iostream>
#include <vector>

class Animal {
public:
    Animal(int legs_amount): legs_amount(legs_amount) {}
    virtual std::string speak() {
        return "Animal speaks...";
    }
    int get_legs_amount() {
        return legs_amount;
    }
private:
    int legs_amount;
};

class Cat: public Animal {
public:
    Cat(int legs_amount): Animal(legs_amount) {}
    std::string speak(){
        return "Meow";
    }
};

class Dog: public Animal {
public:
    Dog(int legs_amount): Animal(legs_amount) {}
    std::string speak(){
        return "Bark";
    }
};

int main() {
    Dog d(4);
    std::cout << "Dog legs amount:" << d.get_legs_amount() << std::endl;
    std::cout << "Dog speaks:";
    d.speak();
    std::cout << std::endl;

    std::vector<Animal*> animals;
    animals.push_back(&d);

    Cat c(4);
    animals.push_back(&c);

    for (auto i = 0u; i < animals.size(); i++){
            std::cout << "Animal #" << i << " speaks: " << animals[i]->speak() << std::endl;
    }

}
