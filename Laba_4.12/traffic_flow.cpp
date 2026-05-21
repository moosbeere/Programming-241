#include "traffic_flow.h"
#include <iostream>

void TrafficFlow::addVehicle(unique_ptr<Vehicle> v) {
    vehicles.push_back(move(v)); // Перемещаем unique_ptr
}

void TrafficFlow::simulate(const RoadSegment& road, double timeStep) {
    for (const auto& v : vehicles) {
        v->updateSpeed(road.getSpeedLimit()); // Динамический полиморфизм в действии
        v->move(timeStep);
    }
}

void TrafficFlow::printStatus() const {
    for (const auto& v : vehicles) {
        cout << v->getName() << " -> Позиция: " << (int)v->getPosition()
            << " м, Скорость: " << v->getCurrentSpeed() * 3.6 << " км/ч\n";
    }
}
