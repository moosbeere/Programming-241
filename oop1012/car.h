#pragma once
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
public:
    Car(std::string n,
        double maxSpd);

    void accelerate(double value) override;
};

#endif