#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string str, int mS) {
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
    cout << "Марка машины: " << brand << endl;
    cout << "Максимальная скорость: " << maxSpeed << endl;
    cout << "Текущая скорость: " << currentSpeed << endl;
}