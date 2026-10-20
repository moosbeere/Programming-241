// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vehicle.h"
#include "FreightVehicle.h"
#include "TransportUnit.h"
#include "Truck.h"
#include "Car.h"
#include "Route.h"
#include "AssignedRoute.h"
#include "DispatchCenter.h"
#include <memory>
#include <vector>
#include <memory>



int main()
{

	//Lab7


	//Lab6 
	//Vehicle Lada("Lada", 180);
	//Vehicle bmw("BMW", 200);
	//Vehicle renault("Renault", 280);
	//DispatchCenter::report();

	//Lab1
	//Vehicle Lada("Lada", 180);
	//Lada.getStatus();
	//Lada.accelerate(100);
	//Lada.getStatus();
	//Lada.brake(150);
	//Lada.getStatus();
	//Lada.accelerate(200);
	//Lada.getStatus();

	//Lab2
	//std::vector<Vehicle> vector;
	//Vehicle lada("Lada", 180);
	//Vehicle bmw("BMW", 200);
	//Vehicle renault("Renault", 280);
	//vector.push_back(lada);
	//vector.push_back(bmw);
	//vector.push_back(renault);
	//for (auto &i : vector) {
	//	i.accelerate(190);
	//	i.getStatus();
	//}
	//for (auto &i : vector) {
	//	i.brake(100);
	//	i.getStatus();
	//}

	//Lab3
	//FreightVehicle capacity("ZIL", 80, 10);
	//capacity.getStatus();
	//capacity.accelerate(30);
	//capacity.getStatus();

	//Lab4
	//TransportUnit* massiv[2] = { new Truck(), new Car() };
	//for (auto* i : massiv) {
	//	std::cout << i->calculateToll(100) << std::endl;
	//}

	//Lab5
	/*Car Lada("Lada");
	Route Penza("Moscow", "Penza", 500);
	Penza.printInfo();
	AssignedRoute newRoute(Penza, &Lada);*/


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
