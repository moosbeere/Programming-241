#include <iostream>
#include "Weapon.h"
#include "Player.cpp"
#include "MagicWeapon.h"

int main() {
	
	Weapon w1 = Weapon();
	if (w1.getType() == Specific::ONEHANDED)
	{
		std::cout << "ONEHANDED";
	}

	Player player1{ 228, "tarakan", "zamza" };
	player1.print();

	MagicWeapon mw1 = MagicWeapon();
	MagicWeapon mw2 = MagicWeapon("Staff of Evil Spriit", 10, 8, 44);
	std::cout << "mw1 name=" << mw1.getName() << "\n" << "mw1 dmg=" << mw1.getDamage() << "\n"
		<< "mw1 extra damage= " << mw1.getExtraDmg() << "\n" << "mw1 weight=" << mw1.getWeight()
		<< std::endl;
	mw1.setExtraDmg(10);
	std::cout << "mw1.setExtaDmg(10)" "\n" "mw1 extra damage=" << mw1.getExtraDmg() << std::endl;
	std::cout << "mw2 name=" << mw2.getName() << "\n" << "mw2 dmg=" << mw2.getDamage() << "\n"
		<< "mw2 extra damage= " << mw2.getExtraDmg() << "\n" << "mw2 weight=" << mw2.getWeight()
		<< std::endl;
}