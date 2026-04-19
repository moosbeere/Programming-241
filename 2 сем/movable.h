#pragma once

class RoadSegment;

// Интерфейс (абстрактный класс) для объектов, которые "умеют" симулировать движение.
// TrafficFlow хранит только Vehicle, но при этом некоторые машины дополнительно
// наследуются от Movable, чтобы их можно было двигать в симуляции.
class Movable
{
public:
    // Один шаг симуляции для объекта на участке дороги.
    virtual void simulateStep(const RoadSegment& segment, double timeStep) = 0;

    // Текущая позиция объекта на участке (в метрах).
    virtual double getPosition() const = 0;

    // Текущая скорость объекта (в км/ч).
    virtual double getCurrentSpeed() const = 0;

    // Виртуальный деструктор обязателен для полиморфных классов
    // (на случай удаления через указатель/ссылку на базовый тип).
    virtual ~Movable() = default;
};

