#pragma once
#define TRANSPORTUNIT_H

class TransportUnit {
public:
    virtual ~TransportUnit() = default;
    virtual double calculateToll(double distance) const = 0; // полиморфный метод
};

