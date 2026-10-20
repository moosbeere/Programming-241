#pragma once
#include "Route.h"
#include "TransportUnit.h"
#include <memory>

class AssignedRoute
{
private:
	Route route;
	//TransportUnit* transport;
	std::unique_ptr<TransportUnit> transport_;
public:
	AssignedRoute(Route& route, std::unique_ptr<TransportUnit> transport);
	double calculateTotalCost();
};

