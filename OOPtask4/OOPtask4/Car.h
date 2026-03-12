#ifndef CAR_H
#define CAR_H

#include "TransportUnit.h"

class Car : public TransportUnit {
public:
    double calculateToll(double distance) const;
};

#endif
