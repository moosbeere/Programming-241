#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string name;
    int maxSpeed;

public:
    Vehicle(string n = "Unknown", int s = 0) {
        name = n;
        maxSpeed = s;
    }

    void printVehicle() const {
        cout << "Название: " << name << ", Макс скорость: " << maxSpeed << endl;
    }
};

class PublicTransport {
protected:
    int routeNumber;
    int passengerCapacity;

public:
    PublicTransport(int route, int capacity) {
        routeNumber = route;
        passengerCapacity = capacity;
    }

    void printPublicTransport() const {
        cout << "Маршрут: " << routeNumber << ", Вместимость: " << passengerCapacity << endl;
    }
};

class Bus : public PublicTransport, public Vehicle {
private:
    string fuelType;

public:
    Bus(string n, int s, int route, int capacity, string fuel): Vehicle(n, s), PublicTransport(route, capacity) {
        fuelType = fuel;
    }

    void print() const {
        cout << "____Автобус____" << endl;
        printVehicle();
        printPublicTransport();
        cout << "Тип топлива: " << fuelType << endl;
    }
};

class Tram : public PublicTransport {
private:
    int electricLineVoltage;

public:
    Tram(int route, int capacity, int voltage): PublicTransport(route, capacity) {
        electricLineVoltage = voltage;
    }

    void print() const {
        cout << "____Трамвай____" << endl;
        printPublicTransport();
        cout << "Напряжение линии: " << electricLineVoltage << " В" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Bus bus("Автобус", 80, 24, 50, "Дизель");
    Tram tram(5, 120, 600);

    bus.print();
    tram.print();

    return 0;
}