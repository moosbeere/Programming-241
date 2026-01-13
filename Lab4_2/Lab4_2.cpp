#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// Класс оружия
class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    // Конструктор с параметрами
    Weapon(string n, int d, float w) {
        name = n;
        damage = d;
        weight = w;
    }

    // Конструктор без параметров
    Weapon() : Weapon("Обычный меч", 10, 3.5f) {
    }

    // Деструктор (пункт 1)
    ~Weapon() {
        cout << "Удаляется оружие:" << endl;
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << endl;
        cout << "" << endl;
    }

    // Вывод информации
    void printInfo() const {
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << endl;
    }

    // Пункт 5: проверка, сможет ли поднять оружие
    bool isTooHeavy(float maxWeight) const {
        return maxWeight < weight;
    }

    // Пункт 7: метод, принимающий просто вес
    float totalWeight(float otherWeight) const {
        return weight + otherWeight;
    }

    // Пункт 6 и 8: метод, принимающий объект оружия
    // Использует перегрузку
    float totalWeight(const Weapon& other) const {
        return totalWeight(other.weight);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Обычный объект " << endl;
    Weapon weapon1("Топор", 30, 7.5f);
    weapon1.printInfo();

    cout << "Проверка веса (макс. 6): ";
    cout << (weapon1.isTooHeavy(6) ? "слишком тяжёлый" : "можно поднять") << endl;

    cout << endl << "Динамический объект " << endl;
    Weapon* weapon2 = new Weapon("Кинжал", 15, 2.0f);
    weapon2->printInfo();

    cout << "Проверка веса (макс. 3): ";
    cout << (weapon2->isTooHeavy(3) ? "слишком тяжёлый" : "можно поднять") << endl;

    cout << endl << "Проверка суммарного веса" << endl;
    cout << "weapon1 + weapon2 = "
        << weapon1.totalWeight(*weapon2) << endl;

    cout << "weapon1 + вес 5 = "
        << weapon1.totalWeight(5.0f) << endl;

    // Удаление динамического объекта (пункт 4)
    delete weapon2;

    cout << endl << "Конец программы" << endl;
    return 0;
}
