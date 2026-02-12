#include "Vehicle.h"
#include <iostream>

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
    std::cout << "Марка машины: " << brand << std::endl;
    std::cout << "Максимальная скорость: " << maxSpeed << std::endl;
    std::cout << "Текущая скорость: " << currentSpeed << "\n" << std::endl;
}