#pragma once
#include <iostream>
#include "Orugie.h"
using namespace std;

// Создайте класс Characteristic, имеющий одно поле: силу
class Characteristic
{
public:
	float sila;
	Characteristic(float sila);

	float GetDamage(Orugie o);
};

