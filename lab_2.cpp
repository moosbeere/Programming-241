#include <iostream>
#include "lab_2.h"

static void task_1()
{
	int a = 0;
	int b = 0;

	std::cout << "Введите два числа по очереди: " << std::endl;
	std::cin >> a >> b;
	std::cout << "Среднее арифметическое: " << static_cast<float>(a) / static_cast<float>(b) << std::endl;

	char symbol;
	std::cout << "Введите знак '+', '-', '*', '/'" << std::endl;
	std::cin >> symbol;

	//if (symbol == '+')
	//	std::cout << "Сложение переменных: " << a + b << std::endl;
	//else if (symbol == '-')
	//	std::cout << "Вычитание переменных: " << a - b << std::endl;
	//else if (symbol == '*')
	//	std::cout << "Умножение переменных: " << a * b << std::endl;
	//else if (symbol == '/')
	//	std::cout << "Деление переменных: " << a / b << std::endl;

	switch (symbol)
	{
	case '+':
		std::cout << "Сложение переменных: " << a + b << std::endl;
		break;
	case '-':
		std::cout << "Вычитание переменных: " << a - b << std::endl;
		break;
	case '*':
		std::cout << "Умножение переменных: " << a * b << std::endl;
		break;
	case '/':
		std::cout << "Деление переменных: " << a / b << std::endl;
		break;
	default:
		std::cout << "Введён неизвестный оператор" << std::endl;
		break;
	}
}

static void task_2()
{
	int number = 0;

	while (true)

	{
		std::cout << "Введите целое положительное число: ";
		std::cin >> number;

		if (number >= 0)
			break;
		else
			std::cout << "Введите целое положительное число!" << std::endl;
	}

	std::cout << '1';
	for (int i = 2; i <= number; i++)
		std::cout << " + " << i;

	std::cout << std::endl;

	int array[10] =
	{
		1, 5, 6, 2, 3,
		7, 12, 6, 99, 45
	};

	for (int i = 0; i < 10; i++)
		std::cout << array[i] << ' ';

	std::cout << std::endl;

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		if (i % 2 == 0)
			std::cout << array[i] << ' ';
	}

	std::cout << std::endl;

	int sum = 0;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		if (i % 2 == 1)
			sum = sum + array[i];
	}

	std::cout << "Сумма нечетных чисел в массиве: " << sum << std::endl;
}

static int task_3_abs(const int value = 1)
{
	if (value <= 0)
		return 0;

	int sum = value;
	for (int i = 1; i < value - 1; i++)
		sum = sum + i;

	return sum;
}

static void task_3_args(const int value_a, 
	const int value_b, 
	int& ref_a,
	int& ref_b)
{
	ref_a = value_a + value_b;
	ref_b = value_a * value_b;
}

static void task_3()
{
	const int row = 2;
	const int column = 3;

	int array[row][column] =
	{
		1, 2, 3,
		4, 5, 6
	};

	int sum = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < column; y++)
			sum = sum + array[x][y];
	}

	const int new_array_length = 3;
	int transformed_array[new_array_length];

	for (int i = 0; i < new_array_length; i++)
	{
		int local_sum = 0;

		for (int x = 0; x < row; x++)
			local_sum = local_sum + array[x][i];

		transformed_array[i] = local_sum;
	}

	for (int i = 0; i < new_array_length; i++)
		std::cout << transformed_array[i] << ' ';

	std::cout << std::endl;

	float a = 20.84f;

	float& ref_1 = a;
	float& ref_2 = a;

	ref_1 = 12.12f;

	std::cout << "ref_1: " << ref_1 << " ref_2: " << ref_2 << std::endl;

	int ref_int_a, ref_int_b;
	task_3_args(12, 10, ref_int_a, ref_int_b);

	std::cout << "ref_int_a: " << ref_int_a << " ref_int_b: " << ref_int_b << std::endl;
}

#define add(a, b) a + b\

static void task_4()
{
	lab_2::task_4_static(12);
	lab_2::task_4_static(15);
	lab_2::task_4_static(2);
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
	else if (task == 3)
		task_3();
	else if (task == 4)
		task_4();
}

void lab_2::task_4_static(const int value)
{
	static int static_field = 0;

	std::cout << "sum: " << static_field + value << " static_field: " << static_field << std::endl;
	static_field = value;
}
