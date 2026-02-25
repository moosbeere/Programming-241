#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

const double PI = 3.14;
const std::string FILENAME = "data.txt";

int main() {
  double radius;
  std::cout << "Введите радиус окружности: ";
  std::cin >> radius;

  double length = 2 * PI * radius;
  std::cout << "Длина окружности: " << length << std::endl;

  length = std::round(radius * 1000) / 1000;
  std::cout << "Округление: " << length << std::endl;

  std::string input;
  std::ofstream outFile;
  std::ifstream inFile;

  while (true) {
    std::cout << "> ";
    std::getline(std::cin, input);

    if (input == "exit") {
      break;
    } else if (input == "read") {
      inFile.open(FILENAME);

      if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
          std::cout << line << std::endl;
        }
        inFile.close();
      } else {
        std::cout << "Ошибка" << std::endl;
      }

    } else if (input == "erase") {
      outFile.open(FILENAME, std::ios::trunc);

      if (outFile.is_open()) {
        std::cout << "Файл очищен." << std::endl;
        outFile.close();
      } else {
        std::cout << "Ошибка" << std::endl;
      }

    } else {
      outFile.open(FILENAME, std::ios::app);

      if (outFile.is_open()) {
        outFile << input << std::endl;
        outFile.close();
      } else {
        std::cout << "Ошибка" << std::endl;
      }
    }
  }

  return 0;
}
