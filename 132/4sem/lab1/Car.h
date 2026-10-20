#pragma once
#include "TransportUnit.h"
#include <iostream>

class Car :
    public TransportUnit
{
private:
    std::string brand;
public:
    Car(std::string brand);
    double calculateToll(double distance) const override;
};

