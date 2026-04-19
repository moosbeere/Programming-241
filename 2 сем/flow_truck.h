#pragma once

#include <string>

#include "vehicle.h"
#include "movable.h"
#include "road_segment.h"

// Грузовой автомобиль в модели транспортного потока.
// Отличается параметрами разгона/торможения, но использует те же идеи симуляции.
class FlowTruck : public Vehicle, public Movable
{
private:
    double position;   // м от начала участка
    double speed;      // км/ч
    double accelRate;  // км/ч за секунду при разгоне (медленнее легкового)
    double brakeRate;  // км/ч за секунду при торможении (плавнее)

public:
    FlowTruck(const std::string& brand,
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

    // Один шаг симуляции (см. комментарии в FlowCar):
    // целевая скорость ограничена min(getMaxSpeed авто, speedLimit дороги),
    // затем обновляются speed и position.
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

        const double speedMS = speed * 1000.0 / 3600.0;
        position += speedMS * timeStep;

        // Ограничиваем position концом участка.
        if (position > segment.getLength())
            position = segment.getLength();
    }

    // Геттеры, нужные интерфейсу Movable
    double getPosition() const override { return position; }
    double getCurrentSpeed() const override { return speed; }
};

