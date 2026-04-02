#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck();
    string getType() const override;
};