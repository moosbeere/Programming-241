#pragma once

class RoadSegment {
    double length;
    double speedLimit;

public:
    RoadSegment(double len, double limit);

    double getLength() const;
    double getSpeedLimit() const;
};