#pragma once
#include "vehicle.h"
#include <string>
using namespace std;
// Базовый класс
class PublicTransport :  virtual public Vehicle {
protected:
    string routeNumber;
    int passengerCapacity;

public:
    PublicTransport(string n, int speed, string route, int capacity);
    void printInfo() const override;
};

class Tram : public PublicTransport {
private:
    int electricLineVoltage;

public:
    Tram(string n, int speed, string route, int capacity, int voltage);
    void printInfo() const override;
};

class Bus : public PublicTransport {
private:
    string fuelType;

public:
    Bus(string n, int speed, string route, int capacity, string fuel);
    void printInfo() const override;
};
