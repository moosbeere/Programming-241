#include <iostream>
#include <string>
using namespace std;

// Абстрактный класс оружия
class Weapon {
public:
    virtual void Attack() = 0;
    virtual ~Weapon() = default;
};

// Класс магического оружия 
class MagicWeapon : public Weapon {
public:
    void Attack() override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

// Класс одноразового оружия 
class SingleWeapon : public Weapon {
private:
    bool used;

public:
    SingleWeapon() : used(false) {}

    void Attack() override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
        } else {
            cout << "Атакуем одноразовым оружием" << endl;
            used = true;
        }
    }
};

// Шаблонный класс для оружия в двух руках
template <typename LeftType, typename RightType>
class DualWeapon {
private:
    LeftType left;
    RightType right;

public:
    DualWeapon(LeftType l, RightType r) : left(l), right(r) {}

    LeftType getLeft() const { return left; }
    RightType getRight() const { return right; }

    void setLeft(LeftType l) { left = l; }
    void setRight(RightType r) { right = r; }
};

int main() {
    setlocale(LC_ALL, "RU");
    // Проверяем, можно ли создать экземпляр абстрактного класса
    // Weapon w; //error: cannot declare variable ‘w’ to be of abstract type ‘Weapon’

    MagicWeapon mw;
    mw.Attack();

    cout << endl;


    SingleWeapon sw;
    sw.Attack();
    sw.Attack();

    cout << endl;


    DualWeapon<MagicWeapon, SingleWeapon> hands(mw, sw);

    cout << "Тест шаблона с объектами оружия:" << endl;
    hands.getLeft().Attack();
    hands.getRight().Attack();

    cout << endl;


    DualWeapon<int, int> weaponIDs(101, 202);
    cout << "Левый: " << weaponIDs.getLeft() << endl;
    cout << "Правый: " << weaponIDs.getRight() << endl;

    weaponIDs.setLeft(303);
    weaponIDs.setRight(404);

    cout << "После изменения:" << endl;
    cout << "Левый: " << weaponIDs.getLeft() << endl;
    cout << "Правый: " << weaponIDs.getRight() << endl;

    return 0;
}
