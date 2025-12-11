#include <iostream>
#include "lab4.h"

int main() {
    std::cout <<  std::endl;
    orujie crook(40, "crook", 2);
    orujie wrist;

    std::cout << std::endl;
    std::cout << "Оружие 1:" << std::endl;
    std::cout << "Вес: " << crook.getWeight() << std::endl;
    std::cout << "Название: " << crook.getName() << std::endl;
    std::cout << "Урон: " << crook.getDamage() << std::endl;

    std::cout << "\nОружие 2:" << std::endl;
    std::cout << "Вес: " << wrist.getWeight() << std::endl;
    std::cout << "Название: " << wrist.getName() << std::endl;
    std::cout << "Урон: " << wrist.getDamage() << std::endl;

    std::cout <<  std::endl;
    orujie staticWeapon(25, "Меч", 15);
    staticWeapon.printInfo();

    std::cout <<  std::endl;
    std::cout << "Можно поднять вес 20? "<< (staticWeapon.checkWeight(20) ? "Да" : "Нет") << std::endl;

    std::cout << std::endl;
    orujie* dynamicWeapon = new orujie(30, "Топор", 25);
    dynamicWeapon->printInfo();

    std::cout << std::endl;
    std::cout << "2.6 Добавьте метод, принимающий объект оружия, и возвращающий суммарный вес текущего объекта и переданного: " << crook.sumWeight(wrist) << std::endl;
    std::cout << "2.7 возврат суммы веса текущего объекта и переданного веса.: " << crook.sumWeight(5.0f) << std::endl;
    std::cout << "2.8 Перепишите функцию, принимающую объект оружия так, чтобы она использовала созданную перегрузку.: " << crook.sumWeightWithOverload(wrist) << std::endl;

    
    delete dynamicWeapon;

    std::cout <<  std::endl;
    orujie sword(25, "Меч", 5);
    std::cout << "GET: " << sword.getDamage() << std::endl;
    sword.setDamage(35.5f);
    std::cout << sword.getDamage() << std::endl;
    sword.setDamage(-10);

    std::cout << std::endl;
    orujie axe(40, "Топор", 8);
    Characteristic hero(15.5f);
    std::cout << "Сила: " << hero.getStrength() << std::endl;
    std::cout << "Урон оружия: " << axe.getDamage() << std::endl;
    std::cout << "Общий урон: " << hero.GetDamage(axe) << std::endl;

    std::cout <<  std::endl;
    float a = 10.5f;
    float b = 2.5f;
    std::cout << "Add: " << MyMath::Add(a, b) << std::endl;
    std::cout << "Sub: " << MyMath::Sub(a, b) << std::endl;
    std::cout << "Mult: " << MyMath::Mult(a, b) << std::endl;
    std::cout << "Div: " << MyMath::Div(a, b) << std::endl;
    MyMath::Add(5, 3);
    MyMath::Mult(7, 2);

    std::cout << " Счетчик вызовов" << std::endl;
    std::cout << "Всего вызовов: " << MyMath::getMethodCallCount() << std::endl;

    std::cout << "Завершение программы" << std::endl;

    return 0;
}
