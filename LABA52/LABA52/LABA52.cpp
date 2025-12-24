#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    cout << "================Игрок================\n";
    Player player1;
    player1.id = 1;
    player1.login = "vitalik_rogalik";
    player1.password = "krutoi";
    player1.printPlayer();

    cout << "================Магическое оружие================\n";
    MagicWeapon magicSword("Моргенштерн", 8, 40, 15);
    magicSword.print();
    cout << "Атака: ";
    magicSword.Attack();
    cout << "Общий урон: " << magicSword.getdamage() << endl;

    MagicWeapon defaultMagic;
    defaultMagic.print();
    defaultMagic.Attack();
    cout << "Общий урон: " << defaultMagic.getdamage() << endl;

    cout << "================Одноразовое оружие================\n";
    DisposableWeapon disposableKnife("Даедалус", 2, 30);
    disposableKnife.Attack();
    disposableKnife.Attack();
    disposableKnife.reset();
    disposableKnife.Attack();

    cout << "================Шаблон DualWield================\n";
    MagicWeapon leftMagic("Щит магический", 5, 10, 5);
    DisposableWeapon rightDisposable("Булава одноразовая", 6, 25);

    DualWield<MagicWeapon, DisposableWeapon> warriorHands(leftMagic, rightDisposable);
    cout << "Левая рука: " << warriorHands.getLeftHand().getName() << endl;
    cout << "Правая рука: " << warriorHands.getRightHand().getName() << endl;

    cout << "Атака оружием из обеих рук:\n";
    warriorHands.getLeftHand().Attack();
    warriorHands.getRightHand().Attack();

    DualWield<int, int> weaponIDs(1001, 1002);
    cout << "ID оружия: " << weaponIDs.getLeftHand() << ", " << weaponIDs.getRightHand() << endl;
    weaponIDs.setLeftHand(1003);
    weaponIDs.setRightHand(1004);
    cout << "Новые ID: " << weaponIDs.getLeftHand() << ", " << weaponIDs.getRightHand() << endl;

    cout << "================Сравнение оружия================\n";
    MagicWeapon magicWeapon1("Сильный меч", 10, 50, 20);
    MagicWeapon magicWeapon2("Слабый меч", 8, 30, 10);
    cout << magicWeapon1.getName() << " (" << magicWeapon1.getdamage() << " урона) > "
        << magicWeapon2.getName() << " (" << magicWeapon2.getdamage() << " урона): "
        << (magicWeapon1 > magicWeapon2 ? "true" : "false") << endl;

    Characteristic char1(25);
    cout << "Сила: " << char1.getStrength() << endl;
    cout << "Общий урон (сила + урон магического меча): " << char1.GetDamage(magicSword) << endl;

    return 0;
}