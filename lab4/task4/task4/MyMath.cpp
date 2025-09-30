#include "MyMath.h"
int MyMath::counter = 0;
float MyMath::Add(float n1, float n2)
{
	MyMath::counter++;
	return (n1 + n2);
}
float MyMath::Sub(float n1, float n2)
{
	MyMath::counter++;
	return (n1 - n2);
}

float MyMath::Mult(float n1, float n2)
{
	MyMath::counter++;
	return (n1 * n2);
}

float MyMath::Div(float n1, float n2)
{
	MyMath::counter++;
	return (n1 / n2);
}