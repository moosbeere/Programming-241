#pragma once
#include <string>

using namespace std;

class Vehicle {
private:
    string brand;
    int maxSpeed;
    int currentSpeed;
public:
    Vehicle(string str, int mS);
    void accelerate(int num);
    void brake(int num);
    void getStatus();
    bool operator<(const Vehicle& other) const;
    int getCurrentSpeed() const;
    int getMaxSpeed() const;
    string getBrand() const;
};