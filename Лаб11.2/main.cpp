#include <iostream>
#include <string>
#include <stdexcept>
#include "FreightVehicle.h"
#include "LogisticsOrder.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        FreightVehicle truck(1000);

        LogisticsOrder order(1200);

        order.assignVehicle(truck);
    }
    catch (const invalid_argument& x) {
        cout << x.what() << endl;
    }
}