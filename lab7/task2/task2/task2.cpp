#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include <fstream>

bool validName(std::string s)
{
	std::regex reg("[A-Z][a-z]{1,31}");
	return (std::regex_match(s, reg) && std::isupper(s[0]));
}

//std::vector<std::string> findLinks(std::string s)
//{
//
//}

int main()
{
	std::string name;
	std::cout << "Input your name:" << std::endl;
	std::cin >> name;
	if (validName(name))
		std::cout << "The name is correct." << std::endl;
	else
		std::cout << "name is incorrect" << std::endl;

	std::ifstream in("input.txt");
	std::string text;
	std::getline(in, text);
	std::smatch matches;
	//std::cout << "Input text with emails" << std::endl;  # Uncomment when text is not got from input.txt
	//std::cin >> text;
	std::regex reg(R"(\b[a-z0-9]{2,}@[a-z]{2,10}\.[a-z]{2,5}\b)", std::regex_constants::icase);

	while (std::regex_search(text, matches, reg))
	{
		std::cout << matches[0] << ' ' << matches[1] << std::endl;
		text = matches.suffix().str();
		//std::cout << text << std::endl;
	}


}