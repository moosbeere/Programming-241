#pragma once
#ifndef PUBLICTRANSPORT_H
#define PUBLICTRANSPORT_H

class PublicTransport
{
protected:
    int routeNumber;
    int passengerCapacity;

public:
    PublicTransport(int route, int capacity);

    void showRoute() const;
};

#endif