#include <iostream>
#include "MyMath.h"
#include "Weapon.h"
#include "Characteristic.h"

int main() {
	/* 1 - 8 */
	Weapon w1 = Weapon("Hammer", 228, 25);
	std::cout << "Name=" << w1.getName() << " Damage=" << w1.getDamage() << " Weight=" << w1.getWeight() << std::endl;
	w1.setName("Grinders");
	w1.setDamage(88);
	w1.setWeight(15);
	std::cout << "Name=" << w1.getName() << " Damage=" << w1.getDamage() << " Weight=" << w1.getWeight() << std::endl;

	Weapon w2 = Weapon();
	Weapon& rw2 = w2;
	Weapon* pw1 = &w1;
	Characteristic char1 = Characteristic(5);
	std::cout << "char1.GetDamage(&w1) = " << char1.GetDamage(pw1) << std::endl;
	/* 9 - 13 */
	float res = MyMath::Add(3, 4);
	res = MyMath::Sub(0, res);
	res = MyMath::Div(res, 10);
	res = MyMath::Mult(res, 5);
	std::cout << "res = " << res << " counter = " << MyMath::counter << std::endl;
}