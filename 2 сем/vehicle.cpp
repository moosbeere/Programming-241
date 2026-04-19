#include "vehicle.h"

#include <iostream>

// Реализация конструктора: задаём марку и максимальную скорость,
// а стартовую текущую скорость делаем равной 0.
Vehicle::Vehicle(const std::string& brand, int maxSpeed)
    : brand(brand),
      maxSpeed(maxSpeed < 0 ? 0 : maxSpeed),
      currentSpeed(0)
{
}

// Ускоряем: увеличиваем currentSpeed, но не превышаем maxSpeed.
void Vehicle::accelerate(int increment)
{
    if (increment <= 0)
        return;

    currentSpeed += increment;
    if (currentSpeed > maxSpeed)
        currentSpeed = maxSpeed;
}

// Тормозим: уменьшаем currentSpeed, но не уходим ниже 0.
void Vehicle::brake(int decrement)
{
    if (decrement <= 0)
        return;

    currentSpeed -= decrement;
    if (currentSpeed < 0)
        currentSpeed = 0;
}

// Печать состояния: выводим все основные поля транспортного средства.
void Vehicle::getStatus() const
{
    std::cout << "Vehicle status:\n";
    std::cout << "  brand: " << brand << "\n";
    std::cout << "  maxSpeed: " << maxSpeed << "\n";
    std::cout << "  currentSpeed: " << currentSpeed << "\n";
}

// Возвращаем максимальную скорость.
int Vehicle::getMaxSpeed() const
{
    return maxSpeed;
}

// Возвращаем марку (по ссылке, чтобы не копировать строку).
const std::string& Vehicle::getBrand() const
{
    return brand;
}

// Сравнение позволяет использовать Vehicle в сортировках/структурах,
// например сравнивать по maxSpeed.
bool Vehicle::operator<(const Vehicle& other) const
{
    return maxSpeed < other.maxSpeed;
}