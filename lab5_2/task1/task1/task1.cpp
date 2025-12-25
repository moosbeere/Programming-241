#include "MagicWeapon.h"
#include "OneTimeWeapon.h"
#include <iostream>
#include "WeaponHand.cpp"

int main()
{
	//Weapon w1 = Weapon(); // Ошибка компиляции
	
	MagicWeapon mw1 = MagicWeapon();
	mw1.attack();
	OneTimeWeapon oneTimeWeap = OneTimeWeapon();
	oneTimeWeap.attack();
	oneTimeWeap.attack();

	WeaponHand<int> handT(11, 12);
	WeaponHand<Specific> handT2(Specific::CROSSBOW, Specific::ONEHANDED);
	std::cout << handT.getlhandType() << ' ' << handT.getrhandType() << std::endl;
	//std::cout << handT2.getlhandType() << ' ' << handT2.getrhandType() << std::endl;

	Specific handT2TypeL = handT2.getlhandType();
	if (handT2TypeL == Specific::CROSSBOW) std::cout << "The type in left hand is CROSSBOW" << std::endl;
}