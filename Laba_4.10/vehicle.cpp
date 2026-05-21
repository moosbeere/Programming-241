#include "vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string n, int speed) : name(n), maxSpeed(speed) {
    cout << "Вызван конструктор Vehicle для: " << name << endl;
}

Vehicle::~Vehicle() {
    // Пустой виртуальный деструктор
}

void Vehicle::printInfo() const {
    cout << "Транспорт: " << name << ", Макс. скорость: " << maxSpeed << " км/ч";
}
