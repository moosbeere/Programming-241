#include <iostream>

enum ErrorCode { TOO_OLD = 1, NOT_BORN_YET = 2, NEGATIVE_YEAR = 3 };
class YearException : public std::exception {
private:
  ErrorCode errorCode;

public:
  YearException(ErrorCode code) : errorCode(code) {}

  ErrorCode getErrorCode() const { return errorCode; }

  const char *what() const noexcept override {
    switch (errorCode) {
    case TOO_OLD:
      return "Что-то не верится...";
    case NOT_BORN_YET:
      return "Вы ещё не родились";
    case NEGATIVE_YEAR:
      return "Вы ввели отрицательное число!";
    default:
      return "Неизвестная ошибка";
    }
  }
};

int main() {
  try {
    int number;
    std::cout << "Введите число 1, 2 или 3: ";
    std::cin >> number;

    switch (number) {
    case 1:
      std::cout << "Один" << std::endl;
      break;
    case 2:
      std::cout << "Два" << std::endl;
      break;
    case 3:
      std::cout << "Три" << std::endl;
      break;
    default:
      throw std::runtime_error("Некорректное значение");
    }

    int birthYear;
    std::cout << "Введите год вашего рождения: ";
    std::cin >> birthYear;

    if (birthYear < 1850) {
      throw YearException(TOO_OLD);
    } else if (birthYear > 2025) {
      throw YearException(NOT_BORN_YET);
    } else if (birthYear < 0) {
      throw YearException(NEGATIVE_YEAR);
    }

    std::cout << "Спасибо!" << std::endl;
  } catch (const YearException &e) {
    std::cout << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
