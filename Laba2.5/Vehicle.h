#pragma once

#include <iostream>

class TransportUnit 
{
public:
    virtual ~TransportUnit() {}
    virtual double calculateToll(double distance) const = 0;
    virtual void printInfo() const = 0;
};

class Car : public TransportUnit 
{
public:
    double calculateToll(double distance) const override;
    void printInfo() const override;
};

class Truck : public TransportUnit 
{
public:
    double calculateToll(double distance) const override;
    void printInfo() const override;
};