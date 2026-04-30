#include "AssignedRoute.h"

AssignedRoute::AssignedRoute(const Route& r, TransportUnit* t) : route(r), transport(t) {}

double AssignedRoute::calculateTotalCost()
{
	return transport->calculateToll(route.getLen());
}
