#include "Route.h"
#include <iostream>

Route::Route(string start, string end, int len) : startPoint(start), endPoint(end), length(len) {}

void Route::PrintInfo()
{
	cout << "Маршрут: " << startPoint << " - " << endPoint << ". Расстояние - " << length << endl;
}

double Route::getLen()
{
	return length;
}
