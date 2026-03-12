#pragma once
#ifndef BASE_H
#define BASE_H

class Base {
public:
    virtual double calculateToll(double distance) const = 0;
    virtual ~Base() {}
};

#endif