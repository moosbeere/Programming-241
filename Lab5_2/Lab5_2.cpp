#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>

using namespace std;

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

// Базовый класс оружия
class Weapon {
private:
    string name;
    int damage;
    WeaponType type;

public:
    Weapon() : name("Неизвестно"), damage(0), type(ONEHANDED) {}
    Weapon(string n, int d, WeaponType t) : name(n), damage(d), type(t) {}

    string getName() const { return name; }
    WeaponType getType() const { return type; }

    // 1. Виртуальный метод для получения урона
    virtual int getDamage() const { return damage; }

    // 4. Перегрузка операторов сравнения по урону
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

// Структура игрока
struct Player {
    int id;
    string login;
    string password;

    void printInfo() const {
        cout << "ID: " << id << endl;
        cout << "Логин: " << login << endl;
        cout << "Пароль: " << password << endl;
    }
};

// Дочерний класс магического оружия
class MagicWeapon : public Weapon {
private:
    int additionalDamage;

public:
    MagicWeapon() : Weapon(), additionalDamage(0) {}
    MagicWeapon(string n, int d, WeaponType t, int addD) : Weapon(n, d, t), additionalDamage(addD) {}

    int getAdditionalDamage() const { return additionalDamage; }

    // 2. Переопределяем метод getDamage
    int getDamage() const override { return Weapon::getDamage() + additionalDamage; }
};

int main() {
    // --- Настройка консоли для русского языка ---
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    // --- Тест обычного оружия ---
    Weapon sword("Меч", 50, ONEHANDED);
    cout << "Обычное оружие: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl;
    printWeaponType(sword.getType());

    cout << "---------------------------" << endl;

    // --- Тест магического оружия ---
    MagicWeapon fireSword("Огненный меч", 60, ONEHANDED, 20);
    cout << "Магическое оружие: " << fireSword.getName() << endl;
    cout << "Базовый + доп. урон: " << fireSword.getDamage() << endl;
    printWeaponType(fireSword.getType());

    cout << "---------------------------" << endl;

    // --- Проверка операторов > и < ---
    Weapon axe("Топор", 55, TWOHANDED);
    cout << "Сравниваем оружие по урону:" << endl;
    cout << sword.getName() << " > " << axe.getName() << "? " << (sword > axe ? "Да" : "Нет") << endl;
    cout << fireSword.getName() << " > " << axe.getName() << "? " << (fireSword > axe ? "Да" : "Нет") << endl;
    cout << sword.getName() << " < " << fireSword.getName() << "? " << (sword < fireSword ? "Да" : "Нет") << endl;

    return 0;
}
