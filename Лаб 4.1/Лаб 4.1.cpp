#include <iostream>
using namespace std;

class Weapon {
public:
    string name;
    int damage;
    int weight;

    Weapon(string n, int d, int w) {
        name = n;
        damage = d;
        weight = w;
    }

    Weapon() : Weapon("Пистолет", 25, 1) {}
};

int main() {
    setlocale(LC_ALL, "Russian");

    Weapon sword("Арбалет", 50, 3);

    Weapon gun;

    cout << "Название: " << sword.name
        << ", Урон: " << sword.damage
        << ", Вес: " << sword.weight << endl;

    cout << "Название: " << gun.name
        << ", Урон: " << gun.damage
        << ", Вес: " << gun.weight << endl;

    return 0;
}