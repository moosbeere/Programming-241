#pragma once
#include <string>

using namespace std;

class TransportUnit {
public:
    virtual double calculateToll(double distance) const = 0;
    virtual string getDescription() const {
        return "Транспортное средство";
    }
};