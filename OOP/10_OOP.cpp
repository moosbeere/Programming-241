#include <iostream>
#include <string>

using namespace std;

// Базовый класс транспорта
class Vehicle {
protected:
    string model;
    int maxSpeed;

public:
    Vehicle(string m, int speed) : model(m), maxSpeed(speed) {}

    void printVehicleInfo() const {
        cout << "Модель: " << model << endl;
        cout << "Максимальная скорость: " << maxSpeed << " км/ч" << endl;
    }
};

// Общественный транспорт
class PublicTransport {
protected:
    string routeNumber;
    int passengerCapacity;

public:
    PublicTransport(string route, int capacity) : routeNumber(route), passengerCapacity(capacity) {}

    void printPublicTransportInfo() const {
        cout << "Маршрут: " << routeNumber << endl;
        cout << "Вместимость: " << passengerCapacity << " пассажиров" << endl;
    }
};

// Автобус
class Bus : public PublicTransport, public Vehicle {
private:
    string fuelType;

public:
    Bus(string route, int capacity, string model, int speed, string fuel) : PublicTransport(route, capacity), Vehicle(model, speed), fuelType(fuel) {}

    void printInfo() const {
        cout << "=== Автобус ===" << endl;

        printVehicleInfo();
        printPublicTransportInfo();

        cout << "Тип топлива: " << fuelType << endl;
    }
};

// Трамвай
class Tram : public PublicTransport {
private:
    int electricLineVoltage;

public:
    Tram(string route, int capacity, int voltage) : PublicTransport(route, capacity), electricLineVoltage(voltage) {}

    void printInfo() const {
        cout << "=== Трамвай ===" << endl;

        printPublicTransportInfo();

        cout << "Напряжение линии: " << electricLineVoltage << " Вольт" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Bus bus("Мск - спб", 50, "А-435843", 90, "Дизель");

    Tram tram("Садовое кольцо", 120, 600);

    bus.printInfo();

    cout << endl;

    tram.printInfo();

    return 0;
}