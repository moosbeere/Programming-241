#include "DispatchCenter.h"

// ======================================================
// Инициализация static-поля
// ======================================================

int DispatchCenter::totalVehiclesDispatched = 0;

// ======================================================
// Метод report
// ======================================================

void DispatchCenter::report() {

    cout << "Всего транспорта создано: "
        << totalVehiclesDispatched
        << endl;
}