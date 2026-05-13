#include <iostream>
#include <memory>
#include "vehicle.h"
#include "route.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // Создаем маршрут и сразу передаем туда машину через make_unique
    AssignedRoute myRoute("Москва", "Питер", 700, make_unique<Car>());
    myRoute.printFullInfo();

    // Меняем машину на грузовик
    cout << "Меняем транспорт..." << endl;
    myRoute.setTransportUnit(make_unique<Truck>());
    myRoute.printFullInfo();

    return 0;
}
