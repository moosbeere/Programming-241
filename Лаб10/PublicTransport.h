#pragma once

class PublicTransport {
protected:
    int routeNumber;
    int passengerCapacity;

public:
    PublicTransport(int route, int capacity);
    void printPublicTransport() const;
};
