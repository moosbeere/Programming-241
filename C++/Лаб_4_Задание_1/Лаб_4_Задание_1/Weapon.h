#pragma once
#include <iostream>

using namespace std;

class weapon {
private:
	std::string name;
	float damage;
	int weight;

public:
	void print();
	bool weightChecker(int maxweight);
	int weightSum(weapon& sw);
	int weightSum(int weight);
	void setDamage(int newDamage);

	weapon(string wname = "wepahh", float wdam = 20.989, int wweigh = 1000) {
		this->name = wname;
		this->damage = wdam;
		this->weight = wweigh;
		cout << "weapon has been created;" << endl;
	};

	~weapon();
	std::string getName();
	int getWeight();
	float getDamage();
	friend class Characteristic;
};

class Characteristic {
private:
	int strength;
public:
	Characteristic(int wstr = 0) {
		this->strength = wstr;
	};
	int getStrength();
	int getDamage(weapon& w);
};

class MyMath {
private:
	static int count;
public:
	static int add(int a, int b);
	static int sub(int a, int b);
	static int mult(int a, int b);
	static float div(float a, float b);
	static int getCount();
};
