// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Monster {
public:
	//Monster() {
	//	name = "Goblin";
	//	health = 4;
	//	damage = 7;
	//};
	//Monster(string name, float health, float damage) {
	//	this->name = name;
	//	this->damage = damage;
	//	this->health = health;
	//}
	// 
	//сокращенная запись конструктора выше
	Monster(string name, float health, float damage) :name(name), health(health), damage(damage) {};
	//вызов коснтруктора со значениями по умолчанию из конструктора более общего
	Monster() :Monster("Goblin", 6, 8) {};

	string name;
	float health;
	float damage;
};

int main()
{
	//Monster m;
	//m.name = "Monster";
	//m.health = 10;
	//m.damage = 4;
	Monster m = Monster("Goblin", 9, 3);
	Monster* pm = &m; //создание указателя на объект
	cout << m.name << ": health = " << m.health << ", damage = " << m.damage << endl;
	cout << pm->name << ": P health = " << pm->health << ", P damage = " << pm->damage << endl;//используется стрелочная нотация
	//Создание объекта с помощью ключевого слова new
	Monster* nMonster = new Monster("new", 8, 9);
	cout << nMonster->name << ": N health = " << nMonster->health << ", N damage = " << nMonster->damage << endl;
	delete nMonster; //удаление динамического объекта
	Monster dMonster;
	cout << dMonster.name << ": D health = " << dMonster.health << ", D damage = " << dMonster.damage << endl;
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
