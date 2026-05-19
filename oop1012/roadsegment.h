#pragma once
#ifndef ROADSEGMENT_H
#define ROADSEGMENT_H

class RoadSegment
{
private:
    double length;
    double speedLimit;

public:
    RoadSegment(double len, double limit);

    double getSpeedLimit() const;
};

#endif