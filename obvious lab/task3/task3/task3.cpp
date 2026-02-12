#include <iostream>
#include <string>
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
		cout << "mark:" << brand;
		cout << "speed:" << currentSpeed;
	}
};

class FreightVehicle : public Vehicle {
private:
	int CargoCapacity;
	
public:
	FreightVehicle(string vehBrand, int vehSpeed, int capacity) :  Vehicle(vehBrand, vehSpeed) {
		CargoCapacity = capacity;
	}

	void getStatus() {
		Vehicle::getStatus();
		cout << "Freight" << CargoCapacity<<"tonn";
}
};

int main() {
	Vehicle automob("HYUNDAI", 300);
	automob.accelerate(100);
	automob.brake(90);
	automob.getStatus();

	FreightVehicle truck("kamaz", 140, 8);
	truck.getStatus();
}