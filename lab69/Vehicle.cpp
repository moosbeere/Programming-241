#include "Vehicle.h"

// ======================================================
// Конструктор
// ======================================================

Vehicle::Vehicle(string n, int speed) {

    name = n;
    maxSpeed = speed;

    // Увеличиваем счетчик
    DispatchCenter::totalVehiclesDispatched++;
}

// ======================================================
// Вывод информации
// ======================================================

void Vehicle::printInfo() const {

    cout << name
        << " | Скорость: "
        << maxSpeed
        << " км/ч"
        << endl;
}

// ======================================================
// Перегрузка оператора <
// ======================================================

bool Vehicle::operator<(const Vehicle& other) const {

    return maxSpeed < other.maxSpeed;
}