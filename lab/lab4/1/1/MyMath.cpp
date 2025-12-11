#include "MyMath.h"

float MyMath::Add(float a, float b)
{
	counter++;
	return a + b;
}

float MyMath::Sub(float a, float b)
{
	counter++;
	return a - b;
}

float MyMath::Div(float a, float b)
{
	counter++;
	return a * b;
}

float MyMath::Mult(float a, float b)
{
	counter++;
	return a / b;
}
