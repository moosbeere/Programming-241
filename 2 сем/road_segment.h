#pragma once

// Участок дороги: длина и ограничение скорости.
class RoadSegment
{
private:
    double length;      // длина, м
    double speedLimit;  // ограничение скорости, км/ч

public:
    RoadSegment(double length, double speedLimit)
        : length(length < 0 ? 0.0 : length),
          speedLimit(speedLimit < 0 ? 0.0 : speedLimit)
    {
    }

    double getLength() const { return length; }
    double getSpeedLimit() const { return speedLimit; }
};

