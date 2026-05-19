#pragma once
#ifndef LOGISTICSORDER_H
#define LOGISTICSORDER_H

#include "vehicle.h"

class LogisticsOrder
{
private:
    double weight;

public:
    LogisticsOrder(double w);

    void assignVehicle(Vehicle& v);
};

#endif