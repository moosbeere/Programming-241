#include <iostream>
#include <string>
using namespace std;

// Перечисление типов оружия
enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

// Класс оружия
class Weapon {
private:
    string name;
    int damage;
    float weight;
    WeaponType type;

public:
    // Конструктор с параметрами
    Weapon(string n, int d, float w, WeaponType t)
        : name(n), damage(d), weight(w), type(t) {}

    // Конструктор без параметров
    Weapon() : Weapon("Default Sword", 10, 2.5f, ONEHANDED) {}

    // GET-методы
    string getName() const { return name; }
    int getDamage() const { return damage; }
    float getWeight() const { return weight; }
    WeaponType getType() const { return type; }

    // Функция для вывода данных
    void printInfo() const {
        cout << "Название: " << name
             << ", Урон: " << damage
             << ", Вес: " << weight << endl;
    }
};

// Структура игрока
struct Player {
    int id;
    string login;
    string password;

    // Функция для вывода данных
    void printInfo() const {
        cout << "ID: " << id
             << ", Логин: " << login
             << ", Пароль: " << password << endl;
    }
};

// Дочерний класс для маг оружия
class MagicWeapon : public Weapon {
private:
    int magicDamage;

public:
    // Конструктор с параметрами
    MagicWeapon(string n, int d, float w, WeaponType t, int m)
        : Weapon(n, d, w, t), magicDamage(m) {}

    // конструктор без параметров
    MagicWeapon() : Weapon(), magicDamage(5) {}

    // GET-методы
    int getMagicDamage() const { return magicDamage; }

    // Функция для вывода данных
    void printMagicInfo() const {
        printInfo();
        cout << "Магический урон: " << magicDamage << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Weapon sword("Diamond sword", 7, 3.4f, ONEHANDED);
    Weapon bow("Wooden Bow", 3, 2.0f, BOW);

    cout << "Тип оружия: ";
    if (sword.getType() == ONEHANDED) cout << "Одноручное оружие\n";
    if (sword.getType() == TWOHANDED) cout << "Двуручное оружие\n";
    if (sword.getType() == BOW) cout << "Лук\n";
    if (sword.getType() == CROSSBOW) cout << "Арбалет\n";

    cout << endl;

    Player player;
    player.id = 1;
    player.login = "ABCD1234";
    player.password = "aa9348asd";
    player.printInfo();

    cout << endl;

    MagicWeapon fireSword("Fire Sword", 40, 3.4f, ONEHANDED, 25);
    MagicWeapon defaultMagic;

    cout << "Магическое оружие:\n";
    fireSword.printMagicInfo();

    cout << "\nДефолтное Магическое оружие:\n";
    defaultMagic.printMagicInfo();

    return 0;
}
