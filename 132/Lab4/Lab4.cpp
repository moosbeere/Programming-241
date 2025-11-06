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
	Monster(string name, float maxHealth, float health, float damage) :name(name), maxHealth(maxHealth), health(health), damage(damage) {};
	//вызов коснтруктора со значениями по умолчанию из конструктора более общего
	Monster() :Monster("Goblin", 6, 4, 8) {};

	int* i = new int(5);
	~Monster() {
		cout << "Object for name: " << this->name << " destroy" << endl;
		delete i;
	}

	string name;
	float health;
	float damage;
	float maxHealth;

	float getMaxHealth() {
		return this->maxHealth;
	}

	void applyDamage(float damage) {
		this->health -= damage;
	}

	void applyDamage() {
		applyDamage(1);
	}

	void recovery() {
		this->health = maxHealth;
	}

	//void attack(Monster* m) {
	//	m->applyDamage(damage);
	//}

	void attack(const Monster &m) {
		m.applyDamage(damage);
	}
};

int main()
{
	//Методы и их перегрузка
	Monster m1("Goblin", 6, 6, 4);
	Monster m2("Monster", 10, 6, 4);

	cout << m1.name << " " << m1.getMaxHealth() << endl;
	cout << m2.name << " " << m2.getMaxHealth() << endl;

	m2.applyDamage(4);
	cout << m2.name << " " << m2.health << endl;

	m2.applyDamage();
	cout << m2.name << " " << m2.health << endl;

	m2.recovery();
	cout << m2.name << " " << m2.health << endl;
	//m2.attack(&m1); передаем через ссылку, так как в функции входной параметр указатель
	m2.attack(m1);
	cout << m1.name << " " << m1.health << endl;




	//Monster m;
	//m.name = "Monster";
	//m.health = 10;
	//m.damage = 4;
	//Monster m = Monster("Goblin", 9, 3);
	//Monster* pm = &m; //создание указателя на объект
	//cout << m.name << ": health = " << m.health << ", damage = " << m.damage << endl;
	//cout << pm->name << ": P health = " << pm->health << ", P damage = " << pm->damage << endl;//используется стрелочная нотация
	////Создание объекта с помощью ключевого слова new
	//Monster* nMonster = new Monster("new", 8, 9);

	//if (true) {
	//	Monster m3("mDelete", 5, 3);
	//}

	//cout << nMonster->name << ": N health = " << nMonster->health << ", N damage = " << nMonster->damage << endl;
	//delete nMonster; //удаление динамического объекта
	//Monster dMonster;
	//cout << dMonster.name << ": D health = " << dMonster.health << ", D damage = " << dMonster.damage << endl;
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
