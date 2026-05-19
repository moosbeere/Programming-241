#include "roadsegment.h"

RoadSegment::RoadSegment(double len,
    double limit)
{
    length = len;
    speedLimit = limit;
}

double RoadSegment::getSpeedLimit() const
{
    return speedLimit;
}