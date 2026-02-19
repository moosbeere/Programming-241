#pragma once
#include "TransportUnit.h"

class Truck : public TransportUnit {
public:
    double calculateToll(double distance) const override;
    std::string getDescription() const override;
};