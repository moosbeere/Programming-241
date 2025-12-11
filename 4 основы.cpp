#include <iostream>
#include <string>

using namespace std;

class weapon {
private:
    string name;   
    int damage;     
    float weight;  

public:

    weapon(string weaponName, int weaponDamage, float weaponWeight) {
        name = weaponName;
        damage = weaponDamage;
        weight = weaponWeight;
    }


    weapon() : weapon("Меч-кладенец", 15, 3.5f) {

    }

    void displayInfo() {
        cout << "Оружие: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    
    setlocale(LC_ALL, "RUS");

    weapon sword("Огненный меч", 25, 4.2f);

    weapon defaultweapon;

    cout << "=== Первое оружие (создано с параметрами) ===" << endl;
    sword.displayInfo();

    cout << "=== Второе оружие (создано без параметров) ===" << endl;
    defaultweapon.displayInfo();

    return 0;
}

//2 задание
#include <iostream>
#include <string>

using namespace std;

class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    Weapon(string weaponName, int weaponDamage, float weaponWeight)
        : name(weaponName), damage(weaponDamage), weight(weaponWeight) {
        cout << "Создано оружие: " << name << endl;
    }

    Weapon() : Weapon("Меч-кладенец", 15, 3.5f) {}

    ~Weapon() {
        cout << "\n=== Деструктор ===" << endl;
        cout << "Удаляется оружие:" << endl;
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
        cout << "==================" << endl;
    }

    void displayInfo() {
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
    }

    bool canLift(float maxWeight) {
        if (weight > maxWeight) {
            return true;
        }
        else {
            return false;
        }
    }

    float totalWeight(const Weapon& otherWeapon) {
        return totalWeight(otherWeapon.weight);
    }

    float totalWeight(float additionalWeight) {
        return weight + additionalWeight;
    }
};

int main() {
    cout << "=== Часть 1: Статический объект ===" << endl;

    Weapon staticWeapon("Огненный меч", 25, 4.2f);

    cout << "\nДанные статического оружия:" << endl;
    staticWeapon.displayInfo();

    cout << "\n=== Часть 2: Динамический объект ===" << endl;

    Weapon* dynamicWeapon = new Weapon("Ледяной лук", 18, 2.8f);

    cout << "\nДанные динамического оружия:" << endl;
    dynamicWeapon->displayInfo();

    cout << "\n=== Проверка метода canLift() ===" << endl;
    cout << "Статическое оружие (вес: 4.2 кг):" << endl;
    cout << "Максимальный вес 3.0 кг: "
        << (staticWeapon.canLift(3.0f) ? "Слишком тяжело!" : "Можно поднять") << endl;
    cout << "Максимальный вес 5.0 кг: "
        << (staticWeapon.canLift(5.0f) ? "Слишком тяжело!" : "Можно поднять") << endl;

    cout << "\n=== Проверка методов totalWeight() ===" << endl;

    Weapon weapon1("Тяжелый молот", 35, 8.5f);
    Weapon weapon2("Легкий кинжал", 12, 1.2f);

    cout << "Суммарный вес молота и кинжала: "
        << weapon1.totalWeight(weapon2) << " кг" << endl;

    cout << "Вес молота + дополнительный вес 2.3 кг: "
        << weapon1.totalWeight(2.3f) << " кг" << endl;

    cout << "Вес кинжала + дополнительный вес 0.5 кг: "
        << weapon2.totalWeight(0.5f) << " кг" << endl;

    cout << "\n=== Удаление динамического объекта ===" << endl;
    delete dynamicWeapon;

    cout << "\n=== Конец программы ===" << endl;

    return 0;
}

//4 задание
#include <iostream>
#include <string>

using namespace std;

class Characteristic;

class Weapon {
private: 
    string name;
    int damage;
    float weight;

public:

    Weapon(string weaponName, int weaponDamage, float weaponWeight)
        : name(weaponName), damage(weaponDamage), weight(weaponWeight) {
        cout << "Создано оружие: " << name << endl;
    }

    Weapon() : Weapon("Меч-кладенец", 15, 3.5f) {}

