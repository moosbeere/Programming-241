#pragma once
#include "TransportUnit.h"
class Car : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 2.5; // Например, 2.5 у.е. за км
    }
};

