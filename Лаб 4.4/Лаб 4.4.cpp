#include <iostream>
#include "Weapon.h"
#include "Characteristic.h"
#include "MyMath.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 50, 3);

    cout << "Оружие: " << sword.getName()
        << ", урон: " << sword.getDamage()
        << ", вес: " << sword.getWeight() << endl;

    sword.setDamage(70);
    cout << "После изменения урона: " << sword.getDamage() << endl;

    Characteristic hero(20);
    cout << "Итоговый урон героя с оружием: "
        << hero.GetDamage(sword) << endl;

    cout << "\nПроверка MyMath:\n";
    cout << "Add: " << MyMath::Add(5, 3) << endl;
    cout << "Sub: " << MyMath::Sub(10, 4) << endl;
    cout << "Mult: " << MyMath::Mult(3, 7) << endl;
    cout << "Div: " << MyMath::Div(20, 4) << endl;

    cout << "Количество вызовов MyMath: "
        << MyMath::callCount << endl;

    return 0;
}
