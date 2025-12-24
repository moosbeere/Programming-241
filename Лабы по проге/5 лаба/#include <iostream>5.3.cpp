#include <iostream>
#include <string>
using namespace std;

// 1. Абстрактный класс Weapon с чисто виртуальной функцией Attack
class Weapon {
protected:
    string name;
    int damage;
    double weight;
public:
    Weapon(const string& n, int d, double w)
        : name(n), damage(d), weight(w) {}

    Weapon() : Weapon("Палка", 2, 1.0) {}

    string getName() const { return name; }
    virtual int getDamage() const { return damage; }
    double getWeight() const { return weight; }
    virtual void Attack() const = 0;
    virtual void printInfo() const {
        cout << "Название оружия: " << name << endl;
        cout << "Наносимый урон: " << getDamage() << endl;
        cout << "Вес оружия: " << weight << endl;
    }
};

// 2. Класс MagWeapon – реализация Attack
class MagWeapon : public Weapon {
    int extraDamage;
public:
    MagWeapon(const string& n, int d, double w, int extra)
        : Weapon(n, d, w), extraDamage(extra) {}

    int getDamage() const override {
        return damage + extraDamage;
    }

    void printInfo() const override {
        cout << "Название маг. оружия: " << name << endl;
        cout << "Базовый урон: " << damage << endl;
        cout << "Доп. магический урон: " << extraDamage << endl;
        cout << "Общий урон: " << getDamage() << endl;
        cout << "Вес: " << weight << endl;
    }

    void Attack() const override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

// 5. Класс SingleUseWeapon (одноразовое оружие)
class SingleUseWeapon : public Weapon {
    mutable bool used;
public:
    SingleUseWeapon(const string& n, int d, double w)
        : Weapon(n, d, w), used(false) {}

    // 7. Логика одноразовой атаки
    void Attack() const override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
        } else {
            cout << "Атакуем одноразовым оружием" << endl;
            used = true;
        }
    }

    bool isUsed() const { return used; }
    void reset() { used = false; }
};

// 9. Шаблон DualWeaponHolder<, >
template<typename TLeft, typename TRight>
class DualWeaponHolder {
private:
    TLeft leftWeapon;
    TRight rightWeapon;
public:
    DualWeaponHolder(const TLeft& left, const TRight& right)
        : leftWeapon(left), rightWeapon(right) {}

    TLeft getLeft() const { return leftWeapon; }
    TRight getRight() const { return rightWeapon; }

    void setLeft(const TLeft& left) { leftWeapon = left; }
    void setRight(const TRight& right) { rightWeapon = right; }
};

int main() {
    // 3. Проверка невозможности создать экземпляр абстрактного класса (закомментированно):
    // Weapon base("Base", 5, 2.0); // Нельзя! Абстрактный класс

    // 4. Экземпляр магического оружия, вызов Attack
    MagWeapon fireSword("Огненный посох", 10, 2.0, 8);
    fireSword.Attack();

    // 8. Экземпляр одноразового оружия, двойная атака
    SingleUseWeapon bomb("Граната", 60, 0.7);
    bomb.Attack();
    bomb.Attack();

    // 11. Проверка работы шаблона с оружием
    DualWeaponHolder<MagWeapon, SingleUseWeapon> holder(fireSword, bomb);
    cout << holder.getLeft().getName() << endl;
    cout << holder.getRight().getName() << endl;

    MagWeapon iceStaff("Ледяной посох", 7, 2.1, 12);
    holder.setLeft(iceStaff);
    cout << holder.getLeft().getName() << endl;

    // 11. Проверка работы шаблона с int
    DualWeaponHolder<int, int> idHolder(101, 205);
    cout << idHolder.getLeft() << endl;
    cout << idHolder.getRight() << endl;
    idHolder.setRight(404);
    cout << idHolder.getRight() << endl;

    return 0;
}


