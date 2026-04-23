#include "Vehicle.h"
#include "DispatchCenter.h"
#include <iostream>

Vehicle::Vehicle(const std::string& m, const std::string& n)
    : model(m), number(n) {
    registerVehicle();   // регистр при создании объекта
}

void Vehicle::registerVehicle() {
    DispatchCenter::totalVehiclesDispatched++;   
    std::cout << "Зарегистрировано: " << model << " (" << number << ")" << std::endl;
}
