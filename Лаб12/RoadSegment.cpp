#include "RoadSegment.h"

RoadSegment::RoadSegment(double len, double limit): length(len), speedLimit(limit) {
}

double RoadSegment::getLength() const {
    return length;
}

double RoadSegment::getSpeedLimit() const {
    return speedLimit;
}