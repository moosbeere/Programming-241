#pragma once

class TransportUnit {
public:
	virtual double calculateToll(double distance) const = 0;
};