#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// Перечисление типов оружия
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
    WeaponType type;
    
public:
    // Конструкторы
    Weapon() : name("Безымянное"), damage(10), type(WeaponType::ONEHANDED) {}
    
    Weapon(string n, int d, WeaponType t) : name(n), damage(d), type(t) {}
    
    // GET-методы
    string getName() const { return name; }
    
    // 1. Сделаем метод виртуальным
    virtual int getDamage() const { return damage; }
    
    WeaponType getType() const { return type; }
    
    // 4. Переопределим операторы сравнения
    bool operator>(const Weapon& other) const {
        return this->getDamage() > other.getDamage();
    }
    
    bool operator<(const Weapon& other) const {
        return this->getDamage() < other.getDamage();
    }
};

// Дочерний класс магического оружия
class MagicWeapon : public Weapon {
private:
    int additionalDamage;
    
public:
    // Конструкторы
    MagicWeapon() : Weapon(), additionalDamage(5) {}
    
    MagicWeapon(string n, int d, WeaponType t, int addDmg) 
        : Weapon(n, d, t), additionalDamage(addDmg) {}
    
    // GET-метод для дополнительного урона
    int getAdditionalDamage() const { return additionalDamage; }
    
    // 2. Переопределяем виртуальный метод getDamage()
    virtual int getDamage() const override {
        // 3. Возвращаем сумму базового урона и дополнительного
        return Weapon::getDamage() + additionalDamage;
    }
};

// Структура игрока
struct Player {
    int id;
    string login;
    string password;
    
    void printInfo() const {
        cout << "ID: " << id << endl;
        cout << "Логин: " << login << endl;
        cout << "Пароль: " << password << endl;
    }
};

int main() {
    // Установка русской локали
    setlocale(LC_ALL, "Russian");
    
    cout << "=== Тестирование виртуального метода getDamage() ===" << endl;
    
    // Создание обычного оружия
    Weapon sword("Меч", 15, WeaponType::ONEHANDED);
    cout << "Обычное оружие: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl << endl;
    
    // Создание магического оружия
    MagicWeapon magicSword("Магический меч", 15, WeaponType::ONEHANDED, 10);
    cout << "Магическое оружие: " << magicSword.getName() << endl;
    cout << "Базовый урон: " << magicSword.Weapon::getDamage() << endl;
    cout << "Дополнительный урон: " << magicSword.getAdditionalDamage() << endl;
    cout << "Общий урон (через getDamage()): " << magicSword.getDamage() << endl;
    
    // 3. Проверка, что метод возвращает сумму
    if (magicSword.getDamage() == (magicSword.Weapon::getDamage() + magicSword.getAdditionalDamage())) {
        cout << "✓ Метод getDamage() корректно возвращает сумму уронов" << endl;
    } else {
        cout << "✗ Ошибка: метод getDamage() возвращает неверное значение" << endl;
    }
    
    cout << endl << "=== Тестирование операторов сравнения ===" << endl;
    
    // Создаем различные виды оружия для сравнения
    Weapon dagger("Кинжал", 8, WeaponType::ONEHANDED);
    Weapon battleAxe("Боевой топор", 25, WeaponType::TWOHANDED);
    MagicWeapon fireStaff("Огненный посох", 12, WeaponType::TWOHANDED, 15);
    MagicWeapon iceBow("Ледяной лук", 10, WeaponType::BOW, 8);
    
    // Сравнение обычного оружия
    cout << "Сравнение обычного оружия:" << endl;
    cout << dagger.getName() << " (" << dagger.getDamage() << " урона) и "
         << battleAxe.getName() << " (" << battleAxe.getDamage() << " урона)" << endl;
    
    if (dagger < battleAxe) {
        cout << dagger.getName() << " слабее, чем " << battleAxe.getName() << endl;
    }
    
    if (dagger > battleAxe) {
        cout << dagger.getName() << " сильнее, чем " << battleAxe.getName() << endl;
    }
    
    // Сравнение магического и обычного оружия
    cout << endl << "Сравнение магического и обычного оружия:" << endl;
    cout << battleAxe.getName() << " (" << battleAxe.getDamage() << " урона) и "
         << fireStaff.getName() << " (" << fireStaff.getDamage() << " урона)" << endl;
    
    if (battleAxe < fireStaff) {
        cout << battleAxe.getName() << " слабее, чем " << fireStaff.getName() << endl;
    } else if (battleAxe > fireStaff) {
        cout << battleAxe.getName() << " сильнее, чем " << fireStaff.getName() << endl;
    } else {
        cout << "Оружие равны по силе" << endl;
    }
    
    // Сравнение двух магических оружий
    cout << endl << "Сравнение двух магических оружий:" << endl;
    cout << fireStaff.getName() << " (" << fireStaff.getDamage() << " урона) и "
         << iceBow.getName() << " (" << iceBow.getDamage() << " урона)" << endl;
    
    if (fireStaff > iceBow) {
        cout << fireStaff.getName() << " сильнее, чем " << iceBow.getName() << endl;
    } else if (fireStaff < iceBow) {
        cout << fireStaff.getName() << " слабее, чем " << iceBow.getName() << endl;
    } else {
        cout << "Оружие равны по силе" << endl;
    }
    
    // Сравнение через указатель на базовый класс (полиморфизм)
    cout << endl << "=== Тестирование полиморфизма ===" << endl;
    Weapon* weaponPtr;
    
    // Указываем на обычное оружие
    weaponPtr = &sword;
    cout << "Обычное оружие через указатель: " << weaponPtr->getDamage() << " урона" << endl;
    
    // Указываем на магическое оружие
    weaponPtr = &magicSword;
    cout << "Магическое оружие через указатель: " << weaponPtr->getDamage() << " урона" << endl;
    cout << "Примечание: вызывается переопределенный метод из MagicWeapon" << endl;
    
    // Демонстрация полиморфного сравнения
    cout << endl << "=== Полиморфное сравнение через указатели ===" << endl;
    Weapon* weapon1 = &battleAxe;
    Weapon* weapon2 = &fireStaff;
    
    if (*weapon1 > *weapon2) {
        cout << weapon1->getName() << " сильнее, чем " << weapon2->getName() << endl;
    } else if (*weapon1 < *weapon2) {
        cout << weapon1->getName() << " слабее, чем " << weapon2->getName() << endl;
    }
    
    // Создаем массив оружия и сортируем по урону
    cout << endl << "=== Список оружия, отсортированный по урону ===" << endl;
    Weapon* weapons[] = {&dagger, &battleAxe, &fireStaff, &iceBow};
    int size = 4;
    
    // Простая сортировка пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*weapons[j] > *weapons[j + 1]) {
                Weapon* temp = weapons[j];
                weapons[j] = weapons[j + 1];
                weapons[j + 1] = temp;
            }
        }
    }
    
    // Выводим отсортированный список
    for (int i = 0; i < size; i++) {
        cout << i+1 << ". " << weapons[i]->getName() << " - " 
             << weapons[i]->getDamage() << " урона" << endl;
    }
    
    // Тестирование структуры Player
    cout << endl << "=== Тестирование структуры Player ===" << endl;
    Player player;
    player.id = 1;
    player.login = "маг123";
    player.password = "secret123";
    player.printInfo();
    
    return 0;
}