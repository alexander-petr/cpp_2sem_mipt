#include <iostream>
#include <vector>
#include "guns.h"
#include <fstream>

class AmmunitionStorage {
public:
    unsigned get_guns_amount() const{
        return guns.size();
    }

    std::string add_gun(Guns item) {
        guns.push_back(item);
        return guns[guns.size() - 1].get_id();
    }

    Guns* get_gun(std::string id){
        for (auto& item : guns) {
            if (item.get_id() == id) {
                return &item;
            }
        }
        return nullptr;
    }
    void save_to_file(std::string filepath) {
        std::ofstream fout(filepath);

        for (auto& item: guns) {
            fout << item.to_string() << std::endl;
        }

        fout.close();
    }
private:
    std::vector<Guns> guns;
};


int main(){
    AmmunitionStorage storage;

    int n;
    std::cout << "Input amount of items" << std::endl;
    std::cin >> n;

    for (int i = 0; i < n; i++){
        std::string id, name, type, fire_power;
        double price;
        int bullets_amount;
        unsigned amount;

        std::cout << "Input item" << std::endl;
        std::cin >> id >> name >> amount >> price >> fire_power >> bullets_amount;

        std::cout << "Item added successfully!" << std::endl;
    }
    std::cout << "Input ID" << std::endl;
    std::string id;
    std::cin >> id;

    Guns* found = storage.get_gun(id);
    if (found) {
        std::cout << found->get_name() << std::endl;
    } else {
        std::cout << "Can't find it" << std::endl;
    }

    std::cout << "Name of file: " << std::endl;
    std::string name;
    std::cin >> name;
    storage.save_to_file(name);
}
