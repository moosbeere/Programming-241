#include "vehicle.h"

#include <iostream>

Vehicle::Vehicle(const std::string& brand, int maxSpeed)
    : brand(brand),
      maxSpeed(maxSpeed < 0 ? 0 : maxSpeed),
      currentSpeed(0)
{
}

void Vehicle::accelerate(int increment)
{
    if (increment <= 0)
        return;

    currentSpeed += increment;
    if (currentSpeed > maxSpeed)
        currentSpeed = maxSpeed;
}

void Vehicle::brake(int decrement)
{
    if (decrement <= 0)
        return;

    currentSpeed -= decrement;
    if (currentSpeed < 0)
        currentSpeed = 0;
}

void Vehicle::getStatus() const
{
    std::cout << "Vehicle status:\n";
    std::cout << "  brand: " << brand << "\n";
    std::cout << "  maxSpeed: " << maxSpeed << "\n";
    std::cout << "  currentSpeed: " << currentSpeed << "\n";
}

int Vehicle::getMaxSpeed() const
{
    return maxSpeed;
}

const std::string& Vehicle::getBrand() const
{
    return brand;
}

bool Vehicle::operator<(const Vehicle& other) const
{
    return maxSpeed < other.maxSpeed;
}

