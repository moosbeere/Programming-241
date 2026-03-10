#pragma once

// Базовый абстрактный класс "Транспортная единица"
class TransportUnit
{
public:
    // Расчёт платы за проезд по расстоянию (в км)
    virtual double calculateToll(double distance) const = 0;

    // Виртуальный деструктор нужен для корректного удаления через указатель базового класса
    virtual ~TransportUnit() = default;
};

// Легковой автомобиль: плата = distance * 0.1
class Car : public TransportUnit
{
public:
    double calculateToll(double distance) const override
    {
        if (distance < 0)
            distance = 0;
        return distance * 0.1;
    }
};

// Грузовик: плата = distance * 0.3 + 5.0
class Truck : public TransportUnit
{
public:
    double calculateToll(double distance) const override
    {
        if (distance < 0)
            distance = 0;
        return distance * 0.3 + 5.0;
    }
};

