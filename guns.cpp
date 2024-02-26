#include "good.h"
#include <iostream>

Guns::Guns(std::string type,
std::string id,
std::string name,
std::string fire_power,
int bullets_amount,
double price,
DifficultyLevel diff_level): type(type), id(id), name(name), fire_power(fire_power), bullets_amount(bullets_amount), price(price), diff_level(diff_level) {}

virtual std::string get_fire_power() const{
    return "Fire Power: ", fire_power;
}
virtual std::string get_type() const{
    return type;
}
virtual std::string get_name() const{
    return name;
}
DifficultyLevel get_diff_level() const{
    return diff_level;
}
int get_bullets_amount() const{
    return bullets_amount;
}
double get_price() const{
    return price;
}
std::string get_id() const{
    return id;
}
