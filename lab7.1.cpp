#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cout << "Введите строку: ";
  std::getline(std::cin, s);

  if (s.length() >= 4) {
    std::cout << s.substr(1, 3) << std::endl;
  } else {
    std::cout << "Строка слишком короткая" << std::endl;
  }

  size_t foundIndex = s.find('a');

  if (foundIndex != std::string::npos) {
    std::cout << foundIndex << std::endl;
  } else {
    std::cout << "Символа a не найдено" << std::endl;
  }

  return 0;
}
