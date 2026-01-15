#ifndef LAB_4_H
#define LAB_4_H

#include <iostream>
#include <string>


// Класс Weapon

class Weapon
{
    // Класс Characteristic имеет доступ к private полям Weapon
    friend class Characteristic;

public:
    // Конструктор по умолчанию
    Weapon()
        : Weapon("default_weapon_name", 10, 20)
    {
    }

    // Пользовательский конструктор
    Weapon(const std::string& name, int damage, int weight)
        : m_name(name)
        , m_damage(damage)
        , m_weight(weight)
    {
    }

    // Деструктор (для демонстрации момента уничтожения объекта)
    ~Weapon()
    {
        std::printf(
            "(DESTRUCTION) name: %s, damage: %d, weight: %d\n",
            m_name.c_str(),
            m_damage,
            m_weight
        );
    }

    // Вывод информации об оружии
    void print()
    {
        std::printf(
            "name: %s, damage: %d, weight: %d\n",
            m_name.c_str(),
            m_damage,
            m_weight
        );
    }

    // Проверка: превышает ли вес допустимый
    bool is_weight_accessable(int maxWeight)
    {
        return m_weight > maxWeight;
    }

    // Суммирование веса с числом
    int sum_properties(int weight)
    {
        return m_weight + weight;
    }

    // Суммирование веса с другим объектом Weapon
    int sum_properties(Weapon* weapon)
    {
        return sum_properties(weapon->m_weight);
    }

    // Сеттеры
    void set_name(const std::string& name) { m_name = name; }
    void set_damage(int damage) { m_damage = damage; }
    void set_weight(int weight) { m_weight = weight; }

    // Геттеры
    const std::string& get_name() { return m_name; }
    int get_damage() { return m_damage; }
    int get_weight() { return m_weight; }

private:
    std::string m_name; // название оружия
    int m_damage;       // урон
    int m_weight;       // вес
};

// Класс Characteristic
class Characteristic
{
public:
    explicit Characteristic(int strength) // Только явный вызов конструктора
        : m_strength(strength)
    {
    }

    // Получение итогового урона с учётом силы персонажа
    int get_damage(Weapon* weapon)
    {
        return m_strength + weapon->m_damage;
    }

private:
    int m_strength; // сила персонажа
};

// Класс MyMath static
class MyMath
{
public:
    static int add(int a, int b)
    {
        ++m_calls_counter;
        return a + b;
    }

    static int sub(int a, int b)
    {
        ++m_calls_counter;
        return a - b;
    }

    static int mul(int a, int b)
    {
        ++m_calls_counter;
        return a * b;
    }

    static int div(int a, int b)
    {
        ++m_calls_counter;
        return a / b;
    }

    // Счётчик количества вызовов всех методов
    static inline int m_calls_counter = 0;
};

#endif // LAB_4_H

