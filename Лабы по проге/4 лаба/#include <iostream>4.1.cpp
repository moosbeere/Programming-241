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
        : name(n), damage(d), weight(w) {}

    Weapon() : Weapon("Палка", 2, 1.0) {}

    void printInfo() const {
        cout << "Название оружия: " << name << endl;
        cout << "Наносимый урон: " << damage << endl;
        cout << "Вес оружия: " << weight << endl;
    }
};

int main() {
    Weapon sword("Клинок ночи", 42, 3.1);
    Weapon stick;

    cout << "=== Первый объект (создан с параметрами): ===" << endl;
    sword.printInfo();
    cout << endl;
    cout << "=== Второй объект (создан без параметров): ===" << endl;
    stick.printInfo();

    return 0;
}



