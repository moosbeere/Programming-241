#include <iostream>

static void task_1()
{
	int a = 12;
	int* ref_a = &a;

	std::cout << ref_a << " -> " << a << std::endl;
	*ref_a = 55;
	std::cout << ref_a << " -> " << a << std::endl;

	constexpr int ARRAY_LENGTH = 4;
	int array[ARRAY_LENGTH] = { 14, 543, 12, 435 };
	int* ref_array = array;

	std::cout << "Print array: " << std::endl;

	for (int i = 0; i < ARRAY_LENGTH; i++)
		std::cout << std::addressof(array[i]) << " -> " << array[i] << std::endl;

	int b = 5;
	int* const ref_b = &b;

	std::cout << "previous b: " << b << std::endl;
	// ref_b = &a; <- Ошибка
	*ref_b = 234;
	std::cout << "new b: " << b << std::endl;
}

static int task_2_sum_array(int* start, int* end)
{
	int sum = 0;

	while (start != end)
	{
		sum = sum + *start;
		start++;
	}

	sum = sum + *end;

	return sum;
}

static int task_2_sum(const int a, const int b)
{
	return a + b;
}

static int task_2_sub(const int a, const int b)
{
	return a - b;
}

using math_method = int(*)(const int, const int);

static math_method task_2_char(const char a)
{
	if (a == '+')
		return task_2_sum;
	else if (a == '-')
		return task_2_sub;

	return nullptr;
}

static void task_2()
{
	constexpr int ARRAY_LENGTH = 3;
	int array[ARRAY_LENGTH] = { 1, 2, 3 };

	std::cout << "array sum (start, end): " << task_2_sum_array(array, array + ARRAY_LENGTH - 1) << std::endl;

	math_method method = task_2_char('+');
	std::cout << "method reference result: " << method(1, 5) << std::endl;

	float* dynamic_array = new float[5];

	for (int i = 0; i < 5; i++)
		std::cout << dynamic_array[i] << std::endl;

	delete[] dynamic_array;
}

int main()
{
	std::setlocale(LC_ALL, "Russian");

	int task = 0;
	std::cout << "Введите номер задания" << std::endl;
	std::cin >> task;

	if (task == 1)
		task_1();
	else if (task == 2)
		task_2();
}
