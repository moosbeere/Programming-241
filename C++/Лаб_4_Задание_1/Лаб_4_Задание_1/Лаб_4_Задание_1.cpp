#include <iostream>
#include <string>

using namespace std;

class weapon {
public:
	string name;
	float damage;
	int weight;
	void print() {
		cout << "\nSPECS:\nNAME: " << name << ";\nDAMAGE: " << damage << ";\nWEIGHT: " << weight << ";\n";
	}
	int weightChecker(int maxweight) {
		return weight <= maxweight;
	}
	weapon(string wname = "wepahh", float wdam = 20.989, int wweigh = 1000) {
		this->name = wname;
		this->damage = wdam;
		this->weight = wweigh;
		cout << "weapon has been created;" << endl;
	}
	~weapon() {
		cout << "\nweapon has been deleted;";
	}
};

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

int main() {
	setlocale(LC_ALL, "Russian");
	weapon a("Excalibur", 200.278, 200000);
	weapon b;
	weapon* c = new weapon("Brother");
	a.print();
	b.print();
	c->print();

	cout << "\n" << a.weightChecker(3000000) << "\n";

	armour d;
	d.print();

	toolkit e(12, 20.48);
	e.print();
	delete c;
}
