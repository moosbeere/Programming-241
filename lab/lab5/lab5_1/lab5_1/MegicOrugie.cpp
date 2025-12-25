#include "MegicOrugie.h"

MagicOrugie::MagicOrugie() : Orugie(), DopUron(2) {}

MagicOrugie::MagicOrugie(string n, int d, TypeOrugie t, int du) : Orugie(n, d, t), DopUron(du){}

int MagicOrugie::GetDopUron()
{
	return DopUron;
}


