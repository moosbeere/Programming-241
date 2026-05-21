#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;

// Участок дороги
class RoadSegment {
private:
    double length;
    double speedLimit;

public:
    RoadSegment(double len, double limit) : length(len), speedLimit(limit) {}

    double getLength() const {
        return length;
    }

    double getSpeedLimit() const {
        return speedLimit;
    }
};

// Базовый класс транспорта
class Vehicle {
protected:
    string name;
    double currentSpeed;
    double maxSpeed;
    double position;

public:
    Vehicle(string n, double current, double max) : name(n), currentSpeed(current), maxSpeed(max), position(0) {}

    virtual void update(double timeStep, double roadSpeedLimit) = 0;

    void move(double timeStep) {
        position += currentSpeed * timeStep;
    }

    void printInfo() const {
        cout << name
             << ", Скорость: "
             << currentSpeed
             << " км/ч"
             << ", Позиция: "
             << position
             << " км"
             << endl;
    }
};

// Легковой автомобиль
class Car : public Vehicle {
public:
    Car(string n, double current, double max) : Vehicle(n, current, max) {}

    void update(double timeStep, double roadSpeedLimit) override {

        // Быстро ускорение
        currentSpeed += 15 * timeStep;

        // Ограничение скорости
        currentSpeed = min(currentSpeed, min(maxSpeed, roadSpeedLimit));

        move(timeStep);
    }
};

// Грузовик
class Truck : public Vehicle {
public:
    Truck(string n, double current, double max) : Vehicle(n, current, max) {}

    void update(double timeStep, double roadSpeedLimit) override {

        // Медленное ускорение
        currentSpeed += 5 * timeStep;

        // Ограничение скорости
        currentSpeed = min(currentSpeed,
                           min(maxSpeed, roadSpeedLimit));

        move(timeStep);
    }
};

// Поток транспорта
class TrafficFlow {
private:
    RoadSegment road;

    vector<unique_ptr<Vehicle>> vehicles;

public:
    TrafficFlow(const RoadSegment& r) : road(r) {}

    void addVehicle(unique_ptr<Vehicle> v) {
        vehicles.push_back(move(v));
    }

    void simulate(double timeStep) {
        cout << "=== Симуляция ===" << endl;

        for (auto& vehicle : vehicles) {
            vehicle->update(timeStep, road.getSpeedLimit());

            vehicle->printInfo();
        }

        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    RoadSegment road(10, 90);

    TrafficFlow flow(road);

    flow.addVehicle(make_unique<Car>("Toyota", 40, 180));

    flow.addVehicle(make_unique<Truck>("Volvo Truck", 30, 110));


    for (int i = 0; i < 5; i++) {
        flow.simulate(1.0);
    }

    return 0;
}