#include <iostream> // Библиотека ввода-вывода
#include <string>   // Библиотека для работы со строками

using namespace std; // Использование стандартного пространства имен

// 1-3. Класс Weapon: инкапсуляция данных (private) и методы доступа (public)
class Weapon {
private:
    string name;   // Название оружия
    int damage;    // Урон
    double weight; // Вес
public:
    // Конструктор с параметрами для инициализации всех полей
    Weapon(const string& n, int d, double w)
        : name(n), damage(d), weight(w) {
    }

    // Конструктор по умолчанию (создает "Палку")
    Weapon() : Weapon("Палка", 2, 1.0) {}

    // Геттеры (Get-методы) для получения значений закрытых полей
    string getName() const { return name; }
    int getDamage() const { return damage; }
    double getWeight() const { return weight; }

    // Сеттер (Set-метод) для изменения урона
    void setDamage(int newDamage) { damage = newDamage; }

    // 6. Объявление дружественного класса (он сможет видеть private поля Weapon)
    friend class Characteristic;
};

// 5. Класс Characteristic: хранит силу персонажа
class Characteristic {
private:
    int strength; // Сила
public:
    // Конструктор инициализации силы
    Characteristic(int str) : strength(str) {}

    // 7. Метод расчета урона: складывает свою силу и приватный урон оружия
    int GetDamage(const Weapon& w) const {
        return strength + w.damage; // Доступ к w.damage возможен благодаря friend
    }
};

// 9-11. Класс MyMath со статическими членами (не требуют создания объекта)
class MyMath {
public:
    static int callCount; // Статическая переменная-счетчик всех вызовов

    // Статические методы для арифметических операций
    static int Add(int a, int b) { ++callCount; return a + b; }
    static int Sub(int a, int b) { ++callCount; return a - b; }
    static int Mult(int a, int b) { ++callCount; return a * b; }
    static double Div(int a, int b) {
        ++callCount;
        if (b == 0) throw std::runtime_error("Деление на ноль!"); // Проверка деления
        return (double)a / b;
    }
};

// Инициализация статической переменной вне класса
int MyMath::callCount = 0;

int main() {
    setlocale(LC_ALL, "Russian"); // Поддержка русского языка

    // Демонстрация инкапсуляции (геттеры и сеттеры)
    cout << "-- Проверка get/set методов --" << endl;
    Weapon club("Дубина", 12, 5.4);
    cout << "Название: " << club.getName() << endl;
    cout << "Урон: " << club.getDamage() << endl;
    cout << "Вес: " << club.getWeight() << endl;

    cout << "Изменим урон на 35." << endl;
    club.setDamage(35); // Меняем данные через метод
    cout << "Новый урон: " << club.getDamage() << endl << endl;

    // Демонстрация дружественного класса
    cout << "-- Проверка работы Characteristic и GetDamage --" << endl;
    Characteristic strongGuy(22);
    cout << "Суммарный урон (сила + урон оружия): "
        << strongGuy.GetDamage(club) << endl << endl;

    // Демонстрация статических методов и полей
    cout << "-- Проверка MyMath --" << endl;
    int a = 16, b = 4;
    cout << "Add(" << a << ", " << b << ") = " << MyMath::Add(a, b) << endl;
    cout << "Sub(" << a << ", " << b << ") = " << MyMath::Sub(a, b) << endl;
    cout << "Mult(" << a << ", " << b << ") = " << MyMath::Mult(a, b) << endl;
    cout << "Div(" << a << ", " << b << ") = " << MyMath::Div(a, b) << endl;

    // Вывод итогового значения счетчика
    cout << "Количество вызовов MyMath: " << MyMath::callCount << endl;

    return 0; // Завершение программы
}