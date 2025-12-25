#include <fstream>
#include <cmath>
#include <string>
#include <iostream>
#include <functional>
#ifdef M_PI
const double PI = M_PI;
#else
const double PI = std::acos(-1.0);
#endif

constexpr unsigned int constHash(const char* str) {
	return *str ? static_cast<unsigned int>(*str) + 33 * constHash(str + 1) : 5381;
}

int main()
{
	/* Punct 1-3 */
	double n;
	double pi = PI;
	std::cout << "Input a radius of the circle" << std::endl;
	std::cin >> n;
	double circumFerence = std::trunc(n * 2 * 1000 * pi) / 1000;
	std::cout << circumFerence;

	/* Punct 4-8 */
	std::cout << "Input some string" << std::endl;
	std::fstream ofs("output.txt", std::ios::app);
	if (!ofs.is_open())
	{
		std::cout << "File is not found.";
		return 0;
	}
	ofs.clear();
	ofs.seekp(0, std::ios::end);
	std::string s;
	std::getline(std::cin, s);
	ofs << s << std::endl;
	ofs.close();

	while (s != "exit")
	{
		std::cout << "Input \"read\" or \"erase\" or \"exit\"\n";
		std::cin >> s;
		std::hash<std::string> hasher;
		size_t hash = hasher(s);
		std::string s2;
		switch (constHash(s.c_str()))
		{
		case constHash("read"):  // НЕ ЧИТАЕТ ЕЩЕ !!!
		{
			std::string res = "";
			std::ifstream ifs("output.txt");
			while (std::getline(ifs, s2))
			{
				res += s2 + "\n";
			}
			std::cout << res << std::endl;
			break;
			ifs.close();
		}
		case constHash("erase"):
		{
			std::ofstream clearfile("output.txt", std::ios::trunc);
			clearfile.close();
			break;
		}
		case constHash("exit"):
			break;
		}
	}

}