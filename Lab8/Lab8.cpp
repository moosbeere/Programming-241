#include <iostream>
#include <string>
#include "Warehouse.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Warehouse<int> intWarehouse;
    intWarehouse.addItem(101);
    intWarehouse.addItem(202);
    intWarehouse.addItem(303);

    cout << "Склад целых чисел, всего грузов: " << intWarehouse.getTotalItems() << endl;
    for (int i = 0; i < intWarehouse.getTotalItems(); ++i) {
        cout << "  Элемент " << i << ": " << intWarehouse.getItem(i) << endl;
    }

    Warehouse<string> stringWarehouse;
    stringWarehouse.addItem("первый");
    stringWarehouse.addItem("второй");
    stringWarehouse.addItem("третий");

    cout << "\nСклад строк, всего грузов: " << stringWarehouse.getTotalItems() << endl;
    for (int i = 0; i < stringWarehouse.getTotalItems(); ++i) {
        cout << "  Элемент " << i << ": " << stringWarehouse.getItem(i) << endl;
    }

    try {
        cout << "\nПробуем получить элемент с индексом 5: ";
        cout << intWarehouse.getItem(5) << endl;
    }
    catch (out_of_range& err) {
        cout << "Ошибка: " << err.what() << endl;
    }

    return 0;
}