#include "Weapon.h"
#include <iostream>

using namespace std;

class armour {
public:
	int weight;
	float defence;
	void print() {
		cout << "\nSPECS:\nWEIGHT: " << weight << ";\nDEFENCE: 1" << defence << ";\n";
	}
	armour() {
		this->weight = 200;
		this->defence = 200;
		cout << "armour has been created" << endl;
	}
	~armour() {
		cout << "\narmour has been deleted;";
	}
};

class toolkit {
public:
	int weight;
	float check;
	void print() {
		cout << "\nSPECS:\nWEIGHT: " << weight << ";\nCHECK: 1" << check << ";\n";
	}
	toolkit(int tWeight, float tCheck) {
		this->weight = tWeight;
		this->check = tCheck;
		cout << "toolkit has been created" << endl;
	}
	~toolkit() {
		cout << "\ntoolkit has been deleted;";
	}
};

void weapon::print() {
	cout << "\nSPECS:\nNAME: " << name << ";\nDAMAGE: " << damage << ";\nWEIGHT: " << weight << ";\n";
}
bool weapon::weightChecker(int maxweight) {
	return weight <= maxweight;
}
int weapon::weightSum(weapon& sw) {
	return this->weight - this->weight + weightSum(sw.weight);
}
int weapon::weightSum(int weight) {
	return this->weight + weight;
}
weapon::~weapon() {
	cout << "\nweapon has been deleted;";
}

string weapon::getName() {
	return name;
}
float weapon::getDamage() {
	return damage;
}
int weapon::getWeight() {
	return weight;
}
void weapon::setDamage(int newDamage) {
	damage = newDamage;
}

int Characteristic::getStrength() {
	return strength;
}
int Characteristic::getDamage(weapon& w) {
	return strength + w.damage;
}

int MyMath::count = 0;

int MyMath::add(int a, int b) {
	count++;
	return a + b;
}
int MyMath::sub(int a, int b) {
	count++;
	return a - b;
}
int MyMath::mult(int a, int b) {
	count++;
	return a * b;
}
float MyMath::div(float a, float b) {
	count++;
	return a / b;
}
int MyMath::getCount() {
	return count;
}

int main() {
	setlocale(LC_ALL, "Russian");
	weapon a("Excalibur", 200.278, 200000);
	weapon b;
	weapon* c = new weapon("Brother");
	a.print();
	b.print();
	c->print();

	cout << "\n" << a.weightChecker(3000000) << "\n";
	cout << "Сумма: " << a.weightSum(192483) << endl;

	armour d;
	d.print();

	toolkit e(12, 20.48);
	e.print();
	delete c;

	Characteristic f(25);
	cout << "Сила: " << f.getStrength() << endl;

	cout << "Урон: " << f.getDamage(a) << endl;

	cout << "Сложение " << MyMath::add(23, 2) << endl;
	cout << "Вычитание " << MyMath::sub(23, 2) << endl;
	cout << "Умножение " << MyMath::mult(23, 2) << endl;
	cout << "Деление " << MyMath::div(23, 2) << endl;

	cout << "COUNT: " << MyMath::getCount() << endl;
}