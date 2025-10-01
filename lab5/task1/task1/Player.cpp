#include <iostream>
#include <string>


struct Player
{
	int id;
	std::string login;
	std::string password;

	void print()
	{
		std::cout << "id=" << id << " login=" << login << " password =" << password;
	}
};