#include <iostream>
#include <vector>
#include <random>

enum class SortAlgorithm
{
	Max = 0,
	Min = 1,
};

template <auto _Algorithm = SortAlgorithm::Max>
void selection_sort(std::vector<int>& numbers)
{
	size_t array_length = numbers.size() - 1;
	int max = 0;
	if constexpr (_Algorithm == SortAlgorithm::Max)
		max = std::numeric_limits<int>::min();
	else
		max = std::numeric_limits<int>::max();
	int index = 0;

	while (array_length > 0)
	{
		for (int i = 0; i < array_length + 1; i++)
		{
			if constexpr (_Algorithm == SortAlgorithm::Max)
			{
				if (numbers[i] > max)
				{
					max = numbers[i];
					index = i;
				}
			}
			else
			{
				if (numbers[i] < max)
				{
					max = numbers[i];
					index = i;
				}
			}
		}

		std::swap(numbers[array_length], numbers[index]);
		
		if constexpr (_Algorithm == SortAlgorithm::Max)
			max = std::numeric_limits<int>::min();
		else
			max = std::numeric_limits<int>::max();
		index = 0;
		array_length--;
	}
}

std::vector<int> phone_numbers_to_string(const std::vector<std::string>& phone_numbers)
{
	std::vector<int> numbers {};

	for (const auto& number : phone_numbers)
	{
		std::string new_number = number;
		size_t offset = 0;
		size_t index = 0;

		new_number.erase(
			std::remove_if(
				new_number.begin(), 
				new_number.end(), 
				[](const char ch) {
					return ch == '-';
				}
			)
		);

		numbers.push_back(std::atoi(new_number.c_str()));
	}

	return numbers;
}

void selection_sort_phone_numbers(std::vector<std::string>& phone_numbers)
{
	std::vector<int> numbers = phone_numbers_to_string(phone_numbers);
	size_t array_length = numbers.size() - 1;
	int max = std::numeric_limits<int>::min();
	int index = 0;

	while (array_length > 0)
	{
		for (int i = 0; i < array_length + 1; i++)
		{
			if (numbers[i] > max)
			{
				max = numbers[i];
				index = i;
			}
		}

		std::swap(phone_numbers[array_length], phone_numbers[index]);

		max = std::numeric_limits<int>::min();
		index = 0;
		array_length--;
	}
}

void print_vector(const std::vector<int>& v)
{
	for (const auto i : v)
		std::cout << i << " ";

	std::cout << std::endl;
}

int main()
{
	std::vector<int> numbers {};

	std::random_device device {};
	std::uniform_int_distribution<int> random_range_1(2, 103);

	for (int i = 0; i < 5; i++)
		numbers.push_back(random_range_1(device));

	selection_sort(numbers);
	print_vector(numbers);

	numbers.clear();
	std::uniform_int_distribution<int> random_range_2(0, 100);

	for (int i = 0; i < 5; i++)
		numbers.push_back(random_range_2(device));

	selection_sort<SortAlgorithm::Min>(numbers);
	print_vector(numbers);

	std::vector<std::string> phone_numbers =
	{
		"23-45-67",
		"99-24-14",
		"25-86-35",
	};

	selection_sort_phone_numbers(phone_numbers);
}
