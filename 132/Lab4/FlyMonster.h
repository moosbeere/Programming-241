#pragma once
#include "Monster.h"
class FlyMonster :
    public Monster
{
public:
    FlyMonster(string name, float health, float maxHealth, float damage, float flySpeed);
    FlyMonster();
    void fly();
    float getFlySpeed();

private:
    float flySpeed;

};

