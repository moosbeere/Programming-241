#include <iostream>
#include <string>
#include <clocale>

// Тип оружия
enum class WeaponType
{
    OneHanded,
    TwoHanded,
    Bow,
    Firearm
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

    // Чисто виртуальный метод (делает класс абстрактным)
    virtual void attack() = 0;

    // Проверка допустимого веса
    bool is_weight_accessable(int maxWeight) const
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

// Магическое оружие
class MagicWeapon final : public Weapon
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

    // Переопределение атаки
    void attack() override
    {
        std::cout << "Атакуем магическим оружием\n";
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

// Одноручное одноразовое оружие
class OneHandedWeapon : public Weapon
{
public:
    OneHandedWeapon()
        : Weapon("onehanded_weapon", 8, 5, WeaponType::OneHanded)
        , m_is_used(false)
    {
    }

    void attack() override
    {
        if (!m_is_used)
        {
            std::cout << "Атакуем одноразовым оружием\n";
            m_is_used = true;
        }
        else
        {
            std::cout << "Оружие уже было использовано\n";
        }
    }

private:
    bool m_is_used;
};

// Двуручное оружие (шаблон)
template <typename Left, typename Right>
class TwoHandedWeapon : public Weapon
{
public:
    TwoHandedWeapon(WeaponType left, WeaponType right)
        : Weapon("twohanded_weapon", 15, 12, WeaponType::TwoHanded)
        , m_left(left)
        , m_right(right)
    {
    }

    void attack() override
    {
        std::cout << "Атакуем двуручным оружием\n";
    }

    void set_left_weapon(WeaponType left) { m_left = left; }
    void set_right_weapon(WeaponType right) { m_right = right; }

    WeaponType get_left_weapon() const { return m_left; }
    WeaponType get_right_weapon() const { return m_right; }

private:
    WeaponType m_left;
    WeaponType m_right;
};

// Задание
static void runTask()
{
    MagicWeapon magicWeapon;
    OneHandedWeapon oneHandedWeapon;

    magicWeapon.attack();

    oneHandedWeapon.attack();
    oneHandedWeapon.attack();

    TwoHandedWeapon<int, int> twoHandedWeapon(
        WeaponType::Bow,
        WeaponType::Crossbow
    );

    std::cout
        << "left hand: " << static_cast<int>(twoHandedWeapon.get_left_weapon())
        << " right hand: " << static_cast<int>(twoHandedWeapon.get_right_weapon())
        << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    runTask();
    return 0;
}
