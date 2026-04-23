#include "DispatchCenter.h"
#include "Vehicle.h"

int main() {
    // Отчёт до создания объектов
    DispatchCenter::report();

    Vehicle car1("BMW", "A123BC");
    Vehicle car2("KIA K5", "B456DE");
    Vehicle truck1("Kamaz", "C789FG");

    DispatchCenter::report();

    return 0;
}
