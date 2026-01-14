#pragma once
#ifndef DISPOSABLEWEAPON_H
#define DISPOSABLEWEAPON_H

#include "Weapon.h"

// Одноразовое оружие
class DisposableWeapon : public Weapon {
private:
    bool used; // true — если оружие уже было использовано

public:
    // Конструктор по умолчанию
    DisposableWeapon();

    // Конструктор с параметрами
    DisposableWeapon(const std::string& n, int d, WeaponType t);

    // Реализация Attack()
    void Attack() override;
};

#endif
