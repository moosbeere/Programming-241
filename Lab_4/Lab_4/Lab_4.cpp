//ЗАДАНИЕ 1
#include <iostream>
#include <string>
using namespace std;

//1. Создание класса оружия: название оружия, наносимый урон, вес оружия
class Orygie {
public:
	std::string name;
	int yron;
	float ves;

	//2. Создание констуруктора, принимающего 3 параметра и использующего их для инициализации переменных класса
	Orygie(string name, float yron, float ves) {
		this->name = name;
		this->yron = yron;
		this->ves = ves;
	};

}

