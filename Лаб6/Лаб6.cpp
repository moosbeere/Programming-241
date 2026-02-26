#include <iostream>
using namespace std;

class DispatchCenter {
public:
    static int totalVehiclesDispatched;

    static void report() {
        cout << "Общее количество обслуженных транспортных средств: " << totalVehiclesDispatched << endl;
    }
};

int DispatchCenter::totalVehiclesDispatched = 0;

class Vehicle {
public:
    Vehicle() {
        DispatchCenter::totalVehiclesDispatched++;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Vehicle v1;
    Vehicle v2;
    Vehicle v3;

    DispatchCenter::report();

    return 0;
}