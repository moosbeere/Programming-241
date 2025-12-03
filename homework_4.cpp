#include <iostream>
#include <fstream>
#include <unordered_set>
#include <istream>
#include <string>
#include <algorithm>

std::vector<int> get_numbers_from_input(std::ifstream& input)
{
	std::vector<int> numbers {};
	std::string input_string {
		std::istreambuf_iterator<char>(input),
		std::istreambuf_iterator<char>()
	};

	std::string temp {};
	for (const char ch : input_string)
	{
		if (std::isdigit(ch) || ch == '0')
		{
			temp.push_back(ch);
		}
		else
		{
			numbers.push_back(std::atoi(temp.c_str()));
			temp.clear();
		}
	}

	if (temp.size() > 0)
		numbers.push_back(std::atoi(temp.c_str()));

	return numbers;
}


int main33()
{
	std::unordered_set<int> numbers {};
	std::ifstream input_stream("input.txt", std::ios::app);
	const auto& input_numbers = get_numbers_from_input(input_stream);

	for (const auto x : input_numbers)
	{
		if (x > 0)
			numbers.emplace(x);
		else if (x < 0)
			numbers.erase(-x);
		else
			break;
	}

	std::vector<int> sorted_numbers(numbers.begin(), numbers.end());
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	std::ofstream output_stream("output.txt", std::ios::trunc);
	std::string output_string {};

	for (const auto x : sorted_numbers)
		output_string = output_string + std::to_string(x) + ' ';

	output_string.pop_back();

	output_stream.write(output_string.data(), output_string.size());

	return 0;
}