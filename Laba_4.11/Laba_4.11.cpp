#include <iostream>
#include "logistics_order.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    FreightVehicle myTruck("Газель", 3000);

    cout << "Проверка 1: Хороший заказ " << endl;
    try {
        LogisticsOrder goodOrder(1500);
        goodOrder.assignVehicle(myTruck);
    }
    catch (const invalid_argument& e) {
        cout << "Перехвачено исключение: " << e.what() << endl;
    }

    cout << "\nПроверка 2: Слишком тяжелый заказ " << endl;
    try {
        LogisticsOrder heavyOrder(5000);
        heavyOrder.assignVehicle(myTruck);
    }
    catch (const invalid_argument& e) {
        cout << "Перехвачено исключение: " << e.what() << endl;
    }
    return 0;
}
