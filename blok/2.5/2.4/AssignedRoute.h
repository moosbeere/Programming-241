#pragma once
#include "Route.h"
#include "TransportUnit.h"

class AssignedRoute
{
public:
	Route route;
	TransportUnit* transport;

	AssignedRoute(const Route& r, TransportUnit* t);

	double calculateTotalCost();
};

