#include<iostream>
using namespace std;

#include "Route.h"
#include"Unit.h"

int main(){
	setlocale(LC_ALL, "RU");

	TransportUnit* Car = new car();


	Route route1;
	
	route1.startPoint = "Душанбе";
	route1.endPoint = "Москва";
	route1.length = 2500;

	AssignedRoute assigned1(Car, &route1);

	assigned1.PrintInfo();
	delete Car;
	
}