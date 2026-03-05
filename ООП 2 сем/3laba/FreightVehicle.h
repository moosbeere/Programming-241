#ifndef FREIGHTVEHICLE_H
#define FREIGHTVEHICLE_H

#include "Vehicle.h"

class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;          // новое поле — грузоподъёмность

public:
    FreightVehicle(const std::string& b, double capacity);

    // Переопределённый метод getStatus()
    void getStatus();
};

#endif

