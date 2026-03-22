#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(std::string str, int mS) {
    brand = str;
    maxSpeed = mS;
    currentSpeed = 0;
}

void Vehicle::accelerate(int num) {
    currentSpeed += num;
    if (currentSpeed > maxSpeed) currentSpeed = maxSpeed;
}

void Vehicle::brake(int num) {
    currentSpeed -= num;
    if (currentSpeed < 1) currentSpeed = 0;
}

void Vehicle::getStatus() {
    cout << "Марка авто: " << brand << endl;
    cout << "Максимальная скорость: " << maxSpeed << endl;
    cout << "Текущая скорость" << currentSpeed << "" << endl;
}

bool Vehicle::operator<(const Vehicle& other) const {
    return this->maxSpeed < other.maxSpeed;
}