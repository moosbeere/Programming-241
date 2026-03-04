#include "Route.h"
#include <iostream>
#include <memory>
using namespace std;

void Route::PrintInfo()
{
    cout << "Точка отправления: " << startPoint << endl;
    cout << "Точка назначения: " << endPoint << endl;
    cout << "Длина: " << length << " км" << endl;
}

AssignedRoute::AssignedRoute(unique_ptr<TransportUnit> t, Route* r)
    : transport(move(t)), route(r)  
{

}

AssignedRoute::~AssignedRoute()
{

}

double AssignedRoute::calculateTotalCost()
{
    return transport->calculateToll(route->length);
}

void AssignedRoute::PrintInfo()
{
    route->PrintInfo();
    cout << "Транспорт: " << transport->getLicensePlate() << endl;
    cout << "Стоимость проезда: " << calculateTotalCost() << endl;
}