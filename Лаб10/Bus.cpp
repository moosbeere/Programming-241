#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus(string n, int s, int route, int capacity, string fuel): Vehicle(n, s), PublicTransport(route, capacity) {
    fuelType = fuel;
}

void Bus::print() const {
    cout << "____Автобус____" << endl;
    printVehicle();
    printPublicTransport();
    cout << "Тип топлива: " << fuelType << endl;
}