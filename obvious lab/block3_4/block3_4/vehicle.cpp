#include <iostream>
#include "vehicle.h"
using namespace std;

Vehicle::Vehicle(const string brand, int maxSpeed)
    : brand(brand), maxSpeed(maxSpeed), currentSpeed(0) {
}


void Vehicle::accelerate(int increment) {
    if (currentSpeed + increment > maxSpeed) {
        currentSpeed = maxSpeed;
    }
    else {
        currentSpeed += increment;
    }
}

void Vehicle::brake(int decrement) {
    if (currentSpeed - decrement <= 0) {
        currentSpeed = 0;
    }
    else {
        currentSpeed -= decrement;
    }
}

void Vehicle::getStatus() const {
    cout << "Марка: " << brand << endl;
    cout << "Макс скорость: " << maxSpeed << " км/ч" << endl;
    cout << "Текущая скорость: " << currentSpeed << " км/ч" << endl << endl;

}

string Vehicle::getBrand() const {
    return brand;
}

int Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

int Vehicle::getCurrentSpeed() const {
    return currentSpeed;
}