#include <iostream>
#include <string>
#include "weapon.h"

using namespace std;

// 4. Структура игрока
struct Player
{
    int         id;       // уникальный идентификатор
    std::string login;    // логин
    std::string password; // пароль

    // 5. Функция вывода всех данных
    void print() const
    {
        cout << "Игрок #" << id
             << ", логин: " << login
             << ", пароль: " << password << endl;
    }
};

// 7. Дочерний класс для магического оружия
class MagicWeapon : public Weapon
{
private:
    int extraDamage; // 8. дополнительный урон

public:
    // 9. Конструктор без параметров
    MagicWeapon()
        : Weapon()      // базовый конструктор оружия по умолчанию
        , extraDamage(10)
    {
    }

    // 9. Конструктор с параметрами
    MagicWeapon(const std::string& name,
                int                damage,
                float              weight,
                WeaponType         type,
                int                extra)
        : Weapon(name, damage, weight, type)
        , extraDamage(extra)
    {
    }

    // 10. GET-метод для дополнительного урона
    int getExtraDamage() const
    {
        return extraDamage;
    }

    // 2. Переопределённый метод урона: базовый + дополнительный
    int getDamage() const override
    {
        return Weapon::getDamage() + extraDamage;
    }

    // Дополнительный метод для вывода полной информации
    void printMagicInfo() const
    {
        cout << "Магическое оружие:" << endl;
        print(); // метод базового класса
        cout << "Дополнительный магический урон: " << extraDamage << endl;
    }

    // 2. Реализация виртуальной функции атаки
    void Attack() override
    {
        cout << "Атакуем магическим оружием" << endl;
    }
};

// 5. Класс одноразового оружия
class DisposableWeapon : public Weapon
{
private:
    bool used; // 6. флаг использования

public:
    DisposableWeapon(const std::string& name,
                     int                damage,
                     float              weight,
                     WeaponType         type)
        : Weapon(name, damage, weight, type)
        , used(false)
    {
    }

    // 7. Поведение при атаке
    void Attack() override
    {
        if (used)
        {
            cout << "Оружие уже было использовано" << endl;
        }
        else
        {
            cout << "Атакуем одноразовым оружием" << endl;
            used = true;
        }
    }
};

// 9. Шаблонный класс для хранения оружия в левой и правой руке
template <typename L, typename R>
class DualWield
{
private:
    L leftHand;
    R rightHand;

public:
    DualWield(const L& left, const R& right)
        : leftHand(left)
        , rightHand(right)
    {
    }

    const L& getLeft() const  { return leftHand; }
    const R& getRight() const { return rightHand; }

    void setLeft(const L& left)   { leftHand = left; }
    void setRight(const R& right) { rightHand = right; }
};

int main()
{
    // 3. Попробовать создать экземпляр Weapon НЕЛЬЗЯ:
    // Weapon w("test", 10, 1.0f, WeaponType::ONEHANDED); // Ошибка компилятора: абстрактный класс

    // 2–3 (раньше 2–3). Создаём оружие с типом и выводим его тип через if
    MagicWeapon dagger("Кинжал", 25, 1.2f, WeaponType::ONEHANDED, 5);

    cout << "Оружие dagger:" << endl;
    dagger.print();

    cout << "Тип оружия (через if): ";
    WeaponType t = dagger.getType();
    if (t == WeaponType::ONEHANDED)
        cout << "Одноручное оружие";
    else if (t == WeaponType::TWOHANDED)
        cout << "Двуручное оружие";
    else if (t == WeaponType::BOW)
        cout << "Лук";
    else if (t == WeaponType::CROSSBOW)
        cout << "Арбалет";
    cout << endl;

    // 6. Тестируем структуру Player
    Player p;
    p.id       = 1;
    p.login    = "Hero123";
    p.password = "qwerty";

    cout << "\nИнформация об игроке:" << endl;
    p.print();

    // 11. Тестируем класс MagicWeapon
    cout << "\nТест магического оружия:" << endl;

    MagicWeapon defaultMagic; // конструктор без параметров
    defaultMagic.printMagicInfo();

    cout << endl;

    MagicWeapon fireStaff("Огненный посох", 40, 3.0f, WeaponType::TWOHANDED, 25);
    fireStaff.printMagicInfo();

    // 3. Проверяем, что урон магического оружия = базовый + дополнительный
    int baseDamage   = 40;
    int extraDamage  = fireStaff.getExtraDamage();
    int virtualDmg   = fireStaff.getDamage(); // должен быть baseDamage + extraDamage

    cout << "Базовый урон: " << baseDamage << endl;
    cout << "Дополнительный магический урон: " << extraDamage << endl;
    cout << "Урон из виртуального метода getDamage(): " << virtualDmg << endl;

    // 5. Проверяем операторы > и <
    MagicWeapon sword("Меч", 35, 3.0f, WeaponType::ONEHANDED, 0);
    MagicWeapon bow("Охотничий лук", 20, 2.0f, WeaponType::BOW, 0);

    cout << "\nСравнение обычного оружия:" << endl;
    cout << "Меч (" << sword.getDamage() << ") "
         << (sword > bow ? "сильнее" : "не сильнее")
         << " лука (" << bow.getDamage() << ")" << endl;

    cout << "\nСравнение обычного и магического оружия:" << endl;
    cout << "Меч (" << sword.getDamage() << ") "
         << (sword < fireStaff ? "слабее" : "не слабее")
         << " огненного посоха (" << fireStaff.getDamage() << ")" << endl;

    // 4. Вызываем Attack у магического оружия
    cout << "\nАтака магическим оружием:" << endl;
    fireStaff.Attack();

    // 8. Тест одноразового оружия
    cout << "\nТест одноразового оружия:" << endl;
    DisposableWeapon bomb("Бомба", 100, 5.0f, WeaponType::TWOHANDED);
    bomb.Attack(); // первый раз
    bomb.Attack(); // второй раз

    // 11. Проверка шаблона DualWield
    cout << "\nТест шаблонного класса DualWield:" << endl;

    // Вариант 1: реальные объекты оружия
    DualWield<MagicWeapon, DisposableWeapon> hands1(fireStaff, bomb);
    cout << "Левая рука держит: ";  hands1.getLeft().printMagicInfo();
    cout << "Правая рука держит: "; const_cast<DisposableWeapon&>(hands1.getRight()).Attack(); // просто вызов атаки

    // Вариант 2: идентификаторы оружия (ints)
    DualWield<int, int> weaponIds(101, 202);
    cout << "ID оружия в левой руке: " << weaponIds.getLeft() << endl;
    cout << "ID оружия в правой руке: " << weaponIds.getRight() << endl;

    return 0;
}

