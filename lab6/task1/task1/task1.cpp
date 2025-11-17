#include <iostream>
#include <string>
#include "MyException.cpp";

int main()
{

	try {

		std::cout << "Please input a number" << std::endl;
		int n;
		std::cin >> n;
		if (n == 1) std::cout << "One" << std::endl;
		else if (n == 2) std::cout << "Two" << std::endl;
		else if (n == 3) std::cout << "Tree" << std::endl;
		else throw "Exception: Incorrect number!";
		std::cout << "Input your birth year";
		int date;
		std::cin >> date;
		if (date < 1850) throw std::exception("It is not true");
		else if (date > 2025) throw std::logic_error("You are not born yet.");
		else if (date < 0) throw std::logic_error("You enterered a negative number");
		std::cout << "Thank you, everything's good.";

		/* Using MyException class */
		std::cout << "Input your birth year again" << std::endl;
		std::cin >> date;
		if (date < 0) throw MyException(DateError::NEGATIVE);
		else if (date < 1850) throw MyException(DateError::EARLY);
		else if (date > 2025) throw MyException(DateError::LATE);
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}
	catch (std::logic_error e)
	{
		std::cout << "Logic Error: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

}