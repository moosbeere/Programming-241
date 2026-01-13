#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// 1. Перечисление типов оружия
enum class WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

// Базовый класс оружия
class Weapon {
private:
    string name;
    int damage;
    // 2. Добавлена переменная типа перечисления
    WeaponType type;
    
public:
    // Конструкторы
    Weapon() : name("Безымянное"), damage(10), type(WeaponType::ONEHANDED) {}
    
    Weapon(string n, int d, WeaponType t) : name(n), damage(d), type(t) {}
    
    // GET-методы
    string getName() const { return name; }
    int getDamage() const { return damage; }
    WeaponType getType() const { return type; } // 2. GET-метод для типа
};

// 4. Структура игрока
struct Player {
    int id;             // уникальный идентификатор
    string login;       // логин
    string password;    // пароль
    
    // 5. Функция вывода данных
    void printInfo() const {
        cout << "ID: " << id << endl;
        cout << "Логин: " << login << endl;
        cout << "Пароль: " << password << endl;
    }
};

// 7. Дочерний класс магического оружия
class MagicWeapon : public Weapon {
private:
    // 8. Поле дополнительного урона
    int additionalDamage;
    
public:
    // 9. Конструктор без параметров
    MagicWeapon() : Weapon(), additionalDamage(5) {}
    
    // 9. Конструктор с параметрами
    MagicWeapon(string n, int d, WeaponType t, int addDmg) 
        : Weapon(n, d, t), additionalDamage(addDmg) {}
    
    // 10. GET-метод для дополнительного урона
    int getAdditionalDamage() const { return additionalDamage; }
    
    // Метод для получения общего урона
    int getTotalDamage() const {
        return getDamage() + additionalDamage;
    }
};

int main() {
    // Установка русской локали
    setlocale(LC_ALL, "Russian");
    
    // Создание объекта оружия
    Weapon sword("Меч", 15, WeaponType::ONEHANDED);
    
    // 3. Вывод текстового представления типа оружия
    cout << "Информация об оружии:" << endl;
    cout << "Название: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl;
    cout << "Тип: ";
    
    if (sword.getType() == WeaponType::ONEHANDED) {
        cout << "Одноручное оружие";
    } else if (sword.getType() == WeaponType::TWOHANDED) {
        cout << "Двуручное оружие";
    } else if (sword.getType() == WeaponType::BOW) {
        cout << "Лук";
    } else if (sword.getType() == WeaponType::CROSSBOW) {
        cout << "Арбалет";
    }
    cout << endl << endl;
    
    // 6. Тестирование структуры Player
    Player player1;
    player1.id = 1;
    player1.login = "warrior123";
    player1.password = "securePass";
    
    cout << "Информация об игроке:" << endl;
    player1.printInfo();
    cout << endl;
    
    // 11. Тестирование класса MagicWeapon
    cout << "Тестирование магического оружия:" << endl;
    
    // Использование конструктора без параметров
    MagicWeapon magicWeapon1;
    cout << "Магическое оружие (конструктор без параметров):" << endl;
    cout << "Название: " << magicWeapon1.getName() << endl;
    cout << "Базовый урон: " << magicWeapon1.getDamage() << endl;
    cout << "Дополнительный урон: " << magicWeapon1.getAdditionalDamage() << endl;
    cout << "Общий урон: " << magicWeapon1.getTotalDamage() << endl;
    cout << endl;
    
    // Использование конструктора с параметрами
    MagicWeapon magicWeapon2("Посох магии", 20, WeaponType::TWOHANDED, 15);
    cout << "Магическое оружие (конструктор с параметрами):" << endl;
    cout << "Название: " << magicWeapon2.getName() << endl;
    cout << "Базовый урон: " << magicWeapon2.getDamage() << endl;
    cout << "Дополнительный урон: " << magicWeapon2.getAdditionalDamage() << endl;
    cout << "Общий урон: " << magicWeapon2.getTotalDamage() << endl;
    
    // Проверка типа оружия
    cout << "Тип: ";
    if (magicWeapon2.getType() == WeaponType::ONEHANDED) {
        cout << "Одноручное оружие";
    } else if (magicWeapon2.getType() == WeaponType::TWOHANDED) {
        cout << "Двуручное оружие";
    } else if (magicWeapon2.getType() == WeaponType::BOW) {
        cout << "Лук";
    } else if (magicWeapon2.getType() == WeaponType::CROSSBOW) {
        cout << "Арбалет";
    }
    cout << endl;
    
    return 0;

}   
