#pragma once

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "movable.h"
#include "road_segment.h"
#include "vehicle.h"

// Поток транспортных средств на участке дороги.
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
        vehicles.push_back(
            std::make_unique<T>(std::forward<Args>(args)...));
    }

    // Один шаг моделирования для всех транспортных средств.
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

    // Вывод текущего состояния потока.
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
                      << " | pos = " << std::setprecision(1)
                      << mv->getPosition() << " m"
                      << ", speed = " << std::setprecision(1)
                      << mv->getCurrentSpeed() << " km/h\n";
        }
        std::cout << "\n";
    }
};

