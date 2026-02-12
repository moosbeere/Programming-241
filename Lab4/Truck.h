#include "TransportUnit.h"

class Truck : public TransportUnit {
public:
    double calculateToll(double distance) const override;
};