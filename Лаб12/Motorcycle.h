#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle();
    string getType() const override;
};