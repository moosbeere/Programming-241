#include <iostream>

using namespace std;

class TransportUnit {
public:

    virtual double calculateToll(double distance) const = 0;
};


class Car : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.1;
    }
};


class Truck : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.3 + 5.0;
    }
};


int main() {
    setlocale(LC_ALL, "RU");

    Car car;
    Truck truck;

    TransportUnit* units[2];

    units[0] = &car;
    units[1] = &truck;

    double distance = 100;

    cout << "Расчет платы за " << distance << " км:\n";

    for (int i = 0; i < 2; i++) {
        cout << "Плата: " << units[i]->calculateToll(distance) << endl;
    }

    return 0;
}