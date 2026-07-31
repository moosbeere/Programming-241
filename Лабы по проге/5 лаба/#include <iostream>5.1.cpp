#include <iostream>
#include <string>
using namespace std;

// 1. Создаём перечисление типов оружия
enum WeaponType {
    ONEHANDED,   // одноручное
    TWOHANDED,   // двуручное
    BOW,         // лук
    CROSSBOW     // арбалет
};

// 2. Модифицированный класс Weapon с полем WeaponType
class Weapon {
private:
    string name;
    int damage;
    double weight;
    WeaponType type;  // новое поле-тип

public:
    // Конструктор с параметрами
    Weapon(const string& n, int d, double w, WeaponType t)
        : name(n), damage(d), weight(w), type(t) {}

    // Конструктор по умолчанию
    Weapon() : Weapon("Палка", 2, 1.0, ONEHANDED) {}

    string getName() const { return name; }
    int getDamage() const { return damage; }
    double getWeight() const { return weight; }
    WeaponType getType() const { return type; }

    void setDamage(int d) { damage = d; }

    void printInfo() const {
        cout << "Название оружия: " << name << endl;
        cout << "Наносимый урон: " << damage << endl;
        cout << "Вес оружия: " << weight << endl;
        // 3. Вывод текстового представления типа
        cout << "Тип оружия: ";
        if (type == ONEHANDED) cout << "Одноручное оружие";
        else if (type == TWOHANDED) cout << "Двуручное оружие";
        else if (type == BOW) cout << "Лук";
        else if (type == CROSSBOW) cout << "Арбалет";
        else cout << "Неизвестный тип";
        cout << endl;
    }
};

// 4. Структура игрока
struct Player {
    int id;              // уникальный идентификатор
    string login;
    string password;
    // 5. Функция вывода данных в консоль
    void printInfo() const {
        cout << "Игрок ID: " << id << endl;
        cout << "Логин: " << login << endl;
        cout << "Пароль: " << password << endl;
    }
};

// 7. Дочерний класс MagWeapon для магического оружия
class MagWeapon : public Weapon {
private:
    int extraDamage;  // 8. дополнительный урон

public:
    // 9. Конструктор с параметрами
    MagWeapon(const string& n, int d, double w, WeaponType t, int extra)
        : Weapon(n, d, w, t), extraDamage(extra) {}

    // 9. Конструктор по умолчанию
    MagWeapon() : Weapon("Магический посох", 10, 2.5, TWOHANDED), extraDamage(5) {}

    // 10. GET-метод для поля extraDamage
    int getExtraDamage() const { return extraDamage; }

    // Переопределённый вывод информации (для теста)
    void printInfo() const {
        Weapon::printInfo();
        cout << "Дополнительный магический урон: " << extraDamage << endl;
    }
};

int main() {
    // Тестируем Weapon с типами и выводом
    Weapon sword("Клинок ночи", 42, 3.1, ONEHANDED);
    cout << "=== Оружие (sword): ===" << endl;
    sword.printInfo();
    cout << endl;

    Weapon bow("Охотничий лук", 18, 1.5, BOW);
    cout << "=== Оружие (bow): ===" << endl;
    bow.printInfo();
    cout << endl;

    // 6. Тестируем структуру игрока
    Player p1;
    p1.id = 123;
    p1.login = "dragonSlayer";
    p1.password = "qwerty123";
    cout << "=== Тест игрока Player ===" << endl;
    p1.printInfo();
    cout << endl;

    // 11. Тест MagWeapon
    MagWeapon staff("Посох мудреца", 22, 2.8, TWOHANDED, 13);
    cout << "=== Магическое оружие (staff): ===" << endl;
    staff.printInfo();
    cout << "Extra damage через getExtraDamage(): " << staff.getExtraDamage() << endl;
    cout << endl;

    MagWeapon defaultMag;
    cout << "=== Магическое оружие (defaultMag, по умолчанию): ===" << endl;
    defaultMag.printInfo();

    return 0;
}
