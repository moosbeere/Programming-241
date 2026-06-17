#include <string>
#include <iostream>


int main()
{
	std::string str;
	std::cout << "Input some string" << std::endl;
	std::cin >> str;
	try
	{
		std::cout << str.substr(2, 3) << std::endl;
		int indx = str.find("a");
		if (indx > 0)
			std::cout << "The index of first 'a' entry in yours: " << indx << std::endl;
		else std::cout << "'a' string is not found." << std::endl;

	}
	catch (std::exception e)
	{
		std::cout << "Exception";
	}

}