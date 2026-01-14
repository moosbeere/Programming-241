#include <iostream>
#include <string>
#include <locale> // для setlocale

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    // 1. Просим пользователя ввести строку
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    // 2. Выводим подстроку со 2-го по 4-й символ включительно
    // Проверяем, что длина строки >= 4
    if (input.length() >= 4) {
        std::string substring = input.substr(1, 3); // substr(start, length)
        std::cout << "Подстрока с 2-го по 4-й символ: " << substring << std::endl;
    }
    else {
        std::cout << "Строка слишком короткая для подстроки с 2-го по 4-й символ." << std::endl;
    }

    // 3. Выводим индекс первого вхождения символа 'a'
    size_t pos = input.find('a');
    if (pos != std::string::npos) {
        std::cout << "Индекс первого вхождения 'a': " << pos << std::endl;
    }
    else {
        std::cout << "Символа a не найдено" << std::endl;
    }

    return 0;
}
