#pragma once
#include "Route.h"
#include "TransportUnit.h"
#include <memory>


class AssignedRoute
{
private:
	Route route;
	std::unique_ptr<TransportUnit> unitTr;

public:
	AssignedRoute(Route &route, std::unique_ptr<TransportUnit> unitTr);
	void CalculateTotalCost();
};

