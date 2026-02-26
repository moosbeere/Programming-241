#pragma once
#include "PublicTransport.h"

class Tram : public PublicTransport {
public:
    int electricLineVoltage;

    Tram(const string& brand, int maxSpeed,
        const string& route, int capacity, int voltage);
    void info();
};