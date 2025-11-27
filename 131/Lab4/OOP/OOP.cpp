// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Monster {
public:
    string name;
    float health;
    float maxHealth;
    float damage;

    Monster(string name, float health, float maxHealth, float damage):name(name), health(health), maxHealth(maxHealth), damage(damage) {}
    Monster():Monster("Goblin", 4, 7, 4) {}

    float getLevel() {
        return maxHealth/5;
    }

    void applyDamage(float damage) {
        health -= damage;
    }
    void applyDamage() {
        applyDamage(1);
    }

    ~Monster() {
        cout << "Объект " << name << " уничтожается!";
    };
};

int main()
{
    setlocale(LC_ALL, "RU");
    Monster m;
    m.applyDamage();
    cout << m.getLevel() << endl;
    cout << m.health << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
