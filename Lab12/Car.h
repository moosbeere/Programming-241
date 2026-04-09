#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(std::string brand, int maxSpeed);
    void getStatus() const override;
};