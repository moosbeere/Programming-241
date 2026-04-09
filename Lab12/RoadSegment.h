#pragma once

class RoadSegment {
private:
    double length;
    double speedLimit;
public:
    RoadSegment(double len, double limit);
    double getLength() const;
    double getSpeedLimit() const;
    void printInfo() const;
};