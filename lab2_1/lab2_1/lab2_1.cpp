

#include <iostream>
#include <string>
#include <clocale>

int main()
{
	std::setlocale(LC_ALL, "ru_RU.UTF-8");

	int x;
	std::cout << "Введите певрое число ";
	std::cin >> x;

	int y;
	std::cout << "Введите  второе число ";
	std::cin >> y;

	int mil;
	mil = (x + y) / 2;

	char op;
	std::cout << "Введите любой знак между +, -, * или / " << std::endl;
	std::cout << op;

	int result = 0;

	/*
	if (op == '+') {
		result = x + y;
	}

	else if (op == '-') {
		result = x - y;
	}

	else if (op == '*') {
		result = x * y;
	}

	else if (op == '/') {
		if (y == 0) {
			std::cout << "Ошибка: деление на ноль!" << std::endl;
			return 1;
		}
		result = x / y;
	}

	else {
		std::cout << "Неверный оператор!" << std::endl;
		return 1;
	}

	std::cout << "Результат: " << result << std::endl;
	*/

	 
	switch (op) {
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		if (y == 0) {
			std::cout << "Ошибка: деление на ноль!" << std::endl;
			return 1;
		}
		result = x / y;
		break;
	default:
		std::cout << "Неверный оператор!" << std::endl;
		return 1;
	}

	std::cout << "Результат: " << result << std::endl;

	return 0;
}
 