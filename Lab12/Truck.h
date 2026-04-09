#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(std::string brand, int maxSpeed);
    void getStatus() const override;
};