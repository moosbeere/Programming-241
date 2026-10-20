#include "Route.h"

Route::Route(std::string startPoint, std::string endPoint, int length):startPoint(startPoint), endPoint(endPoint), length(length)
{
}

void Route::printInfo()
{
	std::cout << "Начало маршрута: " << startPoint << " Окончание маршрута: " << endPoint << " Длина маршрута: " << length << std::endl;
}

int Route::getLength()
{
	return length;
}
