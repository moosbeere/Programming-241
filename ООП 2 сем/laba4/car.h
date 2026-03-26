#ifndef CAR_H
#define CAR_H

#include "TransportUnit.h"

class Car : public TransportUnit {
public:
    // Переопределение чисто виртуальной функции
    double calculateToll(double distance) const override;
};

#endif 
