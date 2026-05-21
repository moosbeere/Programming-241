#include "road_segment.h"

RoadSegment::RoadSegment(double len, double limit) : length(len), speedLimit(limit) {}
double RoadSegment::getSpeedLimit() const { return speedLimit; }
double RoadSegment::getLength() const { return length; }
