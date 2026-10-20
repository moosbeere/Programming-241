// Vehicle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vehicle.h"
#include "FreightVehicle.h"
#include "TransportUnit.h"
#include "Car.h"
#include "Truck.h"
#include <vector>
#include "AssignedRoute.h"
#include "Route.h"
#include "DispatchCenter.h"
#include "Warehouse.h"
#include "Bus.h"
#include <algorithm>

int main()
{
    setlocale(LC_ALL,"Russian");

    //Lab10
	Bus bus("Mercedes", 120, 42, 50, "Diesel");
	bus.getStatus();
	Tram tram("Tatra", 80, 5, 200, 750);
	tram.getStatus();

    //Lab9
    //Vehicle lada("lada", 180);
    //Vehicle bmw("bmw", 280);
    //Vehicle renault("renault", 260);
    //Vehicle arr[] = { lada, bmw, renault };
    //std::sort(arr, arr + 3);
    //for (auto i : arr) {
    //    i.getStatus();
    //}


    //Lab8
    /*Warehouse<int> cargoNumber;
    cargoNumber.addItem(1);
    cargoNumber.addItem(2);
    cargoNumber.addItem(3);

    std::cout << " оличество грузов на складе: " << cargoNumber.getTotalItems() << std::endl;
    for (int i = 0; i < cargoNumber.getTotalItems(); i++) {
        std::cout << "номер груза: " << cargoNumber.getItem(i) << std::endl;
    }

    Warehouse<std::string> cargoName;
    cargoName.addItem("First");
    cargoName.addItem("Second");
    cargoName.addItem("Third");

    std::cout << " оличество грузов на складе: " << cargoName.getTotalItems() << std::endl;
    for (int i = 0; i < cargoName.getTotalItems(); i++) {
        std::cout << "номер груза: " << cargoName.getItem(i) << std::endl;
    }*/

    //Lab7
    //auto lada = std::make_unique<Car>();
    //Route piter("Moscow", "Piter", 700);
    ////piter.printInfo();
    //AssignedRoute cost(piter, std::move(lada));
    //std::cout << cost.calculateTotalCost();

    //Lab6
    /*Vehicle car1("dkfjk", 78);
    Vehicle car2("dkfjk", 78);
    Vehicle car3("dkfjk", 78);
    Vehicle truck("dkfjk", 78);
    DispatchCenter::report();*/

    ////Lab5
    //Car Lada;
    //Route piter("Moscow", "Piter", 700);
    //piter.printInfo();
    //AssignedRoute cost(piter, &Lada);
    //std::cout << cost.calculateTotalCost();


    //Lab4
    //TransportUnit* unit[] = { new Car(), new Truck()};
    //for (auto element : unit) {
    //    cout << element->calculateToll(100) << endl;
    //}

    //Lab1
    //Vehicle Lada("Lada", 150);
    //Lada.getStatus();
    //Lada.accelerate(100);
    //Lada.getStatus();
    //Lada.accelerate(700);
    //Lada.getStatus();
    //Lada.brake(100);
    //Lada.getStatus();

    //Lab2
    //vector<Vehicle> car;
    //string arr[] = {"BMW", "Renault", "KIA", "VolksWagen"};
    //for (int i = 0; i < 4; i++) {
    //    car.push_back(Vehicle(arr[i], (i+1)*100)); // Vehicle("BMW", 100)
    //}
    //for (auto a : car) {
    //    a.getStatus();
    //    a.accelerate(200);
    //    a.getStatus();
    //}

    //Lab3
    //FreightVehicle truck("Truck", 100, 80);
    //truck.getStatus();
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
