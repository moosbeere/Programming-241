#include "weapon.h"
#include <iostream>

//  Конструктор, принимающий 4 параметра (включая тип оружия)
Weapon::Weapon(const std::string& weaponName,
               int                weaponDamage,
               float              weaponWeight,
               WeaponType         weaponType)
    : name(weaponName)
    , damage(weaponDamage)
    , weight(weaponWeight)
    , type(weaponType)
{
}

//  Конструктор без параметров, вызывающий основной конструктор
Weapon::Weapon()
    : Weapon("Безымянное оружие", 10, 1.0f, WeaponType::ONEHANDED)
{
}

//  Деструктор, выводящий данные оружия и сообщение об удалении
Weapon::~Weapon()
{
    std::cout << "Деструктор: оружие удаляется -> ";
    print();
}

//  Метод для вывода информации об оружии
void Weapon::print() const
{
    std::cout << "Название: " << name
              << ", Урон: " << damage
              << ", Вес: " << weight << " кг"
              << ", Тип: ";

    switch (type)
    {
    case WeaponType::ONEHANDED:
        std::cout << "Одноручное";
        break;
    case WeaponType::TWOHANDED:
        std::cout << "Двуручное";
        break;
    case WeaponType::BOW:
        std::cout << "Лук";
        break;
    case WeaponType::CROSSBOW:
        std::cout << "Арбалет";
        break;
    }

    std::cout << std::endl;
}

//  Метод проверки по максимальному допустимому весу.
//  Если maxWeight < weight, возвращаем true (оружие слишком тяжёлое),
//  иначе false.
bool Weapon::isTooHeavy(float maxWeight) const
{
    return maxWeight < weight;
}

//  Метод, принимающий объект оружия и возвращающий суммарный вес
float Weapon::totalWeight(const Weapon& other) const
{
    // Используем перегрузку, принимающую просто вес
    return totalWeight(other.weight);
}

//  Перегрузка: метод, принимающий просто вес
float Weapon::totalWeight(float extraWeight) const
{
    return weight + extraWeight;
}

//  GET-методы
const std::string& Weapon::getName() const
{
    return name;
}

int Weapon::getDamage() const
{
    return damage;
}

float Weapon::getWeight() const
{
    return weight;
}

WeaponType Weapon::getType() const
{
    return type;
}

//  SET-метод для урона
void Weapon::setDamage(int newDamage)
{
    damage = newDamage;
}

// 4. Операторы сравнения по урону, используют виртуальный getDamage()
bool operator>(const Weapon& lhs, const Weapon& rhs)
{
    return lhs.getDamage() > rhs.getDamage();
}

bool operator<(const Weapon& lhs, const Weapon& rhs)
{
    return lhs.getDamage() < rhs.getDamage();
}



