#include <iostream>


using namespace std;


class Weapon
{
public:
    string name;
    float damage;
    float weight;

    // Конструктор с аргументами
    Weapon(string inputName, float inputDamage, float inputWeight)
    {
        name = inputName;
        damage = inputDamage;
        weight = inputWeight;
    }
    // Пустой конструктор с дефолтными значениями
    Weapon() : Weapon("Посох", 1.00, 5.25) {

    }

    ~Weapon() {
        cout << "Удаление оружия";
        printInfo();
    }

    void printInfo()
    {
        cout << "\nИмя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << endl;
    }

    bool checkWeight(float maxWeight) {
        if (maxWeight > weight) { return true; }
        else { return false; }
    }

    // Аргумент выступает в виде ссылки на объект класса, потому что иначе срабатывает деконструктор на передаваемый элемент
    int newWeapon(Weapon& newItem) {
        return newWeapon(newItem.weight);
    }
    int newWeapon(int newWeight) {
        return newWeight + weight;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 25, 2);
    sword.printInfo();

    Weapon axe("Топор", 15, 7);
    axe.printInfo();

    cout << "Вес " << sword.name << " + " << axe.name << " = " << sword.newWeapon(axe) << endl;

    Weapon* bow = new Weapon("Лук", 10, 0.1);
    bow->printInfo();
    delete bow;
    cout << endl;

    if (sword.checkWeight(3)) {
        cout << "Вес оружия: " << sword.name << " < 3" << endl;
    }
    else {
        cout << "Вес оружия: " << sword.name << " >= 3" << endl;
    }

    cout << "Перегрузка функцией принимающей просто вес = " << sword.newWeapon(10) << endl;

}