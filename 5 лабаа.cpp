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
    Weapon(string n, int d, WeaponType t) {
        name = n;
        damage = d;
        type = t;
    }

    Weapon() {
        name = "Unknown";
        damage = 0;
        type = ONEHANDED;
    }

    string getName() { return name; }
    int getDamage() { return damage; }
    WeaponType getType() { return type; }
};

struct Player {
    int id;
    string login;
    string password;

    void printInfo() {
        cout << "Игрок:" << endl;
        cout << "ID: " << id << endl;
        cout << "Логин: " << login << endl;
        cout << "Пароль: " << password << endl;
    }
};

class MagicWeapon : public Weapon {
private:
    int magicDamage;

public:
    MagicWeapon() : Weapon() {
        magicDamage = 0;
    }

    MagicWeapon(string n, int d, WeaponType t, int m)
        : Weapon(n, d, t) {
        magicDamage = m;
    }

    int getMagicDamage() { return magicDamage; }
};

int main() {

    setlocale(LC_ALL, "RUS");

    Weapon sword("Sword", 25, ONEHANDED);

    cout << "Тип оружия: ";
    if (sword.getType() == ONEHANDED) cout << "Одноручное оружие";
    else if (sword.getType() == TWOHANDED) cout << "Двуручное оружие";
    else if (sword.getType() == BOW) cout << "Лук";
    else if (sword.getType() == CROSSBOW) cout << "Арбалет";
    cout << endl << endl;

    Player p1;
    p1.id = 1;
    p1.login = "Hero";
    p1.password = "12345";
    p1.printInfo();

    cout << endl;

    MagicWeapon staff("Magic Staff", 15, TWOHANDED, 40);

    cout << "Магическое оружие:" << endl;
    cout << "Название: " << staff.getName() << endl;
    cout << "Урон: " << staff.getDamage() << endl;
    cout << "Магический урон: " << staff.getMagicDamage() << endl;
    cout << "Тип: ";

    if (staff.getType() == ONEHANDED) cout << "Одноручное";
    else if (staff.getType() == TWOHANDED) cout << "Двуручное";
    else if (staff.getType() == BOW) cout << "Лук";
    else if (staff.getType() == CROSSBOW) cout << "Арбалет";

    cout << endl;

    return 0;
}

///2 задание

#include <iostream>
#include <string>
using namespace std;

class Weapon {
protected:
    string name;
    int damage;

public:
    Weapon(string n, int d) : name(n), damage(d) {}
    Weapon() : name("Unknown"), damage(0) {}

    virtual void Attack() = 0;

    string getName() const { return name; }
    int getDamage() const { return damage; }
};

class MagicWeapon : public Weapon {
private:
    int magicDamage;

public:
    MagicWeapon(string n, int d, int md)
        : Weapon(n, d), magicDamage(md) {
    }

    MagicWeapon() : Weapon(), magicDamage(0) {}

    int getMagicDamage() const { return magicDamage; }

    void Attack() override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

class SingleUseWeapon : public Weapon {
private:
    bool used;  

public:
    SingleUseWeapon(string n, int d)
        : Weapon(n, d), used(false) {
    }

    SingleUseWeapon() : Weapon(), used(false) {}

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

template <typename T1, typename T2>
class DualWield {
private:
    T1 leftHand;
    T2 rightHand;

public:
    DualWield(T1 left, T2 right)
        : leftHand(left), rightHand(right) {
    }

    T1 getLeftHand() const { return leftHand; }
    T2 getRightHand() const { return rightHand; }

    void setLeftHand(T1 value) { leftHand = value; }
    void setRightHand(T2 value) { rightHand = value; }
};

int main() {

    MagicWeapon staff("Magic Staff", 20, 50);
    staff.Attack();

    cout << endl;

    SingleUseWeapon bomb("Bomb", 100);
    bomb.Attack();  
    bomb.Attack();  

    cout << endl;

    DualWield<MagicWeapon, SingleUseWeapon> hands(staff, bomb);
    hands.getLeftHand().Attack();   
    hands.getRightHand().Attack(); 

    cout << endl;

    DualWield<int, int> weaponIDs(101, 202);
    cout << "ID левой руки: " << weaponIDs.getLeftHand() << endl;
    cout << "ID правой руки: " << weaponIDs.getRightHand() << endl;

    return 0;
}
