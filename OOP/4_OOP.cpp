#include <iostream>
using namespace std;

// Абстрактный базовый класс
class TransportUnit {
public:
    virtual double calculateToll(double distance) const = 0;
};

// Легковушка
class Car : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.1;
    }
};

// Грузовик
class Truck : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.3 + 5.0;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    const double distance = 100.0;

    TransportUnit* vehicles[2];

    vehicles[0] = new Car();
    vehicles[1] = new Truck();

    for (int i = 0; i < 2; i++) {
        cout << "Плата за проезд: "
             << vehicles[i]->calculateToll(distance)
             << " у.е." << endl;
    }
    return 0;
}