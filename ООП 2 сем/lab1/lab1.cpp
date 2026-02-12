#include "Vehicle.h"
#include <iostream>
using namespace std;

// Конструктор
Vehicle::Vehicle(string b, int ms) {
    brand = b;
    maxSpeed = ms;
    currentSpeed = 0;
}

// Увеличение скорости
void Vehicle::accelerate(int increment) {
    currentSpeed = currentSpeed + increment;
    if (currentSpeed > maxSpeed) {
        currentSpeed = maxSpeed;
    }
}

// Уменьшение скорости
void Vehicle::brake(int decrement) {
    currentSpeed = currentSpeed - decrement;
    if (currentSpeed < 0) {
        currentSpeed = 0;
    }
}

// Вывод статуса
void Vehicle::getStatus() {
    cout << "Марка: " << brand 
         << ", Макс. скорость: " << maxSpeed 
         << ", Текущая скорость: " << currentSpeed 
         << endl;
}
