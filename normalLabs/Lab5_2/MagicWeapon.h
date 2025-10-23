#pragma once
#include "Weapon.h"

class MagicWeapon : public Weapon {
private:
	float extraDamage;
public:
	MagicWeapon() : Weapon(), extraDamage(0) {}
	MagicWeapon(string inputName, float inputDamage, float inputWeight, WeaponType inputType, float extraInput) : Weapon(inputName, inputDamage, inputWeight, inputType), extraDamage(extraInput) {}

	friend ostream& operator<<(ostream& os, const MagicWeapon& weapon);

	virtual float getDamage();
	float getExtraDamage();
	float getTotalDamage();
	void Attack() override;
};
