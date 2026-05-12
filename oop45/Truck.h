#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include "TransportUnit.h"


// Класс Truck


class Truck : public TransportUnit {
public:

    // Переопределение функции
    double calculateToll(double distance) const override;
};

#endif