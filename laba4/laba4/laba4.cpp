#include <iostream>
#include "weapon.h"
using namespace ::std;

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
		cout << "\nВес оружия " << weapon1.getName() << " " << "True\n\n";

	cout << "Вес текущего и переданного оружия: " << weapon1.suma_weight(weapon2) << "\n\n";

	cout << "Вес текущего и переданного веса: " << weapon2.suma_weight2(5) << "\n\n";

	cout << "Вес текущего и переданного оружия с перегрузкой: " << weapon1.suma_weight3(weapon2) << "\n\n";

	cout << "Текущий урон: " << weapon1.getdamage() << "\n\n";
	weapon1.setdamage(300);
	cout << "Новый урон: " << weapon1.getdamage() << "\n\n";

	Characteristic char1(25);
	cout << "Сила: " << char1.getStrength() << "\n";

	cout << "Общий урон (сила + урон меча): " << char1.GetDamage(weapon1) << "\n\n";

	cout <<"Сложение " << MyMath::Add(10, 5) << "\n";
	cout <<"Вычитание " << MyMath::Sub(10, 5) << "\n";
	cout <<"Умножение "<< MyMath::Mult(10, 5) << "\n";
	cout <<"Деление "<< MyMath::Div(10, 5) << "\n\n";

	cout << "Вызовы: " << MyMath::getcount() << "\n\n";


}