#include <string>

class Characteristic;

class Weapon {
private:
  std::string name;
  int damage;
  float weight;

public:
  Weapon(const std::string &weaponName, int weaponDamage, float weaponWeight);
  Weapon();

  ~Weapon();

  std::string getName() const { return name; }
  int getDamage() const { return damage; }
  float getWeight() const { return weight; }

  void setDamage(int newDamage) { damage = newDamage; }

  void display() const;
  bool tooHeavy(float maxWeight) const;
  float totalWeight(const Weapon &otherWeapon) const;
  float totalWeight(float otherWeight) const;

  friend class Characteristic;
};
