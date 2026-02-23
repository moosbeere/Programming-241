#pragma once
using namespace std;

class TransportUnit {
public:
	virtual double calculateToll(double distance) const = 0;
	virtual ~TransportUnit() {}

};

class car :public TransportUnit {
public:
	car();
	
	double calculateToll(double distance) const override;
};

class Truck :public TransportUnit {
public:
	Truck();
	double calculateToll(double distance)const override;
};