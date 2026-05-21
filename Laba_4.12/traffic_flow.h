#pragma once
#include <vector>
#include <memory>
#include "vehicle.h"
#include "road_segment.h"

using namespace std; // Добавлено в заголовок

class TrafficFlow {
private:
    vector<unique_ptr<Vehicle>> vehicles;

public:
    void addVehicle(unique_ptr<Vehicle> v);
    void simulate(const RoadSegment& road, double timeStep);
    void printStatus() const;
};
