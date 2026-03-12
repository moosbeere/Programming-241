#ifndef TRUCK_H
#define TRUCK_H

#include "TransportUnit.h"

class Truck : public TransportUnit {
public:
    double calculateToll(double distance) const;
};

#endif#pragma once
