#include <iostream>
#include "Weapon.h"


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 25, 2);
    sword.printInfo();

    Weapon axe("Топор", 15, 7);
    axe.printInfo();

    cout << "Вес " << sword.name << " + " << axe.name << " = " << sword.newWeapon(axe) << endl;

    Weapon* bow = new Weapon("Лук", 10, 0.1);
    bow->printInfo();
    delete bow;
    cout << endl;

    if (sword.checkWeight(3)) {
        cout << "Вес оружия: " << sword.name << " < 3" << endl;
    }
    else {
        cout << "Вес оружия: " << sword.name << " >= 3" << endl;
    }

    cout << "Перегрузка функцией принимающей просто вес = " << sword.newWeapon(10) << endl;

}