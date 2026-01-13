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

class Weapon {
private:
    string name;
    int damage;
    WeaponType type;

public:
    Weapon() : name("Неизвестно"), damage(0), type(ONEHANDED) {}
    Weapon(string n, int d, WeaponType t) : name(n), damage(d), type(t) {}

    string getName() const { return name; }
    int getDamage() const { return damage; }
    WeaponType getType() const { return type; }
};

void printWeaponType(WeaponType type) {
    if (type == ONEHANDED) cout << "Тип оружия: Одноручное" << endl;
    else if (type == TWOHANDED) cout << "Тип оружия: Двуручное" << endl;
    else if (type == BOW) cout << "Тип оружия: Лук" << endl;
    else if (type == CROSSBOW) cout << "Тип оружия: Арбалет" << endl;
}

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

class MagicWeapon : public Weapon {
private:
    int additionalDamage;

public:
    MagicWeapon() : Weapon(), additionalDamage(0) {}
    MagicWeapon(string n, int d, WeaponType t, int addD) : Weapon(n, d, t), additionalDamage(addD) {}

    int getAdditionalDamage() const { return additionalDamage; }
};

int main() {
    // --- Настройка консоли для русского языка ---
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    Weapon sword("Меч", 50, ONEHANDED);
    cout << "Оружие: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl;
    printWeaponType(sword.getType());


    Player player1 = { 1, "Герой", "12345" };
    player1.printInfo();


    MagicWeapon fireSword("Огненный меч", 60, ONEHANDED, 20);
    cout << "Магическое оружие: " << fireSword.getName() << endl;
    cout << "Урон: " << fireSword.getDamage() << endl;
    cout << "Доп. урон: " << fireSword.getAdditionalDamage() << endl;
    printWeaponType(fireSword.getType());

    return 0;
}
