#include <iostream>
#include "Weapon.h"


using namespace std;


// Конструктор с аргументами
Weapon::Weapon(string inputName, float inputDamage, float inputWeight)
{
    name = inputName;
    damage = inputDamage;
    weight = inputWeight;
}
// Пустой конструктор с дефолтными значениями
Weapon::Weapon() : Weapon("Посох", 1.00, 5.25) {}

Weapon::~Weapon() {
    cout << "Удаление оружия";
    printInfo();
}

string Weapon::getName() {
    return name;
}

float Weapon::getDamage() {
    return damage;
}

float Weapon::getWeight() {
    return weight;
}

void Weapon::setDamage(float newDamage) { damage = newDamage; }

void Weapon::printInfo()
{
    cout << "\nИмя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << endl;
}

bool Weapon::checkWeight(float maxWeight) {
    if (maxWeight > weight) { return true; }
    else { return false; }
}

// Аргумент выступает в виде ссылки на объект класса, потому что иначе срабатывает деконструктор на передаваемый элемент
int Weapon::newWeapon(Weapon& newItem) {
    return newWeapon(newItem.weight);
}
int Weapon::newWeapon(int newWeight) {
    return newWeight + weight;
}

Characteristic::Characteristic(float inputStrength) {
    strength = inputStrength;
}

float Characteristic::GetDamage(const Weapon& weapon) {
    return strength + weapon.damage;
}

int MyMath::Add(int a, int b) {
    staticMethodCount++;
    return a + b;
}
int MyMath::Sub(int a, int b) {
    staticMethodCount++;
    return a - b;
}
int MyMath::Mult(int a, int b) {
    staticMethodCount++;
    return a * b;
}
int MyMath::Div(int a, int b) {
    staticMethodCount++;
    return a / b;
}
int MyMath::getStaticCount() { return staticMethodCount; }


int MyMath::staticMethodCount = 0;


int main()
{
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 25, 2);
    sword.printInfo();

    Weapon axe("Топор", 15, 7);
    axe.printInfo();

    cout << "Вес " << sword.getName() << " + " << axe.getName() << " = " << sword.newWeapon(axe) << endl;

    Weapon* bow = new Weapon("Лук", 10, 0.1);
    bow->printInfo();
    delete bow;
    cout << endl;

    if (sword.checkWeight(3)) {
        cout << "Вес оружия: " << sword.getName() << " < 3" << endl;
    }
    else {
        cout << "Вес оружия: " << sword.getName() << " >= 3" << endl;
    }

    cout << "Перегрузка функцией принимающей просто вес = " << sword.newWeapon(10) << endl;

    cout << endl << "Проверка set запроса до:\nУрон меча = " << sword.getDamage() << endl;
    sword.setDamage(999);
    cout << "После:\nУрон меча = " << sword.getDamage() << endl;
    Characteristic hero(10);
    cout << "Урон наносимый героем с помощью топора = " << hero.GetDamage(axe) << endl;
    MyMath opers;
    cout << "Сложение с помощью MyMath: 2, 3 = " << opers.Add(2, 3) << endl;
    cout << "Вычитание с помощью MyMath: 2, 3 = " << opers.Sub(2, 3) << endl;
    cout << "Умножение с помощью MyMath: 2, 3 = " << opers.Mult(2, 3) << endl;
    cout << "Деление с помощью MyMath: 2, 3 = " << opers.Div(2, 3) << endl;
    cout << "Значение статической переменной после операций = " << opers.getStaticCount() << endl;
}