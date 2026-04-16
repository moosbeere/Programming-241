#pragma once
#include "DispatchCenter.h"
#include <string>

class Vehicle {
private:
    std::string model;
public:
    Vehicle(std::string m) : model(m) {
        DispatchCenter::registerVehicle();
    }
};
