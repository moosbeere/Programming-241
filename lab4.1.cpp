#include <iostream>
#include <string>

class Weapon {
private:
  std::string name;
  int damage;
  float weight;

public:
  Weapon(const std::string &wName, int wDamage, float wWeight) {
    name = wName;
    damage = wDamage;
    weight = wWeight;
  }

  Weapon() : Weapon("Меч", 10, 2.5f) {}

  void display() const {
    std::cout << "Оружие: " << name << ", Урон: " << damage
              << ", Вес: " << weight << " кг" << std::endl;
  }
};

int main() {
  Weapon sword("Меч", 25, 5.8f);
  Weapon defaultWeapon;

  sword.display();

  defaultWeapon.display();

  return 0;
}
