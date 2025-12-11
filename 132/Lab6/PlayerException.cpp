#include "PlayerException.h"

const char* PlayerException::what() const throw()
{
	if (code == PlayerError::BIG) return "Health > 100";
	else if (code == PlayerError::NEGATIVE) return "Health < 0";
	else if (code == PlayerError::ZERO) return "Health = 0";
}
