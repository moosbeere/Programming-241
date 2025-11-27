#pragma once
#include "Monster.h"
class FlyMonster final:
    public Monster
{
public:
    FlyMonster(string name, double health, float maxHealth, float damage, float flySpeed);
    FlyMonster();
    void fly();
    float getFlySpeed();
    void print() override;
    FlyMonster operator +(FlyMonster& m2);
    bool operator ==(FlyMonster& m2);
    bool operator !=(FlyMonster& m2);


private:
    float flySpeed;

};

