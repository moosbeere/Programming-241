#include "TransportUnit.h"
#include <iostream>
using namespace std;

int TransportUnit::totalVehiclesDispatched = 0;

TransportUnit::TransportUnit(string plate) : licensePlate(plate) {
    totalVehiclesDispatched++;
    cout << "Транспорт создан. Номер: " << licensePlate
        << "  Всего: " << totalVehiclesDispatched << endl;
}

TransportUnit::~TransportUnit() {
    totalVehiclesDispatched--;
    cout << "Транспорт удален. Номер: " << licensePlate
        << " |Осталось: " << totalVehiclesDispatched << endl;
}

void TransportUnit::report() {
    cout << "ОТЧЕТ ДИСПЕТЧЕРА" << endl;
    cout << "Всего обслужено транспортных средств: "
        << totalVehiclesDispatched << endl;
}

Car::Car(string plate) : TransportUnit(plate) {}

double Car::calculateToll(double distance) const {
    return distance * 0.1;
}

string Car::getType() const {
    return "Легковой автомобиль " + getLicensePlate();
}

Truck::Truck(double cap, string plate)
    : TransportUnit(plate), capacity(cap) {
}

double Truck::calculateToll(double distance) const {
    double extraFee = (capacity > 15) ? 10.0 : 0.0;
    return distance * 0.3 + 5.0 + extraFee;
}

string Truck::getType() const {
    return "Грузовик " + getLicensePlate() +
        " (грузоподъемность: " + to_string(capacity) + "т)";
}