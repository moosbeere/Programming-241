#include "FreightVehicle.h"
#include <iostream>
FreightVehicle::FreightVehicle(string brand, int maxSpeed, int cargoCapacity):Vehicle(brand, maxSpeed), cargoCapacity(cargoCapacity)
{

}
void FreightVehicle::getStatus(){
	Vehicle::getStatus();
	std::cout << "CargoCapacity = " << cargoCapacity << std::endl;
}
