#include <iostream>
#include <string>
#include <clocale>

// Тип оружия
enum class WeaponType
{
    OneHanded,
    TwoHanded,
    Bow,
    Crossbow
};

// Базовый класс Weapon
class Weapon
{
public:
    // Конструктор по умолчанию
    Weapon()
        : Weapon("default_weapon_name", 10, 20, WeaponType::OneHanded)
    {
    }

    // Основной конструктор
    Weapon(const std::string& name,
        int damage,
        int weight,
        WeaponType type)
        : m_name(name)
        , m_damage(damage)
        , m_weight(weight)
        , m_type(type)
    {
    }

    // Виртуальный деструктор
    virtual ~Weapon()
    {
        std::printf(
            "(DESTRUCTOR) name: %s, damage: %d, weight: %d\n",
            m_name.c_str(),
            m_damage,
            m_weight
        );
    }

    // Вывод информации об оружии
    void print() const
    {
        std::printf(
            "name: %s, damage: %d, weight: %d\n",
            m_name.c_str(),
            m_damage,
            m_weight
        );
    }

    // Проверка допустимого веса
    bool is_weight_accessible(int maxWeight) const
    {
        return m_weight > maxWeight;
    }

    // Суммирование свойств
    int sum_properties(int weight) const
    {
        return m_weight + weight;
    }

    // Перегрузка
    int sum_properties(const Weapon& weapon) const
    {
        return sum_properties(weapon.m_weight);
    }

    // Сеттеры
    void set_name(const std::string& name) { m_name = name; }
    void set_damage(int damage) { m_damage = damage; }
    void set_weight(int weight) { m_weight = weight; }

    // Геттеры
    const std::string& get_name() const { return m_name; }
    virtual int get_damage() const { return m_damage; }
    int get_weight() const { return m_weight; }
    WeaponType get_type() const { return m_type; }

    // Перегрузка операторов
    bool operator>(const Weapon& rhs) const
    {
        return get_damage() > rhs.get_damage();
    }

    bool operator<(const Weapon& rhs) const
    {
        return get_damage() < rhs.get_damage();
    }

protected:
    std::string m_name;
    int m_damage;
    int m_weight;
    WeaponType m_type;
};

// Структура Player
struct Player
{
    Player(const std::string& login,
        const std::string& password,
        int id)
        : m_login(login)
        , m_password(password)
        , m_id(id)
    {
    }

    void print() const
    {
        std::printf(
            "login: %s, password: %s, id: %d\n",
            m_login.c_str(),
            m_password.c_str(),
            m_id
        );
    }

    std::string m_login;
    std::string m_password;
    int m_id;
};

// Магическое оружие
class MagicWeapon : public Weapon
{
public:
    // Конструктор по умолчанию
    MagicWeapon()
        : Weapon("magic_weapon", 10, 20, WeaponType::OneHanded)
        , m_additional_damage(5)
    {
    }

    // Основной конструктор
    MagicWeapon(const std::string& name,
        int baseDamage,
        int additionalDamage,
        int weight,
        WeaponType type)
        : Weapon(name, baseDamage, weight, type)
        , m_additional_damage(additionalDamage)
    {
    }

    // Переопределение урона
    int get_damage() const override
    {
        return m_damage + m_additional_damage;
    }

    int get_additional_damage() const
    {
        return m_additional_damage;
    }

private:
    int m_additional_damage;
};

// Задание
static void runTask()
{
    Weapon weapon("weapon_crossbow", 10, 5, WeaponType::Crossbow);
    MagicWeapon magicWeapon("magic_weapon", 10, 10, 5, WeaponType::Crossbow);
    Player player("Chertik", "Nolik00", 3321452);

    // Проверка типа оружия
    switch (weapon.get_type())
    {
    case WeaponType::OneHanded:
        std::cout << "Одноручное оружие\n";
        break;
    case WeaponType::TwoHanded:
        std::cout << "Двуручное оружие\n";
        break;
    case WeaponType::Bow:
        std::cout << "Лук\n";
        break;
    case WeaponType::Crossbow:
        std::cout << "Арбалет\n";
        break;
    }

    weapon.print();
    player.print();

    std::cout
        << "magic weapon damage: "
        << magicWeapon.get_damage()
        << std::endl;

    std::cout
        << "magic weapon > weapon: "
        << (magicWeapon > weapon)
        << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    runTask();
    return 0;
}
