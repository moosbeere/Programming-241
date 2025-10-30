#include <iostream>
#include "Weapon.h"
#include "MagicWeapon.h"
#include "OneTimeWeapon.h"
#include "Hands.h"


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Weapon sword; вылезает ошибка, невозможно создать экземпляр абстрактного класса
    MagicWeapon sword;
    sword.printInfo();
    cout << endl;
    sword.Attack();
    OneTimeWeapon mushket = OneTimeWeapon("Мушкет", 10, 5, CROSSBOW);
    mushket.Attack();
    mushket.Attack();

    // Из-за того что мы можем передать любой тип в Hands мы должны перегрузить оператор <<
    // Во всех классах оружия (не только в Weapon, потому что он абстрактный)
    // Поэтому мы везде создаём friend ostream& operator<<
    // которая возвращает поток, чтобы можно было делать вывод по дочерним классам оружия
    Hands<OneTimeWeapon, MagicWeapon> weapons(mushket, sword);
    weapons.printHands();
    cout << endl;

    Hands<int, int> weaponn(1, 2);
    weaponn.printHands();
    cout << endl;
}