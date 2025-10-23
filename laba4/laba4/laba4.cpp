
#include <iostream>
using namespace ::std;

class weapon
{

private:
	string name;
	int weight;
	int damage;

public:
	weapon(string Wname, int Wweight, int Wdamage)
	{
		name = Wname;
		weight = Wweight;
		damage = Wdamage;
	}
	weapon() : weapon("палка", 1, 100000){}

	~weapon() {
		cout << "УДАЛЕНИЕ ОРУЖИЯ" << "\n";
		cout << "Название: " << name << "\n";
		cout << "Урон: " << damage << "\n";
		cout << "Вес: " << weight << "\n\n";
	
	}
	
	string getName() const {
		return name;
	}
	void print()
	{
		cout << "Название: " << name << "\n";
		cout << "Вес: " << weight << "\n";
		cout << "Урон: " << damage << "\n\n";
	}

	int weight_possible() const
	{
		return weight < 50;
	}

	int getweight() const {
		return weight;
	}

	int suma_weight(const weapon& oweapon) const {
		return weight + oweapon.getweight();
	}

	int suma_weight2(int oweight) const {
		return weight + oweight;
	}

	int suma_weight3(const weapon& oweapon) const {
		return suma_weight2(oweapon.getweight());

	}
};

int main()
{
	setlocale(LC_ALL, "RUS");

	weapon weapon1("меч", 10, 20);
	weapon1.print();

	weapon weapon2;
	weapon2.print();

	cout << "================Задание 2================\n";

	weapon* weapon3 = new weapon("камень", 3, 1);
	weapon3->print();
	delete weapon3;
	
	if (weapon1.weight_possible() == 1)
		cout << "\nВес оружия " <<weapon1.getName() << " " << "True\n\n";

	cout << "Вес текущего и переданного оружия: " << weapon1.suma_weight(weapon2) << "\n\n";

	cout << "Вес текущего и переданного веса: " << weapon2.suma_weight2(5) << "\n\n";

	cout << "Вес текущего и переданного оружия с перегрузкой: " << weapon1.suma_weight3(weapon2) << "\n\n";



		
}

