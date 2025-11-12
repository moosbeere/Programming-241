#include <iostream>

void recursion(const int x, const int y = 1)
{
	std::cout << y << std::endl;

	if (x != y)
		recursion(x, y + 1);
}

void recursion_a_b(const int a, const int b)
{
	std::cout << a << std::endl;

	if (a == b)
		return;

	if (a < b)
		recursion_a_b(a + 1, b);
	else
		recursion_a_b(a - 1, b);
}

int sum_digits(const int x)
{
	if (x == 0)
		return 0;
	
	return x % 10 + sum_digits(x / 10);
}

void get_divs(int x, const int divisor = 2) 
{
	if (divisor > x) 
		return;

	if (x % divisor == 0) 
	{
		std::cout << divisor << std::endl;

		while (x % divisor == 0)
			x /= divisor;
	}

	get_divs(x, divisor + 1);
}

int main_3()
{
	int n = 2;

	recursion_a_b(1, 4);

	return 0;
}