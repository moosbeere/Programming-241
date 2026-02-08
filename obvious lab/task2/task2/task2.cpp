#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
private:
	string brand;
	int maxSpeed;
	int currentSpeed;

public:
	Vehicle(string carsBrand, int MaxSpeed) {
		brand = carsBrand;
		maxSpeed = MaxSpeed;
		currentSpeed = 0;
	}

	void accelerate(int increment) {
		currentSpeed += increment;
		if (currentSpeed > maxSpeed) {
			currentSpeed = maxSpeed;
		}
	}

	void brake(int decrement) {
		currentSpeed -= decrement;
		if (currentSpeed < 0) {
			currentSpeed = 0;
		}
	}

	void getStatus() {
		cout << "mark:" << brand<<" ";
		cout << "speed:" << currentSpeed<<" ";
	}
};



int main() {
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