#include <iostream>
using namespace std;

class TransportUnit {
public:
	virtual double calculateToll(double distance) const = 0;
	virtual ~TransportUnit() {}
		
};

class car :public TransportUnit {
	virtual double calculateToll(double distance) const override { 
		distance = distance * 0.1; 
		return distance;
	}
};

class Truck :public TransportUnit {
	virtual double calculateToll(double distance) const override {
		distance = distance * 0.3 + 5.0;
		return distance;
	}
};

int main() {
	setlocale (LC_ALL,"RU");
	TransportUnit* transports[3];

	transports[0] = new car();
	transports[1] = new Truck();
	transports[2] = new car();

	double distance = 120;

	for (int i = 0; i < 3; i++) {
		double pay = transports[i]->calculateToll(distance);
		cout << "Транспорт: " << i + 1<<endl;
		cout << "Оплата за проезд: " << pay << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete transports[i];
	}
}