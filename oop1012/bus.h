#pragma once
#ifndef BUS_H
#define BUS_H

#include "vehicle.h"
#include "publictransport.h"
#include <string>

class Bus : public Vehicle, public PublicTransport
{
private:
    std::string fuelType;

public:
    Bus(std::string n,
        double maxSpd,
        int route,
        int capacity,
        std::string fuel);

    void info() const override;
};

#endif