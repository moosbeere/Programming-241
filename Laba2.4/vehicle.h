#pragma once
#include <iostream>
using namespace std;
class TransportUnit
{
public:
	virtual double calculateToll(double distance) const = 0;
	virtual	~TransportUnit (){}
};

class Car : public TransportUnit
{
public:
	double calculateToll(double distance) const override
	{
		cout << "Плата для Car: ";
		return distance * 0.1;
	}
	~Car()
	{
		cout << "Вызов деструктора Car: " << endl;
	}
};

class Truck : public TransportUnit
{
public:
	double calculateToll(double distance) const override 
	{
		cout << "Плата для Truck: ";
        return distance * 0.3 + 5.0;
    }
	~Truck()
	{
		cout << "Вызов деструктора Truck: " << endl;

	}
};