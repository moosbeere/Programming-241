#include <iostream>
#include <string>
#include"vehicle.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "RU");
	Vehicle automob("HYUNDAI", 300);
	automob.accelerate(100);
	automob.brake(90);
	automob.getStatus();

	FreightVehicle truck("kamaz", 140, 8);
	truck.accelerate(50);
	truck.getStatus();
}