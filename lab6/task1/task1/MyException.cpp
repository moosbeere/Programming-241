//#include "MyException.h"
#include <iostream>


enum class DateError
{
	NEGATIVE,
	EARLY,
	LATE
};


class MyException : public std::exception
{
private:
	DateError code;
public:
	MyException(DateError code) : code(code) {};
	const char* what() const noexcept override
	{
		if (code == DateError::NEGATIVE) return "Year can not be negative.";
		else if (code == DateError::EARLY) return "Year can not be less 1850";
		else if (code == DateError::LATE) return "Incorrect input";
		else return "Unknown Error!!!";
	}
};
