#pragma once
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    int maxSpeed;         
    double currentSpeed;   
    double position;       
    double accelRate;      
    double decelRate;

public:
    Vehicle(string brand, int maxSpeed, double accel, double decel);
    virtual ~Vehicle() = default;

    void accelerate(double delta);
    void brake(double delta);
    virtual void update(double roadSpeedLimit, double timeStepHours);
    virtual void getStatus() const;

    double getPosition() const { return position; }
    void setPosition(double pos) { position = pos; }

    virtual double getCargoCapacity() const { return 1e9; }
};