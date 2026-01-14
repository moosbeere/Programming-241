#pragma once
#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H

#include "Weapon.h"

// Дочерний класс для магического оружия
class MagicWeapon : public Weapon {
private:
    int additionalDamage; // Дополнительный магический урон

public:
    // Конструктор по умолчанию
    MagicWeapon();

    // Конструктор с параметрами
    MagicWeapon(const std::string& n, int d, WeaponType t, int addD);

    // Геттер дополнительного урона
    int getAdditionalDamage() const;

    // Переопределение метода getDamage()
    // Возвращает сумму базового и магического урона
    int getDamage() const override;

    // Реализация чисто виртуальной функции Attack
    void Attack() override;
};

#endif

