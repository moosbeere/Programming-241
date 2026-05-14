#ifndef CAR_H
#define CAR_H

#include "TransportUnit.h"

class Car : public TransportUnit {
public:
    Car(std::string name, int maxSpeed);

    double calculateToll(double distance) const override;
    void info() const override;
};

#endif#pragma once
