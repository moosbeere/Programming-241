#include <iostream>
#include "weapon.h"
using namespace ::std;

int main()
{
    setlocale(LC_ALL, "RUS");

    cout << "================Задание 1================\n";

    weapon weapon1("меч", 10, 20, ONEHANDED);
    weapon1.print();

    weapon weapon2;
    weapon2.print();

    cout << "================Задание 2================\n";

    weapon* weapon3 = new weapon("двуручный меч", 3, 1, TWOHANDED);
    weapon3->print();
    delete weapon3;

    if (weapon1.weight_possible() == 1)
        cout << "\nВес оружия " << weapon1.getName() << " допустим (True)\n\n";

    cout << "Вес текущего и переданного оружия: " << weapon1.suma_weight(weapon2) << "\n\n";

    cout << "Вес текущего и переданного веса: " << weapon2.suma_weight2(5) << "\n\n";

    cout << "Вес текущего и переданного оружия с перегрузкой: " << weapon1.suma_weight3(weapon2) << "\n\n";

    cout << "Текущий урон: " << weapon1.getdamage() << "\n\n";
    weapon1.setdamage(300);
    cout << "Новый урон: " << weapon1.getdamage() << "\n\n";

    Characteristic char1(25);
    cout << "Сила: " << char1.getStrength() << "\n";

    cout << "Общий урон (сила + урон меча): " << char1.GetDamage(weapon1) << "\n\n";

    cout << "================Задание 3================\n";
    
    cout << "Тип оружия у weapon1: ";
    if (weapon1.getType() == ONEHANDED) {
        cout << "Одноручное оружие\n";
    }
    else if (weapon1.getType() == TWOHANDED) {
        cout << "Двуручное оружие\n";
    }
    else if (weapon1.getType() == BOW) {
        cout << "Лук\n";
    }
    else if (weapon1.getType() == CROSSBOW) {
        cout << "Арбалет\n";
    }
    cout << "\n";

    cout << "================Задание 4, 5, 6================\n";
  
    Player player1;
    player1.id = 1;
    player1.login = "vitalik_rogalik";
    player1.password = "krutoi";
    cout << "Информация об игроке:\n";
    player1.printPlayer();

    cout << "================Задание 7-11================\n";
    MagicWeapon magicSword("Моргенштерн", 8, 40, 15, ONEHANDED);
    cout << "Магическое оружие:\n";
    magicSword.print();
    cout << "Дополнительный урон: " << magicSword.getAdditionalDamage() << "\n";
    cout << "Общий урон (базовый + дополнительный): " << magicSword.getdamage() << "\n\n";

    MagicWeapon defaultMagic;
    cout << "Магическое оружие по умолчанию:\n";
    defaultMagic.print();
    cout << "Дополнительный урон: " << defaultMagic.getAdditionalDamage() << "\n";
    cout << "Общий урон: " << defaultMagic.getdamage() << "\n\n";

    cout << "================Задание 12-15================\n";
    cout << "Обычное оружие урон: " << weapon1.getdamage() << "\n";
    cout << "Магическое оружие урон: " << magicSword.getdamage() << " (базовый: "
        << ((weapon&)magicSword).weapon::getdamage() << " + дополнительный: " << magicSword.getAdditionalDamage() << ")\n\n";

  
    cout << "================Задание 16-17================\n";
    cout << "Сравнение оружия по урону:\n";
    cout << weapon1.getName() << " (" << weapon1.getdamage() << " урона) > "
        << weapon2.getName() << " (" << weapon2.getdamage() << " урона): "
        << (weapon1 > weapon2 ? "true" : "false") << "\n";


    return 0;
}