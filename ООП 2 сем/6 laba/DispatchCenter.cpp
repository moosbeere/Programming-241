#include "DispatchCenter.h"
#include <iostream>
using namespace std;

int DispatchCenter::totalVehiclesDispatched = 0;

void DispatchCenter::report() {
    cout << "=====================================" << endl;
    cout << "ОТЧЕТ ДИСПЕТЧЕРА:" << endl;
    cout << "Всего обслужено транспортных средств: " << totalVehiclesDispatched << endl;
    cout << "=====================================" << endl;
}

void DispatchCenter::addVehicle() {
    totalVehiclesDispatched++;  // Увеличиваем счетчик
}
