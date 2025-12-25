#include <vector>
#include <iostream>
#include <map>
#include <string>


class Settings
{
public:
	static std::map<std::string, int> map;

	Settings()
	{
		//map = {
		//	{"size", 100 }, {"time", 255}
		//};
	}

	static void add(std::string key, int value)
	{
		map[key] = value;
	}
	static int get(std::string key)
	{
		return map[key];
	}
	static void print()
	{
		std::cout << "settings = [\n";
		for (auto pair : map)
			std::cout << '\t' << '\t' << pair.first << ": " << pair.second << "\n";
		std::cout << '\t' << '\t' << '\t' << "\t]\n";
	}

};


std::map<std::string, int> Settings::map = {  // Comment when
	{"size", 100},							  // when
	{"time", 255}							  // methods are not static
};


void printVec(std::vector<float> vec)
{
	std::cout << "vector = [";
	auto i = vec.begin();
	for (; i != vec.end() - 1; ++i) std::cout << *i << ", ";
	std::cout << *i << "]\n";


}

int main()
{
	std::vector<float> vec = { 1, 2, 3, 4, 5 };
	vec.insert(vec.begin() + 3, 3.5);
	vec.erase(vec.end() - 1);
	printVec(vec);

	//Settings settings;
	//settings.print();
	//settings.add("weight", 77);
	//std::cout << settings.get("weight") << '\n';
	//settings.print();


	/* Checking of static methods*/
	Settings::print();

	Settings::add("lenght", 50);
	Settings::add("height", 177);
	auto map = Settings::map;
	std::cout << "map = [\n";
	for (auto pair : map)
		std::cout << '\t' << '\t' << pair.first << ": " << pair.second << "\n";
	std::cout << '\t' << '\t' << '\t' << "\t]\n";
	int height = Settings::get("height");
	std::cout << "height = " << height << std::endl;
	Settings::map["time"] = 32;
	Settings::print();

}