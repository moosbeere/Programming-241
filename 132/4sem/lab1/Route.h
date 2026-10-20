#pragma once
#include <iostream>

class Route
{
private:
	std::string startPoint;
	std::string endPoint;
	int length;
public:
	Route(std::string startPoint, std::string endPoint, int length);
	void printInfo();
	int getLength();
};

