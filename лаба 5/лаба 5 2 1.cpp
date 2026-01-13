#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// 1. Абстрактный класс Weapon с чисто виртуальной функцией Attack
class Weapon {
protected:
    string name;    // название оружия
    int damage;     // наносимый урон
    float weight;   // вес оружия

public:
    // Конструкторы
    Weapon(string weaponName, int weaponDamage, float weaponWeight) 
        : name(weaponName), damage(weaponDamage), weight(weaponWeight) {
        cout << "Создано оружие: " << name << endl;
    }
    
    Weapon() : Weapon("Стандартное оружие", 10, 2.5) {}
    
    virtual ~Weapon() {
        cout << "Деструктор Weapon: " << name << " удален" << endl;
    }
    
    // 1. Чисто виртуальная функция, делающая класс абстрактным
    virtual void Attack() = 0;
    
    // GET-методы
    string getName() const { return name; }
    int getDamage() const { return damage; }
    float getWeight() const { return weight; }
    
    // SET-метод для урона
    void setDamage(int newDamage) { 
        damage = newDamage; 
        cout << "Урон оружия " << name << " изменен на: " << damage << endl;
    }
    
    // Метод для вывода информации
    void printInfo() const {
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
    }
};

// 2. Класс магического оружия
class MagicWeapon : public Weapon {
private:
    int magicPower; // дополнительная магическая сила
    
public:
    MagicWeapon(string weaponName, int weaponDamage, float weaponWeight, int magicPower)
        : Weapon(weaponName, weaponDamage, weaponWeight), magicPower(magicPower) {
        cout << "Это магическое оружие с силой: " << magicPower << endl;
    }
    
    // 2. Реализация функции Attack для магического оружия
    void Attack() override {
        cout << "Атакуем магическим оружием \"" << name << "\"!" << endl;
        cout << "Нанесен магический урон: " << damage + magicPower << endl;
    }
    
    // Дополнительные методы для магического оружия
    int getMagicPower() const { return magicPower; }
    void setMagicPower(int power) { magicPower = power; }
};

// 5. Класс одноразового оружия
class DisposableWeapon : public Weapon {
private:
    // 6. Флаг использования оружия
    bool isUsed;
    
public:
    DisposableWeapon(string weaponName, int weaponDamage, float weaponWeight)
        : Weapon(weaponName, weaponDamage, weaponWeight), isUsed(false) {
        cout << "Это одноразовое оружие" << endl;
    }
    
    // 7. Реализация функции Attack для одноразового оружия
    void Attack() override {
        if (isUsed) {
            cout << "Оружие \"" << name << "\" уже было использовано!" << endl;
        } else {
            cout << "Атакуем одноразовым оружием \"" << name << "\"!" << endl;
            cout << "Нанесен урон: " << damage << endl;
            isUsed = true;
            cout << "Оружие израсходовано!" << endl;
        }
    }
    
    // Метод для сброса состояния (если нужно)
    void reset() {
        isUsed = false;
        cout << "Оружие \"" << name << "\" сброшено, можно использовать снова" << endl;
    }
    
    // GET-метод для флага использования
    bool getIsUsed() const { return isUsed; }
};

// 9. Шаблонный класс для хранения оружия в обеих руках
template<typename TLeft, typename TRight>
class TwoHands {
private:
    TLeft* leftHand;   // оружие в левой руке
    TRight* rightHand; // оружие в правой руке
    
public:
    // 10. Конструктор
    TwoHands(TLeft* left = nullptr, TRight* right = nullptr) 
        : leftHand(left), rightHand(right) {
        cout << "Созданы две руки с оружием" << endl;
    }
    
    ~TwoHands() {
        cout << "Деструктор TwoHands" << endl;
    }
    
    // 10. GET-методы
    TLeft* getLeftHand() const { return leftHand; }
    TRight* getRightHand() const { return rightHand; }
    
    // 10. SET-методы
    void setLeftHand(TLeft* weapon) { 
        leftHand = weapon; 
        cout << "Установлено оружие в левую руку" << endl;
    }
    
    void setRightHand(TRight* weapon) { 
        rightHand = weapon; 
        cout << "Установлено оружие в правую руку" << endl;
    }
    
    // Метод для атаки обоими руками
    void attackWithBothHands() {
        cout << "\n=== Атака двумя руками ===" << endl;
        
        if (leftHand) {
            cout << "Левая рука: ";
            leftHand->Attack();
        } else {
            cout << "В левой руке нет оружия" << endl;
        }
        
        if (rightHand) {
            cout << "Правая рука: ";
            rightHand->Attack();
        } else {
            cout << "В правой руке нет оружия" << endl;
        }
    }
    
