#pragma once
#include "Weapon.h"


class OneTimeWeapon : public Weapon
{
	bool isUsed;
public:
	OneTimeWeapon(std::string name, float damage, float weight, Specific type);
	OneTimeWeapon(std::string name, float damage, float weight);
	OneTimeWeapon();
	~OneTimeWeapon();
	void setIsUsed(bool status);
	bool getIsUsed();
	void attack() override;
};

