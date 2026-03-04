#pragma once
#include <string>
using namespace std;

class TransportUnit {
private:
    string licensePlate;

public:
    static int totalVehiclesDispatched;

    TransportUnit(string plate);
    virtual double calculateToll(double distance) const = 0;
    virtual string getType() const = 0;
    string getLicensePlate() const { return licensePlate; }
    static void report();
    virtual ~TransportUnit();
};

class Car : public TransportUnit {
public:
    Car(string plate);
    double calculateToll(double distance) const override;
    string getType() const override;
};

class Truck : public TransportUnit {
private:
    double capacity;

public:
    Truck(double cap, string plate);
    double calculateToll(double distance) const override;
    string getType() const override;
};