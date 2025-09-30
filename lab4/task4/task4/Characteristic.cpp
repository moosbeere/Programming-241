#include "Characteristic.h"

Characteristic::Characteristic(int str) 
{
	this->strange = str;
}
float Characteristic::GetDamage(Weapon* w)
{
	return (*w).damage + (this->strange);
}