#include "Weapon.h";


int main() {

    Weapon w1 = Weapon();
    std::cout << w1.name << std::endl;
    Weapon* w2 = new Weapon("rocketlaucnehr", 100, 5);
    std::cout << w2->name << std::endl;
    delete w2;
    std::cout << std::endl;

    Weapon w3 = Weapon("shaft", 7, 2);
    Weapon w4 = Weapon("Fist", 35, 1);
    Weapon* pw4 = &w4;

    std::cout << "w3.check_weight(1): " << w3.check_weight(1) << std::endl;
    std::cout << "w3.weight_sum(w4): " << w3.weight_sum(pw4) << std::endl;
    std::cout << "w3.weight_sum(4): " << w3.weight_sum(4) << std::endl;

}