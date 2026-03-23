#include "FreightVehicle.h"

FreightVehicle::FreightVehicle(double c) : cargoCapacity(c) {}

double FreightVehicle::getCargoCapacity() const {
    return cargoCapacity;
}