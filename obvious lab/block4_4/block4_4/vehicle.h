#pragma once
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    int maxSpeed;
    int currentSpeed;

public:
    Vehicle(const string brand, int maxSpeed);

    virtual ~Vehicle() {}

    virtual void displayInfo() const = 0;
    virtual string getType()const = 0;

    void accelerate(int increment);
    void brake(int decrement);
    void getStatus() const;

    string getBrand() const;
    int getMaxSpeed() const;
    int getCurrentSpeed() const;

  
    bool operator<(const Vehicle& other) const {
        return this->maxSpeed < other.maxSpeed;
    }
};