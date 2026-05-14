#ifndef TRANSPORTUNIT_H
#define TRANSPORTUNIT_H

#include <string>

class TransportUnit {
protected:
    std::string name;
    int maxSpeed;

public:
    TransportUnit(std::string name, int maxSpeed);
    virtual ~TransportUnit();

    virtual double calculateToll(double distance) const = 0;
    virtual void info() const;

    bool operator<(const TransportUnit& other) const;
};

#endif#pragma once
