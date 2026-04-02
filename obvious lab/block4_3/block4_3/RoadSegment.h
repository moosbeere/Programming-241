#pragma once
class RoadSegment
{
private:
	float length;
	int maxAllowedSpeed;
public:
	RoadSegment(float len, int maxAlSp);

	float getlength()const;
	int getMaxAllowedSpeed() const;

	void Info();

};

