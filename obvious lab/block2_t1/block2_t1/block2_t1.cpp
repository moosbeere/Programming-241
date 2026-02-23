#include <iostream>
using namespace std;
#include "Unit.h"


int main() {
	setlocale (LC_ALL,"RU");
	TransportUnit* transports[3];

	transports[0] = new car();
	transports[1] = new Truck ();
	transports[2] = new car();

	double distance = 120;

	for (int i = 0; i < 3; i++) {
		double pay = transports[i]->calculateToll(distance);
		cout << "дистанция" << distance << endl;
		cout << "Транспорт: " << i + 1<<endl;
		cout << "Оплата за проезд: " << pay << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete transports[i];
	}
}
