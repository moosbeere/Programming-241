#include <iostream>
#include <string>
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
    Weapon() {
        name = "Безымянное оружие";
        damage = 0;
        type = ONEHANDED;
    }

    Weapon(string n, int d, WeaponType t) {
        name = n;
        damage = d;
        type = t;
    }

    string getName() {
        return name;
    }

    int getDamage() {
        return damage;
    }

    WeaponType getType() {
        return type;
    }
};

struct Player {
    int id;
    string login;
    string password;

    void printInfo() {
        cout << "ID: " << id << endl;
        cout << "Login: " << login << endl;
        cout << "Password: " << password << endl;
    }
};

class MagicWeapon : public Weapon {
private:
    int bonusDamage;

public:
    MagicWeapon() : Weapon() {
        bonusDamage = 0;
    }

    MagicWeapon(string n, int d, WeaponType t, int bd)
        : Weapon(n, d, t) {
        bonusDamage = bd;
    }

    int getBonusDamage() {
        return bonusDamage;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Weapon sword("Меч", 50, ONEHANDED);

    cout << "Тип оружия: ";
    if (sword.getType() == ONEHANDED)
        cout << "Одноручное оружие" << endl;
    else if (sword.getType() == TWOHANDED)
        cout << "Двуручное оружие" << endl;
    else if (sword.getType() == BOW)
        cout << "Лук" << endl;
    else if (sword.getType() == CROSSBOW)
        cout << "Арбалет" << endl;

    cout << "Название: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl;

    cout << endl;

    Player p;
    p.id = 1;
    p.login = "PlayerOne";
    p.password = "35221";
    p.printInfo();

    cout << endl;

    MagicWeapon staff("Огненный посох", 40, TWOHANDED, 25);

    cout << "Магическое оружие:" << endl;
    cout << "Название: " << staff.getName() << endl;
    cout << "Урон: " << staff.getDamage() << endl;
    cout << "Бонусный урон: " << staff.getBonusDamage() << endl;

    cout << "Тип: ";
    if (staff.getType() == ONEHANDED)
        cout << "Одноручное оружие" << endl;
    else if (staff.getType() == TWOHANDED)
        cout << "Двуручное оружие" << endl;
    else if (staff.getType() == BOW)
        cout << "Лук" << endl;
    else if (staff.getType() == CROSSBOW)
        cout << "Арбалет" << endl;

    return 0;
}
