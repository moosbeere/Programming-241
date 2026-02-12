#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Vehicle.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");
	vector<Vehicle> lst;
	string name;
	int mSpeed;

	for (int i = 0; i < 3; ++i) {
		cout << "Введите марку машины: ";
		cin >> name;
		cout << "Введите максимальную скорость: ";
		cin >> mSpeed;
		lst.push_back(Vehicle(name, mSpeed));
	}
	
	lst[0].accelerate(50);
	lst[1].accelerate(100);
	lst[2].accelerate(1000);
	lst[2].brake(1);
	lst[1].brake(5);

	for (Vehicle elem : lst) {
		elem.getStatus();
	}
}

