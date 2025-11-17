#include <iostream>
#include "MagicWeapon.h"


int main() {
	Weapon *arr[] = { new Weapon("fist", 47, 3, Specific::TWOHANDED), new Weapon(), new MagicWeapon(), new MagicWeapon("SoES", 2, 10, 44, Specific::TWOHANDED)};
	for (auto w : arr)
	{
		w->printAll();
		std::cout << w->getName() << " TOTAL DAMAGE=" << w->getDamage() << std::endl;

	}
	Weapon w1 = Weapon("fist", 46, 3, Specific::TWOHANDED);
	MagicWeapon w2 = MagicWeapon("SoES", 2, 10, 44, Specific::TWOHANDED);
	Weapon w3 = Weapon("Dark Screamer", 47, 3);
	std::cout << (w1 > w2) << std::endl;
	std::cout << (w3 < w2) << std::endl;
}
