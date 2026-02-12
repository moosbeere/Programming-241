#pragma once
#include "TransportUnit.h"

class Car : public TransportUnit {
public:
	double calculateToll(double distance) const override;
};
