#include "lab4.3.2.h"
#include <iostream>

int main() {
  Weapon sword("Двуручный меч", 25, 5.8f);
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
