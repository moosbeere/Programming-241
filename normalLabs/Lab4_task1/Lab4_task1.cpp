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

    void printInfo()
    {
        cout << "\nИмя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    Weapon sword("Меч", 25, 2);
    Weapon staff;
    sword.printInfo();
    staff.printInfo();
}