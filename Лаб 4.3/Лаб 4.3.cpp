#include <iostream>
#include "Weapon.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 50, 3);
    cout << "Обычный объект: " << sword.name << ", урон: " << sword.damage << ", вес: " << sword.weight << endl;

    Weapon* axe = new Weapon("Топор", 80, 5);
    cout << "Динамический объект: " << axe->name << ", урон: " << axe->damage << ", вес: " << axe->weight << endl;

    cout << "Вес = 2 ";
    if (sword.canLift(2)) cout << "Поднимет";
    else cout << "Не поднимет";
    cout << endl;

    cout << "Меч + Топор = " << sword.totalWeight(*axe) << endl;
    cout << "Меч + 10 = " << sword.totalWeight(10) << endl;

    delete axe;

    return 0;
}
