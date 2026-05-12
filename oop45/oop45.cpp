#include <iostream>
#include <windows.h>   // Для SetConsoleCP и SetConsoleOutputCP

#include "Car.h"
#include "Truck.h"
#include "AssignedRoute.h"

using namespace std;


// Главная функция


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Car car;
    Truck truck;

    Route route1("Рига", "Юрмала", 25);
    Route route2("Рига", "Даугавпилс", 230);

    AssignedRoute assigned1(route1, &car);
    AssignedRoute assigned2(route2, &truck);
    
    // Вывод информации

    cout << " Маршрут 1 " << endl;

    assigned1.printAssignedInfo();

    cout << endl;

    cout << " Маршрут 2 " << endl;

    assigned2.printAssignedInfo();

    return 0;
}