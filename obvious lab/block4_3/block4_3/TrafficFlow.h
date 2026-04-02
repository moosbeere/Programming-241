#pragma once
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "RoadSegment.h"
using namespace std;

class TrafficFlow {
private:
    vector<unique_ptr<Vehicle>> vehicles;

public:
    void addVehicle(unique_ptr<Vehicle> vehicle);
    void simulate(double timeStep, const RoadSegment& road);
    void printStatus() const;
    int getVehicleCount() const;
};

