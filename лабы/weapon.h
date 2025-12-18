#pragma once

#include <string>

// 1. Перечисление типов оружия
enum class WeaponType
{
    ONEHANDED, // одноручное
    TWOHANDED, // двуручное
    BOW,       // лук
    CROSSBOW   // арбалет
};

class Characteristic; // предварительное объявление для friendship

class Weapon
{
private:
    std::string name;      // название оружия
    int         damage;    // наносимый урон
    float       weight;    // вес оружия (в килограммах, условно)
    WeaponType  type;      // 2. тип оружия

    // 6. Дружественный класс, который может обращаться к приватным полям
    friend class Characteristic;

public:
    // Конструктор, принимающий 4 параметра (включая тип оружия)
    Weapon(const std::string& weaponName,
           int                weaponDamage,
           float              weaponWeight,
           WeaponType         weaponType);

    // Конструктор без параметров (значения по умолчанию)
    Weapon();

    // Деструктор (виртуальный, т.к. класс абстрактный и есть наследники)
    virtual ~Weapon();

    // GET-методы для всех полей
    const std::string& getName() const;
    // 1. Виртуальный метод, возвращающий урон от оружия
    virtual int  getDamage() const;
    float       getWeight() const;
    WeaponType  getType()   const; // 2. GET для типа оружия

    // SET-метод только для наносимого урона
    void setDamage(int newDamage);

    // Метод для вывода информации об оружии
    void print() const;

    // 1. Чисто виртуальная функция атаки — делает класс абстрактным
    virtual void Attack() = 0;

    // Метод проверки по максимальному допустимому весу.
    // Если maxWeight < weight, возвращаем true (оружие слишком тяжёлое),
    // иначе false.
    bool isTooHeavy(float maxWeight) const;

    // Метод, принимающий объект оружия и возвращающий суммарный вес
    float totalWeight(const Weapon& other) const;

    // Перегрузка: метод, принимающий просто вес
    float totalWeight(float extraWeight) const;
};

// 4. Операторы сравнения по урону (используют виртуальный getDamage)
bool operator>(const Weapon& lhs, const Weapon& rhs);
bool operator<(const Weapon& lhs, const Weapon& rhs);




