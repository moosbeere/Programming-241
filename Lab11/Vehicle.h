#pragma once
#include <string>

using namespace std;

class Vehicle {
private:
    string brand;
    int maxSpeed;
    int currentSpeed;
public:
    Vehicle(std::string str, int mS);
    void accelerate(int num);
    void brake(int num);
    void getStatus();
    bool operator<(const Vehicle& other) const;
    virtual double getCargoCapacity() const { return 10e9; };
};