#pragma once
#ifndef TRAFFICFLOW_H
#define TRAFFICFLOW_H

#include <vector>
#include <memory>

#include "vehicle.h"
#include "roadsegment.h"

class TrafficFlow
{
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    RoadSegment road;

public:
    TrafficFlow(RoadSegment r);

    void addVehicle(std::unique_ptr<Vehicle> v);

    void simulate(double timeStep);
};

#endif