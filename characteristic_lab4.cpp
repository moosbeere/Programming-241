#include "Characteristic.h"

Characteristic::Characteristic(float sila) : sila(sila) {}

float Characteristic::GetDamage(Orugie o)
{
	return o.getUron() + sila;
}
