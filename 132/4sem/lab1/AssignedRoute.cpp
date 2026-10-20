#include "AssignedRoute.h"

AssignedRoute::AssignedRoute(Route &route, std::unique_ptr<TransportUnit> unitTr):route(route), unitTr()
{

}

void AssignedRoute::CalculateTotalCost()
{
	unitTr->calculateToll(route.getLength());
}
