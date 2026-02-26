#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus(const std::string& brand, int maxSpeed, const std::string& route, int capacity, const std::string& fuel)
    : PublicTransport(brand, maxSpeed, route, capacity), Vehicle(brand, maxSpeed), fuelType(fuel) {
}

void Bus::info() {
    PublicTransport::info();
    std::cout << "Fuel: " << fuelType << std::endl;
}