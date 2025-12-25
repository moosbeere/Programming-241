#include "Orugie.h"
using namespace std;

Orugie::Orugie() : name("Klinok"), uron(0), type(TypeOrugie::ONEHANDED) {}

Orugie::Orugie(string n, int u, TypeOrugie t) : name(n), uron(u), type(t) {}

TypeOrugie Orugie::GetType()
{
	return type;
}

string Orugie::GetName()
{
	return name;
}

int Orugie::GetUron()
{
	return uron;
}

string Orugie::GetTypeString()
{
	if (type == TypeOrugie::ONEHANDED) return "Одноручное оружие";
	else if (type == TypeOrugie::TWOHANDED) return "Двуручное оружие";
	else if (type == TypeOrugie::BOW) return "Лук";
	else if (type == TypeOrugie::CROSSBOW) return "Арбалет";

}




