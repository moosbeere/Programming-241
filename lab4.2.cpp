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

  ~Weapon() {
    std::cout << "Удаляется" << std::endl;
    display();
  }

  void display() const {
    std::cout << "Оружие: " << name << ", Урон: " << damage
              << ", Вес: " << weight << " кг" << std::endl;
  }

  bool tooHeavy(float maxWeight) const { return weight > maxWeight; }

  float totalWeight(const Weapon &otherWeapon) const {
    return totalWeight(otherWeapon.weight);
  }

  float totalWeight(float otherWeight) const { return weight + otherWeight; }
};

int main() {
  Weapon sword("Крутой меч", 25, 5.8f);
  sword.display();

  Weapon *bow = new Weapon("Длинный лук", 15, 3.2f);
  bow->display();

  float maxCarryWeight = 4.0f;

  if (sword.tooHeavy(maxCarryWeight)) {
    std::cout << "слишком тяжело!" << std::endl;
  } else {
    std::cout << "можно поднять." << std::endl;
  }

  if (bow->tooHeavy(maxCarryWeight)) {
    std::cout << "слишком тяжело!" << std::endl;
  } else {
    std::cout << "можно поднять." << std::endl;
  }

  float totalWeight1 = sword.totalWeight(*bow);
  std::cout << totalWeight1 << std::endl;

  float additionalWeight = 1.5f;
  float totalWeight2 = bow->totalWeight(additionalWeight);
  std::cout << totalWeight2 << std::endl;

  delete bow;

  return 0;
}
