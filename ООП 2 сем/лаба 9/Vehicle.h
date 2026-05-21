#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
private:
    int maxSpeed;

public:
    Vehicle(int speed);
    bool operator<(const Vehicle& other) const;
};

#endif
