#pragma once
#include <iostream>
#include <string>
#include "PublicTransport.h"
using namespace std;

class Tram : public PublicTransport {
private:
    int electricLineVoltage;

public:
    Tram(const string& brand, int maxSpeed, const string& route, int capacity, int voltage);

    int getVoltage() const;

 
    void displayInfo() const override;
    string getType() const override;
};

