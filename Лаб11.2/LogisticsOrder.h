#pragma once

#include "Vehicle.h"
#include <stdexcept>

using namespace std;

class LogisticsOrder {
private:
    double weight;

public:
    LogisticsOrder(double w);

    void assignVehicle(Vehicle& v);
};