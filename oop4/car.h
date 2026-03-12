#pragma once
#ifndef CAR_H
#define CAR_H

#include "base.h"

class Car : public Base {
public:
    double calculateToll(double distance) const override;
};

#endif