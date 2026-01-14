#ifndef WEAPON_H
#define WEAPON_H

#include <string> // Для использования std::string

// Перечисление типов оружия
enum WeaponType {
    ONEHANDED,   // Одноручное
    TWOHANDED,   // Двуручное
    BOW,         // Лук
    CROSSBOW     // Арбалет
};

// Абстрактный базовый класс Weapon
class Weapon {
protected:
    std::string name;  // Имя оружия
    int damage;        // Базовый урон
    WeaponType type;   // Тип оружия

public:
    // Конструктор по умолчанию
    Weapon();

    // Конструктор с параметрами
    Weapon(const std::string& n, int d, WeaponType t);

    // Геттеры для доступа к полям
    std::string getName() const;
    WeaponType getType() const;

    // Виртуальная функция получения урона
    // Можно переопределять в дочерних классах
    virtual int getDamage() const;

    // Чисто виртуальная функция — делает класс абстрактным
    // Любой наследник обязан реализовать Attack()
    virtual void Attack() = 0;

    // Перегрузка операторов сравнения по урону
    bool operator>(const Weapon& other) const;
    bool operator<(const Weapon& other) const;

    // Виртуальный деструктор, чтобы корректно удалялись дочерние объекты
    virtual ~Weapon() {}
};

#endif
