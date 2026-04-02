#include "RoadSegment.h"
#include <iostream>
using namespace std;
RoadSegment::RoadSegment(float len, int maxAlSp):length(len), maxAllowedSpeed(maxAlSp)
{
}

float RoadSegment::getlength() const
{
	return length;
}

int RoadSegment::getMaxAllowedSpeed() const
{
	return maxAllowedSpeed;
}

void RoadSegment::Info()
{
	cout << "Участок дороги: длина (m) "<< length <<endl;
	cout << "Ограничения по скорости" << maxAllowedSpeed <<"км/ч" <<endl;
}

