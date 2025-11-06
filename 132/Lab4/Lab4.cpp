// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Monster {
public:
    string name;
    float health;
    float damage;
    int* i = new int(5);
    //конструктор первый способ задания
    //Monster() {
    //    name = "Monster";
    //    health = 4;
    //    damage = 7;
    //}
    //конструктор второй способ задания
    //Monster(string name, float health, float damage) {
    //    this->name = name;
    //    this->health = health;
    //    this->damage = damage;
    //}
    Monster(string name, float health, float damage) :name(name), health(health), damage(damage) {};
    Monster():Monster("default", 1, 1) {};
    ~Monster() {
        cout << name << " destroy" << endl;
        delete i;
    }
};

int main()
{
    //второй способ инициализации объекта
    Monster M = Monster("Goblin", 5, 6);
    cout << M.name << " " << M.health << " " << M.damage << endl;

    if (true) {
        Monster m7;
        //Monster* nemM2 = new Monster();
    }

    Monster copyM = M;
    cout << copyM.name << " " << copyM.health << " " << copyM.damage << endl;
    copyM.name = "CopyMonster";
    cout << M.name << " " << M.health << " " << M.damage << endl;

    Monster& hM = M;
    hM.name = "href";
    cout << M.name << " " << M.health << " " << M.damage << endl;


    Monster* pM = &M;
    cout << pM->name << " " << pM->health << " " << pM->damage << endl;

    Monster* newM = new Monster("newMonster", 8, 9);
    cout << newM->name << " " << newM->health << " " << newM->damage << endl;
    delete newM;

    Monster d;
    cout << d.name << " " << d.health << " " << d.damage << endl;

    //первые способыинициализации объекта
   /* Monster m;
    m.damage = 7;
    m.health = 8;
    m.name = "Goblin";
    cout << m.name << " " << m.health << " " << m.damage << endl;
    Monster m1;
    cout << m1.name << " " << m1.health << " " << m1.damage << endl;*/

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
