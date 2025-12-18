#include <iostream>
using namespace std;

class Weapon {
public:
    string name;
    int damage;
    float weight;

    Weapon(string n, int d, int w) {
        name = n;
        damage = d;
        weight = w;
    }

    ~Weapon() {
        cout << "Удаление оружия: " << name
            << " (урон: " << damage
            << ", вес: " << weight << ")" << endl;
    }

    bool canLift(int maxWeight) {
        return weight > maxWeight;
    }

    float totalWeight(float w) {
        return weight + w;
    }

    float totalWeight(const Weapon& x) {
        return totalWeight(x.weight);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 50, 3);
    cout << "Обычный объект: " << sword.name << ", урон: " << sword.damage << ", вес: " << sword.weight << endl;

    Weapon* axe = new Weapon("Топор", 80, 5);
    cout << "Динамический объект: " << axe->name << ", урон: " << axe->damage << ", вес: " << axe->weight << endl;

    cout << "Вес = 2 ";
    if (sword.canLift(2)) {
        cout << "Поднимет";
    }
    else {
        cout << "Не поднимет";
    }
    cout << endl;


    cout << "Меч + Топор = " << sword.totalWeight(*axe) << endl;

    cout << "Меч + 10 = " << sword.totalWeight(10) << endl;

    delete axe;

    return 0;
}