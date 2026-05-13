#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

// ======================================================
// Класс Truck
// ======================================================

class Truck : public Vehicle {
public:

    Truck(string n, int speed);

    double calculateToll(double distance) const override;
};

#endif