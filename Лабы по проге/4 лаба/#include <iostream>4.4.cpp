#include <iostream>
#include <string>

using namespace std;

// 1-3. Weapon: все поля закрыты, get/set методы
class Weapon {
private:
    string name;
    int damage;
    double weight;
public:
    Weapon(const string& n, int d, double w)
        : name(n), damage(d), weight(w) {}

    Weapon() : Weapon("Палка", 2, 1.0) {}

    string getName() const { return name; }
    int getDamage() const { return damage; }
    double getWeight() const { return weight; }

    void setDamage(int newDamage) { damage = newDamage; }

    // 6. Дружба
    friend class Characteristic;
};

// 5. Класс Characteristic с полем сила, конструктором, методом GetDamage
class Characteristic {
private:
    int strength;
public:
    Characteristic(int str) : strength(str) {}
    // 7. Метод, возвращающий сумму силы и урона оружия
    int GetDamage(const Weapon& w) const {
        return strength + w.damage;
    }
};

// 9-11. Класс MyMath с 4 статическими методами и счетчиком вызова
class MyMath {
public:
    static int callCount;

    static int Add(int a, int b)  { ++callCount; return a + b; }
    static int Sub(int a, int b)  { ++callCount; return a - b; }
    static int Mult(int a, int b) { ++callCount; return a * b; }
    static double Div(int a, int b) { ++callCount; if (b == 0) throw std::runtime_error("Деление на ноль!"); return (double)a / b; }
};
int MyMath::callCount = 0;

// Самостоятельная демонстрация всех функционалов
int main() {
    cout << "-- Проверка get/set методов --" << endl;
    Weapon club("Дубина", 12, 5.4);

    cout << "Название: " << club.getName() << endl;
    cout << "Урон: " << club.getDamage() << endl;
    cout << "Вес: " << club.getWeight() << endl;
    cout << "Изменим урон на 35." << endl;
    club.setDamage(35);
    cout << "Новый урон: " << club.getDamage() << endl << endl;

    cout << "-- Проверка работы Characteristic и GetDamage --" << endl;
    Characteristic strongGuy(22);
    cout << "Суммарный урон (сила + урон оружия): "
         << strongGuy.GetDamage(club) << endl << endl;

    cout << "-- Проверка MyMath --" << endl;
    int a = 16, b = 4;
    cout << "Add(" << a << ", " << b << ") = " << MyMath::Add(a, b) << endl;
    cout << "Sub(" << a << ", " << b << ") = " << MyMath::Sub(a, b) << endl;
    cout << "Mult(" << a << ", " << b << ") = " << MyMath::Mult(a, b) << endl;
    cout << "Div(" << a << ", " << b << ") = " << MyMath::Div(a, b) << endl;
    cout << "Количество вызовов MyMath: " << MyMath::callCount << endl;

    return 0;
}