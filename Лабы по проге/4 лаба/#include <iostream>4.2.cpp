#include <iostream>

#include <string>
using namespace std;

class Weapon {
private:
    string name;
    int damage;
    double weight;
public:
    Weapon(const string& n, int d, double w)
        : name(n), damage(d), weight(w) {
        cout << "[Конструктор] Создано: " << name << endl;
    }

    Weapon() : Weapon("Палка", 2, 1.0) {}

    // ДЕСТРУКТОР (главное - оставить!)
    ~Weapon() {
        cout << "[Деструктор] Уничтожается: " << name 
             << " (урон: " << damage 
             << ", вес: " << weight << ")" << endl;
    }

    void printInfo() const {
        cout << "Оружие: " << name 
             << " | Урон: " << damage 
             << " | Вес: " << weight << endl;
    }

    bool isTooHeavy(double maxWeight) const {
        return weight > maxWeight;
    }

    double totalWeight(const Weapon& other) const {
        return weight + other.weight;
    }

    double totalWeight(double otherWeight) const {
        return weight + otherWeight;
    }
};

int main() {
    cout << "=== НАЧАЛО ПРОГРАММЫ ===" << endl << endl;

    // 1. Статический объект (уничтожится автоматически)
    Weapon sword("Клинок ночи", 42, 3.1);
    cout << "1. Sword создан: ";
    sword.printInfo();
    cout << endl;

    // 2. Динамический объект (нужен delete)
    Weapon* pAxe = new Weapon("Боевой топор", 55, 8.0);
    cout << "2. Axe создан: ";
    pAxe->printInfo();
    cout << endl;

    // 3. Проверка веса
    cout << "3. Проверка веса:" << endl;
    cout << "   Sword слишком тяжел для 2.0? " 
         << (sword.isTooHeavy(2.0) ? "ДА" : "нет") << endl;
    cout << "   Axe слишком тяжел для 9.0? " 
         << (pAxe->isTooHeavy(9.0) ? "ДА" : "нет") << endl;
    cout << endl;

    // 4. Сумма весов
    cout << "4. Суммы весов:" << endl;
    cout << "   Sword + Axe = " << sword.totalWeight(*pAxe) << endl;
    cout << "   Sword + 2.5 = " << sword.totalWeight(2.5) << endl;
    cout << endl;

    // 5. Удаление динамического объекта (вызов деструктора!)
    cout << "5. Удаление динамического объекта Axe:" << endl;
    delete pAxe;
    cout << endl;

    // 6. Выход из main - автоматический вызов деструктора для sword
    cout << "6. Завершение main() - автоматически уничтожится sword" << endl;
    cout << "=== КОНЕЦ ПРОГРАММЫ ===" << endl;

    return 0;
}
