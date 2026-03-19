#pragma once
#include <string>
#include <memory>
using namespace std;
class TransportUnit {
protected:
    string licensePlate;

public:
    TransportUnit(string plate = "Unknown");
    virtual double calculateToll(double distance) const = 0;
    virtual std::string getType() const = 0;
    string getLicensePlate() const { return licensePlate; }
    virtual ~TransportUnit() = default;
};

class Car : public TransportUnit {
public:
    Car(string plate = "Unknown");
    double calculateToll(double distance) const override;
    string getType() const override;
};

class Truck : public TransportUnit {
private:
    double capacity;

public:
    Truck(double cap = 10.0, string plate = "Unknown");
    double calculateToll(double distance) const override;
    string getType() const override;
};