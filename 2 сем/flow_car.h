#pragma once

#include <string>

#include "vehicle.h"
#include "movable.h"
#include "road_segment.h"

// Легковой автомобиль в модели транспортного потока.
class FlowCar : public Vehicle, public Movable
{
private:
    double position;   // м от начала участка
    double speed;      // км/ч
    double accelRate;  // км/ч за секунду при разгоне
    double brakeRate;  // км/ч за секунду при торможении

public:
    FlowCar(const std::string& brand,
            int maxSpeed,
            double accelRate,
            double brakeRate)
        : Vehicle(brand, maxSpeed),
          position(0.0),
          speed(0.0),
          accelRate(accelRate),
          brakeRate(brakeRate)
    {
    }

    void simulateStep(const RoadSegment& segment, double timeStep) override
    {
        const double target =
            std::min<double>(getMaxSpeed(), segment.getSpeedLimit());

        if (speed < target)
        {
            speed += accelRate * timeStep;
            if (speed > target)
                speed = target;
        }
        else if (speed > target)
        {
            speed -= brakeRate * timeStep;
            if (speed < target)
                speed = target;
        }

        // Переводим км/ч в м/с: v(km/h) * 1000 / 3600
        const double speedMS = speed * 1000.0 / 3600.0;
        position += speedMS * timeStep;

        if (position > segment.getLength())
            position = segment.getLength();
    }

    double getPosition() const override { return position; }
    double getCurrentSpeed() const override { return speed; }
};

