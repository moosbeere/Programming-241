#include <iostream>
#include "Vehicle.h"
#include "FreightVehicle.h"
#include "LogisticsOrder.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        FreightVehicle truck("TOYOTA", 120, 10);
        LogisticsOrder order1(9);
        order1.assignVehicle(truck);
        cout << "Заказ1 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    try {
        FreightVehicle truck("TRUCK", 100, 5);
        LogisticsOrder order2(3);
        order2.assignVehicle(truck);
        cout << "Заказ2 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    try {
        Vehicle car("AUDI", 200);
        LogisticsOrder order3(200);
        order3.assignVehicle(car);
        cout << "Заказ3 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    try {
        FreightVehicle truck("Kamaz", 90, 8);
        LogisticsOrder order4(-3);
        order4.assignVehicle(truck);
        cout << "Заказ4 добавлен.\n";
    }
    catch (invalid_argument e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    return 0;
}