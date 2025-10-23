#pragma once
#include "Weapon.h"

class OneTimeWeapon : Weapon {
private:
	bool used;
public:
	OneTimeWeapon(string inputName, float inputDamage, float inputWeight, WeaponType inputType, bool inputUsed=false) : Weapon(inputName, inputDamage, inputWeight, inputType), used(inputUsed) {}
	OneTimeWeapon() : Weapon(), used(false) {}
	
	friend ostream& operator<<(ostream& os, const OneTimeWeapon& weapon);

	void Attack() override;
};