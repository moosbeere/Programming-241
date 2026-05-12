#pragma once
#ifndef CAR_H
#define CAR_H

#include "TransportUnit.h"


// Класс Car


class Car : public TransportUnit {
public:

    // Переопределение функции
    double calculateToll(double distance) const override;
};

#endif