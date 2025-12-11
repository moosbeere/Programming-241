#include "Characteristic.h"

//Также добавьте конструктор, который будет инициализировать это поле переданным значением.
Characteristic::Characteristic(float sila) : sila(sila) {}

float Characteristic::GetDamage(Orugie o)
{
	return o.getUron() + sila;
}

