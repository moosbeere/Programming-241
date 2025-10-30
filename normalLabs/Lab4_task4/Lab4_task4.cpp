#include <iostream>
#include "Weapon.h"
#include "Characteristic.h"
#include "MyMath.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 25, 2);
    sword.printInfo();

    Weapon axe("Топор", 15, 7);
    axe.printInfo();

    cout << "Вес " << sword.getName() << " + " << axe.getName() << " = " << sword.newWeapon(axe) << endl;

    Weapon* bow = new Weapon("Лук", 10, 0.1);
    bow->printInfo();
    delete bow;
    cout << endl;

    if (sword.checkWeight(3)) {
        cout << "Вес оружия: " << sword.getName() << " < 3" << endl;
    }
    else {
        cout << "Вес оружия: " << sword.getName() << " >= 3" << endl;
    }

    cout << "Перегрузка функцией принимающей просто вес = " << sword.newWeapon(10) << endl;

    cout << endl << "Проверка set запроса до:\nУрон меча = " << sword.getDamage() << endl;
    sword.setDamage(999);
    cout << "После:\nУрон меча = " << sword.getDamage() << endl;
    Characteristic hero(10);
    cout << "Урон наносимый героем с помощью топора = " << hero.GetDamage(axe) << endl;
    MyMath opers;
    cout << "Сложение с помощью MyMath: 2, 3 = " << opers.Add(2, 3) << endl;
    cout << "Вычитание с помощью MyMath: 2, 3 = " << opers.Sub(2, 3) << endl;
    cout << "Умножение с помощью MyMath: 2, 3 = " << opers.Mult(2, 3) << endl;
    cout << "Деление с помощью MyMath: 2, 3 = " << opers.Div(2, 3) << endl;
    cout << "Значение статической переменной после операций = " << opers.getStaticCount() << endl;
}