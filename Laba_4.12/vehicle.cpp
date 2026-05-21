#include "vehicle.h"

Vehicle::Vehicle(string n, double maxS) : name(n), maxSpeed(maxS), currentSpeed(0), position(0) {}
Vehicle::~Vehicle() {}

void Vehicle::move(double timeStep) {
    position += currentSpeed * timeStep;
}

string Vehicle::getName() const { return name; }
double Vehicle::getPosition() const { return position; }
double Vehicle::getCurrentSpeed() const { return currentSpeed; }

Car::Car(string n, double maxS) : Vehicle(n, maxS) {}

void Car::updateSpeed(double roadLimit) {
    double targetSpeed = min(maxSpeed, roadLimit);
    if (currentSpeed < targetSpeed) {
        currentSpeed += 5.0; // Быстрый разгон
        if (currentSpeed > targetSpeed) currentSpeed = targetSpeed;
    }
    else if (currentSpeed > targetSpeed) {
        currentSpeed -= 7.0; // Быстрое торможение
        if (currentSpeed < targetSpeed) currentSpeed = targetSpeed;
    }
}

Truck::Truck(string n, double maxS) : Vehicle(n, maxS) {}

void Truck::updateSpeed(double roadLimit) {
    double targetSpeed = min(maxSpeed, roadLimit);
    if (currentSpeed < targetSpeed) {
        currentSpeed += 1.5; // Медленный разгон
        if (currentSpeed > targetSpeed) currentSpeed = targetSpeed;
    }
    else if (currentSpeed > targetSpeed) {
        currentSpeed -= 3.0; // Медленное торможение
        if (currentSpeed < targetSpeed) currentSpeed = targetSpeed;
    }
}
