#include "lab4.4.3.h"
#include "lab4.4.4.h"
#include <iostream>

int main() {
    Weapon sword("Крутой меч", 25, 5.8f);
    sword.display();

    std::cout << "Название: " << sword.getName() << std::endl;
    std::cout << "Урон: " << sword.getDamage() << std::endl;
    std::cout << "Вес: " << sword.getWeight() << std::endl;

    sword.setDamage(30);
    std::cout << "Новый урон: " << sword.getDamage() << std::endl;

    Characteristic heroStrength(15);

    std::cout << "Урон с мечом: " << heroStrength.getDamage(sword) << std::endl;

    Weapon dagger("Кинжал", 8, 1.2f);
    std::cout << "Урон с кинжалом: " << heroStrength.getDamage(dagger) << std::endl;

    std::cout << "MyMath::Add(10, 5) = " << MyMath::Add(10, 5) << std::endl;
    std::cout << "MyMath::Sub(10, 5) = " << MyMath::Sub(10, 5) << std::endl;
    std::cout << "MyMath::Mult(10, 5) = " << MyMath::Mult(10, 5) << std::endl;
    std::cout << "MyMath::Div(10, 5) = " << MyMath::Div(10, 5) << std::endl;

    std::cout << "Количество вызовов методов MyMath: " << MyMath::getCallCount() << std::endl;

    return 0;
}
