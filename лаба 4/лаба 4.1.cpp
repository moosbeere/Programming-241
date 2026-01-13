#include <iostream>
#include <string>
#include <clocale>  // для setlocale

using namespace std;

class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    Weapon(string weaponName, int weaponDamage, float weaponWeight)
        : name(weaponName), damage(weaponDamage), weight(weaponWeight) {
    }

    Weapon() : Weapon("Стандартное оружие", 10, 2.5) {}

    string getName() const { return name; }
    int getDamage() const { return damage; }
    float getWeight() const { return weight; }

    void display() const {
        cout << "Оружие: " << name
            << " | Урон: " << damage
            << " | Вес: " << weight << " кг" << endl;
    }
};

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 15, 3.2);
    Weapon defaultWeapon;

    cout << "=== Первый объект ===" << endl;
    sword.display();

    cout << "\n=== Второй объект ===" << endl;
    defaultWeapon.display();

    // Альтернативный вывод через геттеры
    cout << "\n--- Детальная информация ---" << endl;
    cout << "1. Название: " << sword.getName()
        << ", Урон: " << sword.getDamage()
        << ", Вес: " << sword.getWeight() << endl;

    cout << "2. Название: " << defaultWeapon.getName()
        << ", Урон: " << defaultWeapon.getDamage()
        << ", Вес: " << defaultWeapon.getWeight() << endl;

    return 0;
}
