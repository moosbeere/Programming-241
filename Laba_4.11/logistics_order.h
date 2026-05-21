#pragma once
#include "freight_vehicle.h"
#include <stdexcept>
using namespace std;

class LogisticsOrder {
private:
    double weight;

public:
    LogisticsOrder(double w);
    void assignVehicle(const FreightVehicle& vehicle);
};
