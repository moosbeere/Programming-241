#include "Route.h"
#include <iostream>
using namespace std;
#include <string>
#include "Unit.h"


void Route::PrintInfo()
{
	cout<< "Точка отправление: "<<startPoint << endl;
	cout << "Точка назначения: " << endPoint << endl;
	cout << "Длина" << length << endl;
}

AssignedRoute::AssignedRoute(TransportUnit* t, Route* r):transport(t),route(r)
{
	cout << "Создание маршрута..." << endl;
}

AssignedRoute::~AssignedRoute()
{
	cout << "удаление маршрута...." << endl;
}

double AssignedRoute::calculareTotalcost()
{
	return transport->calculateToll(route->length);
}

void AssignedRoute::PrintInfo()
{
	cout << "Назначенный маршрут: " << endl;
	route->PrintInfo();
	cout << "стоимость проезда: " << calculareTotalcost() << endl;
}





