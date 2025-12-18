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
protected:
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

    virtual int getDamage() {
        return damage;
    }

    string getName() {
        return name;
    }

    bool operator>(Weapon& other) {
        return this->getDamage() > other.getDamage();
    }

    bool operator<(Weapon& other) {
        return this->getDamage() < other.getDamage();
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

    int getDamage() override {
        return damage + bonusDamage;
    }

    int getBonusDamage() {
        return bonusDamage;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Weapon sword("Меч", 50, ONEHANDED);
    MagicWeapon staff("Посох", 40, TWOHANDED, 25);

    cout << "Урон меча: " << sword.getDamage() << endl;
    cout << "Урон посоха (суммарный): " << staff.getDamage() << endl;

    cout << endl;

    if (staff > sword)
        cout << "Посох сильнее меча" << endl;
    else
        cout << "Меч сильнее или равен посоху" << endl;

    if (sword < staff)
        cout << "Меч слабее посоха" << endl;
    else
        cout << "Меч сильнее или равен посоху" << endl;

    cout << endl;

    MagicWeapon wand("Жезл", 20, ONEHANDED, 5);

    if (wand > sword)
        cout << "Жезл сильнее меча" << endl;
    else
        cout << "Жезл слабее или равен мечу" << endl;

    return 0;
}
