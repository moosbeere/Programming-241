#include <iostream>
#include <string>
using namespace std;

// Создаём класс оружия
class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    // Конструктор с параметрами
    Weapon(string n, int d, float w)
        : name(n), damage(d), weight(w) {}

    // Конструктор без параметров, вызывающий первый конструктор
    Weapon() : Weapon("Default Gun", 10, 2.5f) {}

    void printInfo() {
        cout << "Имя: " << name
             << ", Урон: " << damage
             << ", Вес: " << weight << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Weapon AK("AK-47", 30, 7.0f); // конструктор с параметрами
    Weapon defaultGun; // конструктор без параметров

    cout << "Оружие 1:" << endl;
    AK.printInfo();

    cout << "\nОружие 2:" << endl;
    defaultGun.printInfo();

    return 0;
}

