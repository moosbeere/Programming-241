#include "RoadSegment.h"
#include <iostream>

RoadSegment::RoadSegment(double len, double limit)
    : length(len), speedLimit(limit) {
}

double RoadSegment::getLength() const { return length; }
double RoadSegment::getSpeedLimit() const { return speedLimit; }

void RoadSegment::printInfo() const {
    std::cout << "Участок дороги: длина = " << length << " км, "
        << "ограничение скорости = " << speedLimit << " км/ч\n";
}