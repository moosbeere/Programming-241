#include "AIMonster.h"

void AIMonster::move(Monster* m)
{
	if (m->health > 0) std::cout << m->name << "is moving...\n";
	else std::cout << m->name << " died!";
}
