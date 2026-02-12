#include <iostream>
#include <string>
#include <vector>
#include "transport.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "RU");
	vector <Vehicle> carPark;

	carPark.push_back(Vehicle("BYD", 210));
	carPark.push_back(Vehicle("BMW", 259));
	carPark.push_back(Vehicle("LADA", 250));
	carPark.push_back(Vehicle("AURUS", 290));
	carPark.push_back(Vehicle("AUDI", 150));

	for (int n = 0; n < 5; n++) {
		carPark[n].accelerate(140);
		carPark[n].brake(100);
		carPark[n].getStatus();
	}
}