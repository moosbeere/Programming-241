#include "Vehicle.h"
#include <cmath>

Vehicle::Vehicle(double maxSp, double brake): speed(maxSp), maxSpeed(maxSp), brakeStep(brake) {
}

double Vehicle::getPosition() const {
    return position;
}

void Vehicle::simulate(double dt, double speedLimit) {
    if (speed <= speedLimit) {
        position += speed * dt;
    }
    else {
        double differance = speed - speedLimit;
        int n = ceil(differance / 2.0);
        double a = -brakeStep * n;
        position += speed * dt + 0.5 * a * dt * dt;
        speed += a * dt;

        if (speed < speedLimit) speed = speedLimit;
    }
}