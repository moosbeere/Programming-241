#include <iostream>
#include <string>
#include <clocale>   // для setlocale

using namespace std;

// Класс оружия
class Weapon {
private:
    string name;   // название оружия
    int damage;    // наносимый урон
    float weight;  // вес оружия

public:
    // Конструктор с параметрами
    Weapon(string n, int d, float w) {
        name = n;
        damage = d;
        weight = w;
    }

    // Конструктор без параметров
    // Вызывает конструктор с параметрами и задаёт значения по умолчанию
    Weapon() : Weapon("Обычный меч", 10, 3.5f) {
    }

    // Метод вывода информации
    void printInfo() {
        cout << "Название оружия: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    // Русский язык в консоли
    setlocale(LC_ALL, "Russian");

    // Объект с параметрами
    Weapon weapon1("Двуручный топор", 35, 8.2f);

    // Объект без параметров
    Weapon weapon2;

    // Вывод данных
    weapon1.printInfo();
    weapon2.printInfo();

    return 0;
}
