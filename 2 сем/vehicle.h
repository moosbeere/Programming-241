#pragma once

#include <string>

// Класс "Транспортное средство"
class Vehicle
{
private:
    std::string brand;   // марка транспортного средства
    int maxSpeed;        // максимальная возможная скорость
    int currentSpeed;    // текущая скорость

public:
    Vehicle(const std::string& brand, int maxSpeed);

    void accelerate(int increment);
    void brake(int decrement);

    // Виртуальный метод, чтобы его можно было расширять в наследниках (напр. FreightVehicle)
    virtual void getStatus() const;

    int getMaxSpeed() const;
    const std::string& getBrand() const;

    // Сравнение транспортных средств по максимальной скорости
    bool operator<(const Vehicle& other) const;

    virtual ~Vehicle() = default;
};

