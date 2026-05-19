#include "trafficflow.h"
#include <iostream>

TrafficFlow::TrafficFlow(RoadSegment r)
    : road(r)
{
}

void TrafficFlow::addVehicle(
    std::unique_ptr<Vehicle> v)
{
    vehicles.push_back(std::move(v));
}

void TrafficFlow::simulate(double timeStep)
{
    for (auto& v : vehicles)
    {
        if (v->getCurrentSpeed()
            < road.getSpeedLimit())
        {
            v->accelerate(5);
        }

        v->move(timeStep);

        v->info();
    }
}