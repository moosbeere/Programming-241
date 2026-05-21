#include "freight_vehicle.h"

FreightVehicle::FreightVehicle(string n, double capacity) : name(n), cargoCapacity(capacity) {
}

double FreightVehicle::getCargoCapacity() const {
    return cargoCapacity;
}

string FreightVehicle::getName() const {
    return name;
}
