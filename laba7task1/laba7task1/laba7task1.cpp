#include <iostream>
#include <string>
#include <locale>
int main() {
    std::locale::global(std::locale("RU"));
    std::string userString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, userString);
    if (userString.length() >= 4) {
        std::string substring = userString.substr(1, 3);
        std::cout << "Подстрока от 2-го до 4-го символа: " << substring << std::endl;
    }
    else {
        std::cout << "Строка слишком короткая для получения подстроки от 2-го до 4-го символа" << std::endl;
    }
    size_t found = userString.find('a');
    if (found != std::string::npos) {
        std::cout << "Индекс первого вхождения символа 'a': " << found << std::endl;
    }
    else {
        std::cout << "Символа a не найдено" << std::endl;
    }
    return 0;
}