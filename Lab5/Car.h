#pragma once
#include <string>
#include "TransportUnit.h"

class Car : public TransportUnit {
private:
    std::string brand;
public:
    Car(const std::string& b);
    double calculateToll(double distance) const override;
    std::string getDescription() const override;
    std::string getBrand() const { return brand; }
};