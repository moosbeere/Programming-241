#ifndef CAR_H
#define CAR_H

#include "TransportUnit.h"

// Класс легкового автомобиля
class Car : public TransportUnit {
public:
    // Переопределение чисто виртуальной функции
    double calculateToll(double distance) const override;
};

#endif // CAR_H
