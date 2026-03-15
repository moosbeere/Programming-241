#pragma once 
#include <iostream>
#include <string>
using namespace std;

class DispatchCenter {
public:
	static int totalVehiclesDispatched;
	static void report();
};

class TransportUnit {
public:
	string b;
	TransportUnit( string b);
};