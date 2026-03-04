#pragma once
using namespace std;
#include <string>

class TransportUnit {
protected:
    string licensePlate;

public:
    TransportUnit(string plate = "Unknown") : licensePlate(plate) {}
    virtual double calculateToll(double distance) const = 0;
    virtual ~TransportUnit() {}
    string getLicensePlate() const { return licensePlate; }
};

class Car : public TransportUnit {
public:
    Car(string plate = "Unknown") : TransportUnit(plate) {}
    double calculateToll(double distance) const override {
        return distance * 0.1;
    }
};

class Truck : public TransportUnit {
public:
    Truck(string plate = "Unknown") : TransportUnit(plate) {}
    double calculateToll(double distance) const override {
        return distance * 0.3 + 5.0;
    }
};