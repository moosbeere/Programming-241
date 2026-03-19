#pragma once

#include "PublicTransport.h"

class Tram : public PublicTransport {
private:
    int electricLineVoltage;

public:
    Tram(int route, int capacity, int voltage);
    void print() const;
};