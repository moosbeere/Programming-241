#include <string>

class Weapon {
private:
  std::string name;
  int damage;
  float weight;

public:
  Weapon(const std::string &weaponName, int weaponDamage, float weaponWeight);
  Weapon();

  ~Weapon();

  void display() const;

  bool tooHeavy(float maxWeight) const;

  float totalWeight(const Weapon &otherWeapon) const;
  float totalWeight(float otherWeight) const;
};
