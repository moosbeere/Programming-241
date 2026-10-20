#include "Route.h"

Route::Route(std::string startPoint, std::string endPoint, int length):startPoint(startPoint), endPoint(endPoint), length(length)
{
}

void Route::printInfo()
{
	std::cout << "startPoint: " << startPoint
		<< "\nendPoint: " << endPoint
		<< "\nLength: " << length << " km\n";
}

int Route::getLength()
{
	return length;
}
