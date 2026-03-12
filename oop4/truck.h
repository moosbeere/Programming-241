#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include "base.h"

class Truck : public Base {
public:
    double calculateToll(double distance) const override;
};

#endif