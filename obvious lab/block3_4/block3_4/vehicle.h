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