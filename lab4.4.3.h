#include "lab4.4.2.h"

class Characteristic {
private:
  int strength;

public:
  Characteristic(int strengthValue) : strength(strengthValue) {}

  int getDamage(const Weapon &weapon) const;
};
