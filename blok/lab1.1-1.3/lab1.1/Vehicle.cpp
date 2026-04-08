#include "Vehicle.h"
using namespace std;




Vehicle::Vehicle(string b, float m) : brand(b), maxSpeed(m) {}

void Vehicle::accelerate(int increment)
{
	if (increment + currentSpeed <= maxSpeed) {
		currentSpeed += increment;
	}
	else 
	{
		cout << "ОШИБКА: скорость нельзя увеличить на " << increment << ", она будет выше макисмальной скорости - " << maxSpeed << endl;
	}
}

void Vehicle::brake(int decrement)
{
	if (currentSpeed - decrement >= 0) {
		currentSpeed -= decrement;
	}
	else
	{
		cout << "ОШИБКА: скорость нельзя уменьшить на " << decrement << ", она будет меньше 0" << endl;
	}
}

void Vehicle::getStatus()
{
	cout << "Бренд:" << brand << ", Максимальная скорость: " << maxSpeed << ", текущая скорость: " << currentSpeed << endl;
}
