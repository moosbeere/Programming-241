#include "Unit.h"
#include <iostream>
#include <string>
using namespace std;


car::car(){}


double car::calculateToll(double distance) const {
	return distance * 0.1;
}

Truck::Truck() {}
double Truck::calculateToll(double distance) const {
	return distance * 0.3 + 5.0;
}