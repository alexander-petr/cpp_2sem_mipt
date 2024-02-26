#include <string>


enum DifficultyLevel {
    EASY = 1,
    NORMAL = 2,
    HARD = 3
};

class Guns {
public:
    Guns(std::string type,
         std::string id,
         std::string name,
         std::string fire_power,
         int bullets_amount,
         double price,
         DifficultyLevel diff_level): type(type), id(id), name(name), fire_power(fire_power), bullets_amount(bullets_amount), price(price), diff_level(diff_level) {}

    virtual std::string get_fire_power() const;
    virtual std::string get_type() const;
    virtual std::string get_name() const;
    DifficultyLevel get_diff_level() const;
    int get_bullets_amount() const;
    double get_price() const;
    std::string get_id() const;

protected:
    std::string id;
    std::string name;
    std::string type;
    std::string fire_power;
    DifficultyLevel diff_level;
    int bullets_amount;
    double price;
};
