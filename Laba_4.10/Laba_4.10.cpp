#include <iostream>
#include "public_transport.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    cout << "--- Создаем Автобус ---" << endl;
    Bus myBus("Автобус", 80, "43-Э", 105, "Дизель");

    cout << "\n--- Создаем Трамвай ---" << endl;
    Tram myTram("Трамвай", 60, "27-А", 150, 600);

    cout << "\n--- Вывод информации ---" << endl;
    myBus.printInfo();
    myTram.printInfo();

    return 0;
}
