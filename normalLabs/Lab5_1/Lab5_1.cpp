#include <iostream>
#include "Weapon.h"
#include "MagicWeapon.h"
#include "Player.h"
#include "WeaponType.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 25, 2, ONEHANDED);
    sword.printInfo();

    Weapon axe("Топор", 15, 7, TWOHANDED);
    axe.printInfo();
    Weapon* bow = new Weapon("Лук", 10, 0.1, BOW);
    bow->printInfo();


    if (sword.getType() == ONEHANDED) {
        cout << endl << sword.getName() << " - это одноручное оружие" << endl;
    }
    Player player;
    player.id = 1;
    player.login = "login";
    player.password = "password";
    player.printAll();
    cout << endl;

    MagicWeapon ump = MagicWeapon("Пистолет-пулемет", 14, 2, CROSSBOW, 10);
    ump.printInfo();
    cout << "Общий урон: " << ump.getDamage() << endl;
    cout << "Дополнительный магический урон: " << ump.getExtraDamage() << endl;
    cout << endl;

    MagicWeapon magicSword("Магический меч", 10, 2, ONEHANDED, 10);
    magicSword.printInfo();
    cout << "Общий урон: " << magicSword.getDamage() << endl;


    cout << "Урон Пистолет-пулемета > магического меча: " << (ump > magicSword ? "Да" : "Нет") << endl;
    cout << "Урон пистолета-пулемета > меча: " << (ump > sword ? "Да" : "Нет") << endl;
    delete bow;
}