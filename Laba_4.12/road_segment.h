#pragma once

using namespace std;

class RoadSegment {
private:
    double length;
    double speedLimit;

public:
    RoadSegment(double len, double limit);
    double getSpeedLimit() const;
    double getLength() const;
};
