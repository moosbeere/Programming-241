#include "weapon.h"

weapon::weapon(string Wname, int Wweight, int Wdamage)
{
	name = Wname;
	weight = Wweight;
	damage = Wdamage;
}

weapon::weapon() : weapon("палка", 1, 100000) {}

weapon::~weapon() {
	cout << "УДАЛЕНИЕ ОРУЖИЯ" << "\n";
	cout << "Название: " << name << "\n";
	cout << "Урон: " << damage << "\n";
	cout << "Вес: " << weight << "\n\n";
}

string weapon::getName() const {
	return name;
}
int weapon::getweight() const {
	return weight;
}
int weapon::getdamage() const {
	return damage;
}

void weapon::print()
{
	cout << "Название: " << name << "\n";
	cout << "Вес: " << weight << "\n";
	cout << "Урон: " << damage << "\n\n";
}

int weapon::weight_possible() const
{
	return weight < 50;
}



int weapon::suma_weight(const weapon& oweapon) const {
	return weight + oweapon.getweight();
}

int weapon::suma_weight2(int oweight) const {
	return weight + oweight;
}

int weapon::suma_weight3(const weapon& oweapon) const {
	return suma_weight2(oweapon.getweight());

}

void weapon::setdamage(int newdamage) {
	damage = newdamage;
}

Characteristic::Characteristic(int str) : strength(str) {}

int Characteristic::getStrength() const {
	return strength;
}

int Characteristic::GetDamage(const weapon& w) const {
	return strength + w.damage;
}

int MyMath::count = 0;

int MyMath::Add(int a, int b) {
	count++;  
	return a + b;
}

int MyMath::Sub(int a, int b) {
	count++;  
	return a - b;
}

int MyMath::Mult(int a, int b) {
	count++;  
	return a * b;
}

double MyMath::Div(int a, int b) {
	count++;  
	return a / b;
}

int MyMath::getcount() {
	return count;
}