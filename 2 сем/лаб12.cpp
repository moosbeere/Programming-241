#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>

#include "vehicle.h"

class RoadSegment
{
private:
    double length;      // м
    double speedLimit;  // км/ч

public:
    RoadSegment(double length, double speedLimit)
        : length(length < 0 ? 0.0 : length),
          speedLimit(speedLimit < 0 ? 0.0 : speedLimit)
    {
    }

    double getLength() const { return length; }
    double getSpeedLimit() const { return speedLimit; }
};

// Интерфейс для движущихся по дороге объектов
class Movable
{
public:
    virtual void simulateStep(const RoadSegment& segment, double timeStep) = 0;
    virtual double getPosition() const = 0;
    virtual double getCurrentSpeed() const = 0;
    virtual ~Movable() = default;
};

// Легковой автомобиль в модели потока
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
        const double target = std::min<double>(getMaxSpeed(), segment.getSpeedLimit());

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

// Грузовой автомобиль в модели потока
class FlowTruck : public Vehicle, public Movable
{
private:
    double position;   // м
    double speed;      // км/ч
    double accelRate;  // медленнее разгон
    double brakeRate;  // более плавное торможение

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

    void simulateStep(const RoadSegment& segment, double timeStep) override
    {
        const double target = std::min<double>(getMaxSpeed(), segment.getSpeedLimit());

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

        if (position > segment.getLength())
            position = segment.getLength();
    }

    double getPosition() const override { return position; }
    double getCurrentSpeed() const override { return speed; }
};

class TrafficFlow
{
private:
    RoadSegment segment;
    std::vector<std::unique_ptr<Vehicle>> vehicles;

public:
    explicit TrafficFlow(const RoadSegment& seg)
        : segment(seg)
    {
    }

    template <typename T, typename... Args>
    void addVehicle(Args&&... args)
    {
        vehicles.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    void simulate(double timeStep)
    {
        for (auto& v : vehicles)
        {
            auto* mv = dynamic_cast<Movable*>(v.get());
            if (!mv)
                continue;

            mv->simulateStep(segment, timeStep);
        }
    }

    void printState(double currentTime) const
    {
        std::cout << "Time: " << std::fixed << std::setprecision(1)
                  << currentTime << " s\n";

        for (const auto& v : vehicles)
        {
            auto* mv = dynamic_cast<const Movable*>(v.get());
            if (!mv)
                continue;

            std::cout << "  " << v->getBrand()
                      << " | pos = " << std::setprecision(1) << mv->getPosition() << " m"
                      << ", speed = " << std::setprecision(1) << mv->getCurrentSpeed() << " km/h\n";
        }
        std::cout << "\n";
    }
};

int main()
{
    RoadSegment segment(1000.0, 60.0); // 1 км, ограничение 60 км/ч
    TrafficFlow flow(segment);

    // Легковые: быстрее разгоняются и тормозят
    flow.addVehicle<FlowCar>("Toyota", 180, 8.0, 10.0);
    flow.addVehicle<FlowCar>("BMW", 220, 10.0, 12.0);

    // Грузовые: медленнее разгон, мягкое торможение
    flow.addVehicle<FlowTruck>("Volvo Truck", 110, 4.0, 6.0);

    const double timeStep = 1.0; // секунды
    const int steps = 20;

    double currentTime = 0.0;
    for (int i = 0; i < steps; ++i)
    {
        flow.simulate(timeStep);
        currentTime += timeStep;
        flow.printState(currentTime);
    }

    return 0;
}
