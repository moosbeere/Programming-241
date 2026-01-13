#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>

using namespace std;

// Перечисление типов оружия
enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

// 1. Абстрактный класс оружия
class Weapon {
protected:
    string name;
    int damage;
    WeaponType type;

public:
    Weapon() : name("Неизвестно"), damage(0), type(ONEHANDED) {}
    Weapon(string n, int d, WeaponType t) : name(n), damage(d), type(t) {}

    string getName() const { return name; }
    WeaponType getType() const { return type; }

    virtual int getDamage() const { return damage; }

    // 1. Чисто виртуальная функция Attack
    virtual void Attack() = 0;

    // Перегрузка операторов сравнения
    bool operator>(const Weapon& other) const { return getDamage() > other.getDamage(); }
    bool operator<(const Weapon& other) const { return getDamage() < other.getDamage(); }
};

// Функция для вывода типа оружия
void printWeaponType(WeaponType type) {
    if (type == ONEHANDED) cout << "Тип оружия: Одноручное" << endl;
    else if (type == TWOHANDED) cout << "Тип оружия: Двуручное" << endl;
    else if (type == BOW) cout << "Тип оружия: Лук" << endl;
    else if (type == CROSSBOW) cout << "Тип оружия: Арбалет" << endl;
}

// Дочерний класс магического оружия
class MagicWeapon : public Weapon {
private:
    int additionalDamage;

public:
    MagicWeapon() : Weapon(), additionalDamage(0) {}
    MagicWeapon(string n, int d, WeaponType t, int addD) : Weapon(n, d, t), additionalDamage(addD) {}

    int getAdditionalDamage() const { return additionalDamage; }

    int getDamage() const override { return Weapon::getDamage() + additionalDamage; }

    // 2. Реализация метода Attack
    void Attack() override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

// Дочерний класс одноразового оружия
class DisposableWeapon : public Weapon {
private:
    bool used;

public:
    DisposableWeapon() : Weapon(), used(false) {}
    DisposableWeapon(string n, int d, WeaponType t) : Weapon(n, d, t), used(false) {}

    void Attack() override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
        } else {
            cout << "Атакуем одноразовым оружием" << endl;
            used = true;
        }
    }
};

// 9. Шаблон класса для левой и правой руки
template <typename Left, typename Right>
class Hands {
private:
    Left leftHand;
    Right rightHand;

public:
    Hands(Left l, Right r) : leftHand(l), rightHand(r) {}

    void setLeft(Left l) { leftHand = l; }
    void setRight(Right r) { rightHand = r; }

    Left getLeft() const { return leftHand; }
    Right getRight() const { return rightHand; }
};

int main() {
    //  Настройка консоли для русского языка 
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    //  Проверка абстрактного класса 
    // Weapon w; // <- Это не скомпилируется, как и должно быть

    //  Магическое оружие 
    MagicWeapon fireSword("Огненный меч", 60, ONEHANDED, 20);
    cout << "Магическое оружие: " << fireSword.getName() << endl;
    cout << "Урон (баз + доп): " << fireSword.getDamage() << endl;
    fireSword.Attack();

    cout << " " << endl;

    //  Одноразовое оружие 
    DisposableWeapon bomb("Бомба", 100, ONEHANDED);
    bomb.Attack(); // первый раз
    bomb.Attack(); // второй раз

    cout << " " << endl;

    //  Шаблонный класс Hands 
    Hands<MagicWeapon, DisposableWeapon> myHands(fireSword, bomb);
    cout << "В левой руке: " << myHands.getLeft().getName() << endl;
    cout << "В правой руке: " << myHands.getRight().getName() << endl;

    // Можно заменить оружие
    DisposableWeapon knife("Нож", 30, ONEHANDED);
    myHands.setRight(knife);
    cout << "После замены, в правой руке: " << myHands.getRight().getName() << endl;

    // Пример с простым типом
    Hands<int, int> numbers(10, 20);
    cout << "Левая рука (int): " << numbers.getLeft() << ", правая рука (int): " << numbers.getRight() << endl;

    return 0;
}
