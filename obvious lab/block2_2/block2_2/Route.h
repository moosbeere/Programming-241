#pragma once
using namespace std;
#include <string>
#include "Unit.h"

class Route {
public:
	string startPoint;
	string endPoint;
	int length;

	void PrintInfo();
};


class AssignedRoute {
private:
	TransportUnit* transport;
	Route* route;

public:
	AssignedRoute(TransportUnit* t, Route* r);

	~AssignedRoute();

	double calculareTotalcost();

	void PrintInfo();

};