    ~Weapon() {
        cout << "\n=== Деструктор ===" << endl;
        cout << "Удаляется оружие:" << endl;
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
        cout << "==================" << endl;
    }

    string getName() const { return name; }     
    int getDamage() const { return damage; }    
    float getWeight() const { return weight; }   

    void setDamage(int newDamage) {
        if (newDamage < 0) {
            cout << "Ошибка: урон не может быть отрицательным!" << endl;
            return;
        }
        damage = newDamage;
        cout << "Урон оружия '" << name << "' изменен на: " << damage << endl;
    }

    void displayInfo() const {
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
    }

    bool canLift(float maxWeight) const {
        return weight > maxWeight;
    }

    float totalWeight(const Weapon& otherWeapon) const {
        return totalWeight(otherWeapon.weight);
    }

    float totalWeight(float additionalWeight) const {
        return weight + additionalWeight;
    }

    friend class Characteristic;
};

class Characteristic {
private:
    int strength;

public:
    Characteristic(int str) : strength(str) {
        cout << "Создана характеристика с силой: " << strength << endl;
    }

    int getDamage(const Weapon& weapon) const {  
        return strength + weapon.damage;
    }
};

class MyMath {
private:
    static int callCount;  

public:
    static int add(int a, int b) {
        callCount++;
        return a + b;
    }

    static int sub(int a, int b) {
        callCount++;
        return a - b;
    }

    static int mult(int a, int b) {
        callCount++;
        return a * b;
    }

    static float div(int a, int b) {
        callCount++;
        if (b == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return 0;
        }
        return static_cast<float>(a) / b;
    }

    static int getCallCount() {
        return callCount;
    }
};

int MyMath::callCount = 0;

int main() {
    cout << "=== Тестирование Weapon с GET/SET методами ===" << endl;

    Weapon sword("Огненный меч", 25, 4.2f);

    cout << "\n--- GET-методы ---" << endl;
    cout << "Название: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl;
    cout << "Вес: " << sword.getWeight() << " кг" << endl;

    cout << "\n--- SET-метод для урона ---" << endl;
    sword.setDamage(35);
    cout << "Новый урон (через GET): " << sword.getDamage() << endl;

    cout << "\n--- Попытка установить отрицательный урон ---" << endl;
    sword.setDamage(-5);

    cout << "\n=== Тестирование Characteristic и дружественности ===" << endl;

    Characteristic hero(10);

    Weapon bow("Лук охотника", 15, 2.0f);
    int totalDamage = hero.getDamage(bow);
    cout << "\nОбщий урон (сила " << hero.getDamage(bow) - bow.getDamage()
        << " + урон лука " << bow.getDamage() << "): " << totalDamage << endl;

    Weapon axe("Топор варвара", 30, 6.0f);
    totalDamage = hero.getDamage(axe);
    cout << "Общий урон с топором: " << totalDamage << endl;

    cout << "\n=== Тестирование MyMath со статическими методами ===" << endl;

    cout << "Сложение: 10 + 5 = " << MyMath::add(10, 5) << endl;
    cout << "Вычитание: 10 - 5 = " << MyMath::sub(10, 5) << endl;
    cout << "Умножение: 10 * 5 = " << MyMath::mult(10, 5) << endl;
    cout << "Деление: 10 / 5 = " << MyMath::div(10, 5) << endl;

    cout << "\nЕще вызовы:" << endl;
    cout << "add(20, 30) = " << MyMath::add(20, 30) << endl;
    cout << "sub(50, 25) = " << MyMath::sub(50, 25) << endl;

    cout << "\n=== Проверка счетчика вызовов ===" << endl;
    cout << "Всего вызовов методов MyMath: " << MyMath::getCallCount() << endl;

    cout << "\nПроверка деления на ноль:" << endl;
    cout << "10 / 0 = " << MyMath::div(10, 0) << endl;

    cout << "\nФинальное значение счетчика: " << MyMath::getCallCount() << endl;
    cout << "(Должно быть 8: 4 первых + 2 дополнительных + 1 деление на ноль + 1 getCallCount)" << endl;

    return 0;
}