#include <iostream>
#include <memory>  
using namespace std;

#include "Route.h"
#include "Unit.h"

int main() {
    setlocale(LC_ALL, "RU");


    Route route1;
    route1.startPoint = "Душанбе";
    route1.endPoint = "Москва";
    route1.length = 2500;

    Route route2;
    route2.startPoint = "Москва";
    route2.endPoint = "Саранск";
    route2.length = 700;



    {
    

        unique_ptr<TransportUnit> carPtr = make_unique<Car>("A123BC");
        AssignedRoute assigned1(move(carPtr), &route1);
        assigned1.PrintInfo();

     
    }

    {
        cout << "" << endl;

        AssignedRoute assigned2(make_unique<Truck>("B456CD"), &route2);
        assigned2.PrintInfo();
    }

    {
        cout << endl;


        AssignedRoute trip1(make_unique<Car>("909"), &route1);
        AssignedRoute trip2(make_unique<Truck>("129"), &route2);
        AssignedRoute trip3(make_unique<Car>("341"), &route1);

        trip1.PrintInfo();
        trip2.PrintInfo();
        trip3.PrintInfo();

        double total = trip1.calculateTotalCost() +
            trip2.calculateTotalCost();
            trip3.calculateTotalCost();

        cout << "\nОБЩАЯ СТОИМОСТЬ ВСЕХ ПОЕЗДОК: " << total <<  endl;
    }

  

}