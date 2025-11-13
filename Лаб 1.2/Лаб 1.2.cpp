#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int x1 = 150;
	float x2 = 15.933;
	unsigned short x3 = 250;
	std::cout << "x1 = " << x1 << std::endl;
	std::cout << "x2 = " << x2 << std::endl;
	std::cout << "x3 = " << x3 << std::endl;

	int day = 23;
	std::string month = "июля";
	int year = 2006;
	std::cout << "Дата рождения: " << day << " " << month << " " << year << " года" << std::endl;

	const double n1 = 2.3;
	const std::string n2 = "WINDOWS";
	std::cout << n1 << " " << n2 << std::endl;

	return 0;
}