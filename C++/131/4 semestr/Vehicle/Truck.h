#pragma once
#include "TransportUnit.h"
class Truck :
    public TransportUnit
{
public:
    virtual double calculateToll(double distance) const;
};

