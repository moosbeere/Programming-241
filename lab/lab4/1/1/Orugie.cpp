#include "Orugie.h"
#include <iostream>
using namespace std;


string Orugie::getName()
{
	return name;
}

float Orugie::getUron()
{
	return uron;
}

float Orugie::getVes()
{
	return ves;
}

void Orugie::setUron(float ur)
{
	uron = ur;
}

Orugie::Orugie(string name, float uron, float ves) : name(name), uron(uron), ves(ves) {}


Orugie::Orugie() : Orugie("Mech", 5, 3) {}


bool Orugie::maxVes(float max_ves)
{
	return max_ves < ves;
}

float Orugie::peredacha(Orugie o)
{
	return peredacha(o.ves);
}

float Orugie::peredacha(float ves_per)
{
	return this->ves + ves_per;
}
