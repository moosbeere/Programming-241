#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string n, int s) {
    name = n;
    maxSpeed = s;
}

void Vehicle::printVehicle() const {
    cout << "Название: " << name << ", Макс скорость: " << maxSpeed << endl;
}