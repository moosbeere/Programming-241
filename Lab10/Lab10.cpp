#include <iostream>
#include "Tram.h"
#include "Bus.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Tram tram("Tatra", 60, "5", 120, 600);
    Bus bus("MAN", 90, "32", 80, "Diesel");

    cout << "Информация по трамваю:" << endl;
    tram.info();
    cout << "\nИнформация по автобусу:" << endl;
    bus.info();

    cout << "\nУскоряем автобус:" << endl;
    bus.accelerate(30);
    bus.getStatus();

    std::cout << "Сравниваем скорости: ";
    if (bus < tram)
        cout << "Автобус медленнее" << endl;
    else
        cout << "Трамвай медленнее или скорость одинаковая" << endl;

    return 0;
}