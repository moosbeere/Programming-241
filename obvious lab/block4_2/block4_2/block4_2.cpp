#include <iostream>
#include "Vehicle.h"
#include "FreightVehicle.h"
#include "LogisticsOrder.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        FreightVehicle truck("Volvo", 120, 10.0);
        LogisticsOrder order1(5.0);
        order1.assignVehicle(truck);
        cout << "Order1 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    try {
        FreightVehicle truck("MAN", 100, 5.0);
        LogisticsOrder order2(7.0);
        order2.assignVehicle(truck);
        cout << "Order2 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    try {
        Vehicle car("Lada", 250);
        LogisticsOrder order3(200);
        order3.assignVehicle(car);
        cout << "Order3 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    try {
        FreightVehicle truck("Kamaz", 90, 8.0);
        LogisticsOrder order4(-3.0);
        order4.assignVehicle(truck);
        cout << "Order4 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    return 0;
}