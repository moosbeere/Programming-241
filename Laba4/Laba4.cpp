#include <iostream>
#include "weapon.h"
#include "characteristic.h"
#include "mymath.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
 
    Weapon sword("Двуручный меч", 30, 5.2f);
    Weapon defaultWeapon;

     cout << "\nОружие 1:";
    cout << "\n  Название: " << sword.getName();
    cout << "\n  Урон: " << sword.getDamage();
    cout << "\n  Вес: " << sword.getWeight();

    cout << "\n\nОружие 2 (по умолчанию):";
    cout << "\n  Название: " << defaultWeapon.getName();
    cout << "\n  Урон: " << defaultWeapon.getDamage();
    cout << "\n  Вес: " << defaultWeapon.getWeight();

     {
        Weapon tempWeapon("Временный лук", 15, 2.1f);
        cout << "\nВременное оружие: " << tempWeapon.getName();
    } 

    Weapon* dynamicWeapon = new Weapon("Динамический топор", 25, 4.3f);
    cout << "\nДинамическое оружие: " << dynamicWeapon->getName();
    delete dynamicWeapon;  

    cout << "\nПроверка подъема оружия (max вес = 4.0):";
    cout << "\n  Меч слишком тяжелый? " << (sword.canLift(4.0f) ? "Да" : "Нет");
    cout << "\n  Оружие по умолчанию слишком тяжелое? "
        << (defaultWeapon.canLift(4.0f) ? "Да" : "Нет");

    
    cout << "\n\nСуммарный вес двух оружий: "
        << sword.getTotalWeight(defaultWeapon);
    cout << "\nВес меча + 10кг: " << sword.getTotalWeight(10.0f);

    
    cout << "\nИсходный урон меча: " << sword.getDamage();
    sword.setDamage(35);
    cout << "\nНовый урон меча: " << sword.getDamage();


    Characteristic hero(20);
    cout << "\nСила героя: 20";
    cout << "\nОбщий урон (сила + урон оружия): "
        << hero.GetDamage(sword);

    
    cout << "\n10 + 5 = " << MyMath::Add(10, 5);
    cout << "\n10 - 5 = " << MyMath::Sub(10, 5);
    cout << "\n10 * 5 = " << MyMath::Mult(10, 5);
    cout << "\n10 / 5 = " << MyMath::Div(10, 5);

    
    MyMath::Add(2, 3);
    MyMath::Mult(4, 5);

    cout << "\n\nКоличество вызовов методов MyMath: "
        << MyMath::getCallCount();

    return 0;
}