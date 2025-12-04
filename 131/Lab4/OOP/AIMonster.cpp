#include "AIMonster.h"

void AIMonster::move(Monster* m)
{
	if (m->health > 0) cout << m->name << " Monster is moving..\n";
	else cout << m->name << " Monster is died\n";
}
