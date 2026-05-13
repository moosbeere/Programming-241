#pragma once
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

// ======================================================
// Класс Car
// ======================================================

class Car : public Vehicle {
public:

    Car(string n, int speed);

    double calculateToll(double distance) const override;
};

#endif