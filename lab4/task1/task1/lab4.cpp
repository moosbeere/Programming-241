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
};


int main()
{
    Weapon w1("nailgun", 1337, 2.28);
    Weapon w2;
    std::cout << "Name: " << w1.name << " Damage: " << w1.damage << " Weight: " << w1.weight << std::endl;
    std::cout << "Name: " << w2.name << " Damage: " << w2.damage << " Weight: " << w2.weight;

    
}

