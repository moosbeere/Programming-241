#pragma once

class RoadSegment;

// Интерфейс для объектов, которые могут двигаться по дороге.
class Movable
{
public:
    virtual void simulateStep(const RoadSegment& segment, double timeStep) = 0;
    virtual double getPosition() const = 0;
    virtual double getCurrentSpeed() const = 0;
    virtual ~Movable() = default;
};

