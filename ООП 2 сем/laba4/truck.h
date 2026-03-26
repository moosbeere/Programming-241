#ifndef TRUCK_H
#define TRUCK_H

#include "TransportUnit.h"

// Класс грузовика
class Truck : public TransportUnit {
public:
    // Переопределение чисто виртуальной функции
    double calculateToll(double distance) const override;
};

#endif // TRUCK_H
