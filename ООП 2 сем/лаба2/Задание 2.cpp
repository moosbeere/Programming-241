#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string& brand, int maxSpeed)
    : brand(brand), maxSpeed(maxSpeed), currentSpeed(0) {}

void Vehicle::accelerate(int increment) {
    if (increment > 0) {               // защита от отрицательного ускорения
        currentSpeed += increment;
        if (currentSpeed > maxSpeed) {
            currentSpeed = maxSpeed;    // ограничиваем максимальной скоростью
        }
    }
}

void Vehicle::brake(int decrement) {
    if (decrement > 0) {              
        currentSpeed -= decrement;
        if (currentSpeed < 0) {
            currentSpeed = 0;          
        }
    }
}

void Vehicle::getStatus() const {
    std::cout << "Марка: " << brand << "\n"
              << "Максимальная скорость: " << maxSpeed << " км/ч\n"
              << "Текущая скорость: " << currentSpeed << " км/ч\n"
              << "------------------------------\n";

}
