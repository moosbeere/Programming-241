#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    string getType() const override;
};