#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>

class Characteristic; // Предварительное объявление

class Weapon {
private:
    std::string name;
    int damage;
    double weight;

public:
    // Конструктор с параметрами
    Weapon(const std::string& n, int d, double w);

    // Конструктор без параметров
    Weapon();

    // Деструктор
    ~Weapon();

    // Методы вывода данных
    void print() const;

    // Методы для проверки веса
    bool isTooHeavy(double maxWeight) const;
    double totalWeight(const Weapon& other) const;
    double totalWeight(double w) const;

    // GET-методы
    std::string getName() const { return name; }
    int getDamage() const { return damage; }
    double getWeight() const { return weight; }

    // SET-метод для урона
    void setDamage(int d) { damage = d; }

    // Делаем класс Characteristic дружественным
    friend class Characteristic;
};

class Characteristic {
private:
    int strength;

public:
    // Конструктор
    Characteristic(int s) : strength(s) {}

    // Метод GetDamage
    int GetDamage(const Weapon& w) const {
        return strength + w.damage;
    }
};

class MyMath {
public:
    static int callCount; // количество вызовов методов

    static int Add(int a, int b) { callCount++; return a + b; }
    static int Sub(int a, int b) { callCount++; return a - b; }
    static int Mult(int a, int b) { callCount++; return a * b; }
    static double Div(double a, double b) { callCount++; return a / b; }
};

#endif // HEADER_H
