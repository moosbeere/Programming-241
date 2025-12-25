#pragma once
#include <iostream>
#include "Orugie.h"
using namespace std;


class Characteristic
{
public:
	float sila;
	Characteristic(float sila);

	float GetDamage(Orugie o);
};
#pragma once
