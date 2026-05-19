#pragma once
#ifndef TRAM_H
#define TRAM_H

#include "publictransport.h"

class Tram : public PublicTransport
{
private:
    int electricLineVoltage;

public:
    Tram(int route,
        int capacity,
        int voltage);

    void info() const;
};

#endif