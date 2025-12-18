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
    Weapon(string n, int d, WeaponType t) {
        name = n;
        damage = d;
        type = t;
    }

    virtual int getDamage() {
        return damage;
    }

    virtual void Attack() = 0;
};

class MagicWeapon : public Weapon {
private:
    int bonusDamage;

public:
    MagicWeapon(string n, int d, WeaponType t, int bd)
        : Weapon(n, d, t) {
        bonusDamage = bd;
    }

    int getDamage() override {
        return damage + bonusDamage;
    }

    void Attack() override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

class OneTimeWeapon : public Weapon {
private:
    bool used;

public:
    OneTimeWeapon(string n, int d, WeaponType t)
        : Weapon(n, d, t) {
        used = false;
    }

    void Attack() override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
        }
        else {
            cout << "Атакуем одноразовым оружием" << endl;
            used = true;
        }
    }
};

template <typename LeftType, typename RightType>
class DualWeapon {
private:
    LeftType leftHand;
    RightType rightHand;

public:
    DualWeapon(LeftType l, RightType r) {
        leftHand = l;
        rightHand = r;
    }

    LeftType getLeft() {
        return leftHand;
    }

    RightType getRight() {
        return rightHand;
    }

    void setLeft(LeftType l) {
        leftHand = l;
    }

    void setRight(RightType r) {
        rightHand = r;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    MagicWeapon staff("Посох", 40, TWOHANDED, 20);
    staff.Attack();

    cout << endl;

    OneTimeWeapon bomb("Бомба", 100, ONEHANDED);
    bomb.Attack();
    bomb.Attack();

    cout << endl;

    DualWeapon<MagicWeapon, OneTimeWeapon> realWeapons(
        MagicWeapon("Жезл", 20, ONEHANDED, 10),
        OneTimeWeapon("Граната", 80, ONEHANDED)
    );

    realWeapons.getLeft().Attack();
    realWeapons.getRight().Attack();

    cout << endl;

    DualWeapon<int, int> weaponIds(1001, 2002);

    cout << "ID оружия в левой руке: " << weaponIds.getLeft() << endl;
    cout << "ID оружия в правой руке: " << weaponIds.getRight() << endl;

    return 0;
}