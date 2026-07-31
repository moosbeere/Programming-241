#include <iostream>
#include <string>
using namespace std;

// 1. Базовый класс Weapon с виртуальным методом getDamage
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
    virtual int getDamage() const { return damage; } // теперь виртуальный!
    double getWeight() const { return weight; }

    // 4. Операторы сравнения > и <
    bool operator>(const Weapon& other) const {
        return getDamage() > other.getDamage();
    }
    bool operator<(const Weapon& other) const {
        return getDamage() < other.getDamage();
    }

    virtual void printInfo() const {
        cout << "Название оружия: " << name << endl;
        cout << "Наносимый урон: " << getDamage() << endl;
        cout << "Вес оружия: " << weight << endl;
    }
};

// 2. Дочерний класс MagWeapon с переопределением getDamage
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
};

int main() {
    // 3. Проверка суммарного урона у обычного и магического оружия
    Weapon sword("Клинок", 20, 2.5);
    MagWeapon fireSword("Огненный меч", 18, 2.6, 15);

    cout << "=== Обычное оружие ===" << endl;
    sword.printInfo();
    cout << endl;

    cout << "=== Магическое оружие ===" << endl;
    fireSword.printInfo();
    cout << endl;

    cout << "Урон обычного меча: " << sword.getDamage() << endl;
    cout << "Урон магического меча: " << fireSword.getDamage() << endl; // должно быть damage + extraDamage
    cout << endl;

    // 5. Проверка операторов > и <
    cout << "--- Проверка сравнения ---" << endl;
    if (fireSword > sword) {
        cout << fireSword.getName() << " сильнее, чем " << sword.getName() << endl;
    } else {
        cout << sword.getName() << " сильнее, чем " << fireSword.getName() << endl;
    }

    Weapon dagger("Кинжал", 10, 1.0);
    if (dagger < sword) {
        cout << dagger.getName() << " слабее, чем " << sword.getName() << endl;
    }

    if (dagger < fireSword) {
        cout << dagger.getName() << " слабее, чем " << fireSword.getName() << endl;
    }

    MagWeapon shadowDagger("Теневой кинжал", 6, 1.2, 8); // общий урон: 6+8=14
    if (shadowDagger > dagger) {
        cout << shadowDagger.getName() << " сильнее, чем " << dagger.getName() << endl;
    }

    if (shadowDagger < fireSword) {
        cout << shadowDagger.getName() << " слабее, чем " << fireSword.getName() << endl;
    }

    return 0;
}
