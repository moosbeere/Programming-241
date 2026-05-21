#pragma once

class TransportUnit
{
public:
    virtual double calculateToll(double distance) const = 0;
};

class Car : public TransportUnit
{
public:
    double calculateToll(double distance) const override;
};

class Truck : public TransportUnit
{
public:
    double calculateToll(double distance) const override;
};
