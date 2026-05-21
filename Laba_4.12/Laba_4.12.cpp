#include <iostream>
#include "traffic_flow.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // Создаем дорогу 2 км, лимит 90 км/ч (25 м/с)
    RoadSegment highway(2000, 25.0);

    // Создаем поток машин
    TrafficFlow flow;
    flow.addVehicle(make_unique<Car>("Ауди", 40.0));
    flow.addVehicle(make_unique<Truck>("КамАЗ", 20.0));

    cout << "НАЧАЛО\n";

    // 5 шагов по 3 секунды
    for (int step = 1; step <= 5; ++step) {
        cout << "\nШаг времени " << step << " (через 3 сек):" << endl;
        flow.simulate(highway, 3.0);
        flow.printStatus();
    }

    return 0;
}
