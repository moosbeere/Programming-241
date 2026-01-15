#include "Lab4.h"
#include <iostream>


// Задание 1

static void runTask1()
{
    // Объект, созданный конструктором по умолчанию
    Weapon defaultWeapon;

    // Объект, созданный пользовательским конструктором
    Weapon crowbar("crowbar", 5, 12);

    // Вывод информации об оружии
    defaultWeapon.print();
    crowbar.print();
}


// Задание 2
static void runTask2()
{
    Weapon defaultWeapon;

    // Динамическое создание объекта
    Weapon* crowbar = new Weapon("crowbar", 5, 12);

    // Проверка доступности веса
    std::cout
        << "1. weight check: "
        << defaultWeapon.is_weight_accessable(30)
        << std::endl;

    std::cout
        << "2. weight check: "
        << crowbar->is_weight_accessable(10)
        << std::endl;

    // Суммирование характеристик
    std::cout
        << "sum weights: "
        << defaultWeapon.sum_properties(crowbar)
        << std::endl;

    // Освобождение памяти
    delete crowbar;
}


// Задание 4

static void runTask4()
{
    Weapon weapon;

    // Получение значений через геттеры
    std::cout << "get_name: " << weapon.get_name() << std::endl;
    std::cout << "get_damage: " << weapon.get_damage() << std::endl;
    std::cout << "get_weight: " << weapon.get_weight() << std::endl;

    // Изменение значений через сеттеры
    weapon.set_name("not_default_weapon");
    weapon.set_damage(344);
    weapon.set_weight(132);

    // Повторный вывод изменённых данных
    std::cout << "get_name: " << weapon.get_name() << std::endl;
    std::cout << "get_damage: " << weapon.get_damage() << std::endl;
    std::cout << "get_weight: " << weapon.get_weight() << std::endl;

    // Работа с классом Characteristic
    Characteristic characteristic(90);
    std::cout
        << "characteristic: "
        << characteristic.get_damage(&weapon)
        << std::endl;

    // Статические методы класса MyMath
    std::cout << "add: " << MyMath::add(12, 20) << std::endl;
    std::cout << "sub: " << MyMath::sub(12, 20) << std::endl;
    std::cout << "mul: " << MyMath::mul(12, 20) << std::endl;
    std::cout << "div: " << MyMath::div(20, 2) << std::endl;

    // Счётчик вызовов
    std::cout
        << "calls: "
        << MyMath::m_calls_counter
        << std::endl;
}

int main()
{
    runTask4();
    return 0;
}
