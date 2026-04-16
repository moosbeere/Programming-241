#include <iostream>
#include "vehicle.h"
#include "route.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // Создаем транспорт (на стеке)
    Car car;
    Truck truck;

    // Создаем назначенные маршруты (композиция с Route)
    AssignedRoute route1("Москва", "Санкт-Петербург", 705.0, &car);
    AssignedRoute route2("Екатеринбург", "Челябинск", 210.0, &truck);

    // Выводим информацию
    route1.printFullInfo();
    route2.printFullInfo();

    // Демонстрация замены транспорта (агрегация)
    cout << "--- Замена транспорта ---" << endl;
    route1.setTransportUnit(&truck);
    route1.printFullInfo();

    // Демонстрация полиморфизма
    cout << "--- Полиморфизм ---" << endl;
    TransportUnit* transports[] = { &car, &truck };
    double distances[] = { 100.0, 200.0 };

    for (int i = 0; i < 2; i++) {
        cout << "Стоимость для ";
        transports[i]->printInfo();
        cout << " на " << distances[i] << " км: "
            << transports[i]->calculateToll(distances[i]) << " у.е." << endl;
    }

    return 0;
}