#include <iostream>
#include "weapon.h"
#include "player.h"

using namespace std;

string weaponTypeToString(WeaponType type) {
    if (type == ONEHANDED) return "Одноручное оружие";
    if (type == TWOHANDED) return "Двуручное оружие";
    if (type == BOW) return "Лук";
    if (type == CROSSBOW) return "Арбалет";
    return "Неизвестный тип";
}

int main() {
    setlocale(LC_ALL, "ru");

    // 2, 3. Создание оружий с типами и вывод текстового представления
    Weapon sword("Меч воина", 40, 4.5f, ONEHANDED);
    Weapon greatsword("Двуручный меч", 60, 8.2f, TWOHANDED);
    Weapon bow("Длинный лук", 35, 2.1f, BOW);
    Weapon crossbow("Тяжелый арбалет", 50, 5.8f, CROSSBOW);

    
    // 3. Использование if для вывода текстового представления
    WeaponType swordType = sword.getType();
    if (swordType == ONEHANDED) {
        cout << sword.getName() << " - Одноручное оружие" << endl;
    }

    cout << greatsword.getName() << " - " << weaponTypeToString(greatsword.getType()) << endl;
    cout << bow.getName() << " - " << weaponTypeToString(bow.getType()) << endl;
    cout << crossbow.getName() << " - " << weaponTypeToString(crossbow.getType()) << endl;

    
    // 4, 5, 6. Тестирование структуры игрока
    Player player1;
    player1.id = 1;
    player1.login = "dragon_slayer";
    player1.password = "qwerty123";
    player1.printInfo();

    Player player2 = { 2, "mage_arch", "fireball_777" };
    player2.printInfo();

 
    // 11. Тестирование магического оружия
    MagicWeapon fireStaff("Огненный посох", 25, 3.0f, TWOHANDED, 15);
    MagicWeapon defaultMagicWeapon;  // Конструктор без параметров

    // 10. GET-метод для дополнительного урона
    cout << "\nДополнительный урон огненного посоха: "
        << fireStaff.getExtraDamage() << endl;

    cout << "Вес огненного посоха: " << fireStaff.getWeight() << " кг" << endl;
    cout << "Можно поднять одной рукой (max 5кг)? "
        << (fireStaff.canLift(5.0f) ? "Нет" : "Да") << endl;

    // 14. Проверка урона магического оружия
    cout << "Урон обычного меча: " << sword.getDamage() << endl;
    cout << "Урон огненного посоха (базовый + магический): "
        << fireStaff.getDamage() << " = "
        << fireStaff.Weapon::getDamage() << " + "
        << fireStaff.getExtraDamage() << endl;

    
    // 15, 16. Проверка операторов сравнения
    cout << "Меч (" << sword.getDamage() << ") > Лук (" << bow.getDamage() << ")? "
        << (sword > bow ? "Да" : "Нет") << endl;

    cout << "Огненный посох (" << fireStaff.getDamage()
        << ") > Двуручный меч (" << greatsword.getDamage() << ")? "
        << (fireStaff > greatsword ? "Да" : "Нет") << endl;

    cout << "Меч (" << sword.getDamage() << ") < Арбалет (" << crossbow.getDamage() << ")? "
        << (sword < crossbow ? "Да" : "Нет") << endl;

    cout << "Магическое оружие по умолчанию (" << defaultMagicWeapon.getDamage()
        << ") < Огненный посох (" << fireStaff.getDamage() << ")? "
        << (defaultMagicWeapon < fireStaff ? "Да" : "Нет") << endl;

    // Сравнение через указатели (полиморфизм)
    Weapon* weapons[4];
    weapons[0] = &sword;
    weapons[1] = &greatsword;
    weapons[2] = &fireStaff;        // Указатель базового класса на дочерний
    weapons[3] = &defaultMagicWeapon;

    for (int i = 0; i < 4; i++) {
        cout << "Оружие " << i + 1 << ": " << weapons[i]->getName()
            << " (урон: " << weapons[i]->getDamage() << ")" << endl;
    }

    
    MagicWeapon magicSword("Волшебный клинок", 30, 2.8f, ONEHANDED, 10);
    MagicWeapon magicBow("Лунный лук", 20, 1.8f, BOW, 25);
    MagicWeapon magicCrossbow("Штормовой арбалет", 40, 4.5f, CROSSBOW, 15);

    cout << "\n" << magicSword.getName() << " - "
        << weaponTypeToString(magicSword.getType())
        << " (урон: " << magicSword.getDamage() << ")" << endl;

    cout << magicBow.getName() << " - "
        << weaponTypeToString(magicBow.getType())
        << " (урон: " << magicBow.getDamage() << ")" << endl;

    cout << magicCrossbow.getName() << " - "
        << weaponTypeToString(magicCrossbow.getType())
        << " (урон: " << magicCrossbow.getDamage() << ")" << endl;

    return 0;
}