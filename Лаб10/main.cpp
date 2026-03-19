#include <iostream>
#include "Bus.h"
#include "Tram.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    Bus bus("Автобус", 80, 24, 50, "Дизель");
    Tram tram(5, 120, 600);

    bus.print();
    tram.print();

    return 0;
}