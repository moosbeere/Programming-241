#include <string>
#include <iostream>
class Weapon {

public:

    std::string name;
    float weight;
    float damage;

    Weapon(std::string name, float damage, float weight) {
        this->name = name;
        this->damage = damage;
        this->weight = weight;
    };

    Weapon() : Weapon("Machinegun", 2, 2) {};

    ~Weapon() {
        std::cout << "Destructor activatd." << std::endl;

    }

    bool check_weight(float weight) {
        return (this->weight <= weight);
    }

    float weight_sum(Weapon w1) {
        return this->weight_sum(w1.weight);
    }
    float weight_sum(float weight) {
        return this->weight + weight;
    }
};


int main()
{
    Weapon w1 = Weapon();
    std::cout << w1.name << std::endl;
    Weapon *w2 = new Weapon("rocketlaucnehr", 100, 5);
    std::cout << w2->name << std::endl;
    delete w2;
    std::cout << std::endl;

    Weapon w3 = Weapon("shaft", 7, 2);
    Weapon w4 = Weapon("Fist", 35, 1);

    std::cout << "w3.check_weight(1): " << w3.check_weight(1) << std::endl;
    std::cout << "w3.weight_sum(w4): " << w3.weight_sum(w4) << std::endl;
    std::cout << "w3.weight_sum(4): " << w3.weight_sum(4) << std::endl;


}

