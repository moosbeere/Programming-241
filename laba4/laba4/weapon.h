#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace ::std;

// 1. Перечисление типов оружия
enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class weapon
{
private:
    string name;
    int weight;
    int damage;
    WeaponType type;  // 2. Добавлена приватная переменная типа перечисления

public:
    weapon(string Wname, int Wweight, int Wdamage, WeaponType Wtype = ONEHANDED);
    weapon();
    virtual ~weapon();  // Виртуальный деструктор

    string getName() const;
    WeaponType getType() const;  // 2. GET-метод для типа
    void print();

    int weight_possible() const;
    int getweight() const;
    virtual int getdamage() const;  // 13. Виртуальный метод
    void setdamage(int newdamage);
    void setType(WeaponType newType);  // Для изменения типа

    int suma_weight(const weapon& oweapon) const;
    int suma_weight2(int oweight) const;
    int suma_weight3(const weapon& oweapon) const;

    // 16. Перегрузка операторов сравнения
    bool operator>(const weapon& other) const;
    bool operator<(const weapon& other) const;

    friend class Characteristic;
};

// 4. Структура игрока
struct Player {
    int id;
    string login;
    string password;

    // 5. Функция для вывода данных
    void printPlayer() const;
};

// 7. Класс магического оружия
class MagicWeapon : public weapon {
private:
    int additionalDamage;  // 8. Дополнительный урон

public:
    // 9. Конструкторы
    MagicWeapon(string Wname, int Wweight, int Wdamage, int addDamage, WeaponType Wtype = ONEHANDED);
    MagicWeapon();  // Конструктор без параметров

    // 10. GET-метод для дополнительного урона
    int getAdditionalDamage() const;

    // 14. Переопределение метода getdamage
    virtual int getdamage() const override;
};

class Characteristic
{
private:
    int strength;

public:
    Characteristic(int str);
    int getStrength() const;
    int GetDamage(const weapon& w) const;
};

class MyMath
{
private:
    static int count;

public:
    static int Add(int a, int b);
    static int Sub(int a, int b);
    static int Mult(int a, int b);
    static double Div(int a, int b);
    static int getcount();
};

// Функция для получения текстового представления типа оружия
string getWeaponTypeName(WeaponType type);

#endif