#include "Vehicle.h"
#include <iostream>
#include <algorithm>

Vehicle::Vehicle(std::string b, int mS, double accel, double decel)
    : brand(b), maxSpeed(mS), currentSpeed(0.0), position(0.0),
    accelRate(accel), decelRate(decel) {
}

void Vehicle::accelerate(double delta) {
    currentSpeed += delta;
    if (currentSpeed > maxSpeed) currentSpeed = maxSpeed;
    if (currentSpeed < 0) currentSpeed = 0;
}

void Vehicle::brake(double delta) {
    currentSpeed -= delta;
    if (currentSpeed < 0) currentSpeed = 0;
}

void Vehicle::update(double roadSpeedLimit, double timeStepHours) {
    double target = std::min((double)maxSpeed, roadSpeedLimit);
    if (currentSpeed < target) {
        currentSpeed += accelRate * timeStepHours;
        if (currentSpeed > target) currentSpeed = target;
    }
    else if (currentSpeed > target) {
        currentSpeed -= decelRate * timeStepHours;
        if (currentSpeed < target) currentSpeed = target;
    }
    position += currentSpeed * timeStepHours;
}

void Vehicle::getStatus() const {
    std::cout << "Марка: " << brand << "\n"
        << "Макс. скорость: " << maxSpeed << " км/ч\n"
        << "Текущая скорость: " << currentSpeed << " км/ч\n"
        << "Позиция: " << position << " км\n";
}