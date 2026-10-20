#pragma once
#include "TransportUnit.h"

class Car :
    public TransportUnit
{
public:
    virtual double calculateToll(double distance) const;
};