    // Метод для вывода информации о оружии в руках
    void printWeaponsInfo() const {
        cout << "\n=== Оружие в руках ===" << endl;
        
        if (leftHand) {
            cout << "Левая рука: " << leftHand->getName() 
                 << " (урон: " << leftHand->getDamage() << ")" << endl;
        } else {
            cout << "Левая рука: пуста" << endl;
        }
        
        if (rightHand) {
            cout << "Правая рука: " << rightHand->getName() 
                 << " (урон: " << rightHand->getDamage() << ")" << endl;
        } else {
            cout << "Правая рука: пуста" << endl;
        }
    }
};

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    cout << "=== Демонстрация абстрактного класса Weapon ===\n" << endl;
    
    // 3. Попытка создать экземпляр абстрактного класса (раскомментируйте для проверки)
    /*
    Weapon weapon; // Ошибка компиляции: cannot declare variable 'weapon' 
                   // to be of abstract type 'Weapon'
    */
    
    cout << "1. Создание экземпляра абстрактного класса невозможно (закомментировано)" << endl;
    
    // 4. Создание экземпляра магического оружия
    cout << "\n2. Создание магического оружия:" << endl;
    MagicWeapon* magicStaff = new MagicWeapon("Посох огня", 15, 2.0, 10);
    
    // 4. Вызов метода Attack у магического оружия
    cout << "\n3. Атака магическим оружием:" << endl;
    magicStaff->Attack();
    
    // 8. Создание экземпляра одноразового оружия
    cout << "\n4. Создание одноразового оружия:" << endl;
    DisposableWeapon* throwingKnife = new DisposableWeapon("Метательный нож", 25, 0.5);
    
    // 8. Дважды вызываем метод Attack
    cout << "\n5. Первая атака одноразовым оружием:" << endl;
    throwingKnife->Attack();
    
    cout << "\n6. Вторая атака одноразовым оружием:" << endl;
    throwingKnife->Attack();
    
    // 11. Проверка шаблона класса TwoHands с типами оружия
    cout << "\n\n=== Проверка шаблонного класса TwoHands ===\n" << endl;
    
    // Создаем еще одно оружие
    MagicWeapon* magicSword = new MagicWeapon("Магический меч", 20, 3.0, 5);
    
    // 11. Создаем экземпляр TwoHands с типами Weapon
    cout << "7. Создание TwoHands с объектами Weapon:" << endl;
    TwoHands<MagicWeapon, DisposableWeapon>* warriorHands = 
        new TwoHands<MagicWeapon, DisposableWeapon>(magicSword, throwingKnife);
    
    warriorHands->printWeaponsInfo();
    
    // Атакуем двумя руками
    warriorHands->attackWithBothHands();
    
    // 11. Проверка шаблона с целыми числами (например, ID оружия)
    cout << "\n\n8. Проверка TwoHands с целыми числами (ID оружия):" << endl;
    
    TwoHands<int, int>* idHands = new TwoHands<int, int>(new int(1001), new int(1002));
    
    cout << "ID в левой руке: " << *idHands->getLeftHand() << endl;
    cout << "ID в правой руке: " << *idHands->getRightHand() << endl;
    
    // Меняем ID
    cout << "\n9. Изменение ID оружия:" << endl;
    *idHands->getLeftHand() = 1003;
    idHands->setRightHand(new int(1004));
    
    cout << "Новый ID в левой руке: " << *idHands->getLeftHand() << endl;
    cout << "Новый ID в правой руке: " << *idHands->getRightHand() << endl;
    
    // 11. Проверка с разными типами данных
    cout << "\n\n10. Проверка TwoHands с разными типами данных:" << endl;
    
    TwoHands<string, int>* mixedHands = new TwoHands<string, int>(
        new string("Лук и стрелы"), 
        new int(150)
    );
    
    cout << "Оружие в левой руке: " << *mixedHands->getLeftHand() << endl;
    cout << "Урон в правой руке: " << *mixedHands->getRightHand() << endl;
    
    // Очистка памяти
    cout << "\n\n=== Очистка памяти ===" << endl;
    
    delete magicStaff;
    delete throwingKnife;
    delete warriorHands;
    delete magicSword;
    delete idHands;
    delete mixedHands;
    
    cout << "\nПрограмма завершена успешно!" << endl;
    
    return 0;
}