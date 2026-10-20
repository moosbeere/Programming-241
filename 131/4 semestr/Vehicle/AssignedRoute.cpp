#include "AssignedRoute.h"

AssignedRoute::AssignedRoute(Route& route, std::unique_ptr<TransportUnit> transport): route(route),transport_(std::move(transport)){}

double AssignedRoute::calculateTotalCost()
{
	return transport_->calculateToll(route.getLength());
}
