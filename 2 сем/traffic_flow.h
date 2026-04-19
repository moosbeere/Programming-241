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

    // Храним транспорт как набор объектов разных типов.
    // unique_ptr означает:
    // - единоличное владение объектом
    // - автоматическое освобождение памяти без ручного delete
    // Здесь хранится базовый тип Vehicle, потому что TrafficFlow
    // "не обязан" знать конкретный класс (FlowCar/FlowTruck).
    std::vector<std::unique_ptr<Vehicle>> vehicles;

public:
    // explicit запрещает неявные преобразования RoadSegment -> TrafficFlow.
    explicit TrafficFlow(const RoadSegment& seg)
        : segment(seg)
    {
    }

    // Шаблон добавления конкретного типа транспорта.
    // Например: addVehicle<FlowCar>(...) создаст FlowCar и положит его в vehicles как Vehicle.
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
            // Не все Vehicle обязаны уметь симулировать движение.
            // dynamic_cast проверяет, наследуется ли конкретный объект от Movable.
            auto* mv = dynamic_cast<Movable*>(v.get());
            if (!mv)
                continue;

            // Если объект умеет двигаться — делаем шаг симуляции.
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
            // Аналогично simulate(): печатаем позицию/скорость только для тех,
            // кто поддерживает интерфейс Movable.
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

