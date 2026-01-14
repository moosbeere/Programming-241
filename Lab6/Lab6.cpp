#include <iostream>
#include <locale>
#include <stdexcept>
#include <ctime>

// Собственный класс исключений для года рождения
class BirthYearException : public std::exception {
public:
    enum ErrorCode {
        TOO_OLD,
        FUTURE,
        NEGATIVE
    };

    BirthYearException(ErrorCode code) : code(code) {}

    const char* what() const noexcept override {
        switch (code) {
        case TOO_OLD: return "Что-то не верится...";
        case FUTURE: return "Вы ещё не родились";
        case NEGATIVE: return "Вы ввели отрицательное число!";
        default: return "Неизвестная ошибка";
        }
    }

private:
    ErrorCode code;
};

int main() {
    // Поддержка русского языка в консоли
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale());
    std::wcin.imbue(std::locale());

    try {
        // Задание 1 и 2: число 1, 2 или 3
        std::wcout << L"Введите число 1, 2 или 3: ";
        int num;
        std::wcin >> num;

        switch (num) {
        case 1: std::wcout << L"Один\n"; break;
        case 2: std::wcout << L"Два\n"; break;
        case 3: std::wcout << L"Три\n"; break;
        default: throw std::runtime_error("Некорректное значение");
        }

    }
    catch (const std::runtime_error& e) {
        std::wcout << e.what() << L"\n";
    }

    try {
        // Задание 3-8: год рождения
        std::wcout << L"Введите год своего рождения: ";
        int year;
        std::wcin >> year;

        // Получаем текущий год безопасно для Visual Studio
        std::time_t t = std::time(nullptr);
        std::tm now{};
        localtime_s(&now, &t);  // безопасная версия localtime
        int currentYear = now.tm_year + 1900;

        if (year < 0)
            throw BirthYearException(BirthYearException::NEGATIVE);
        else if (year < 1850)
            throw BirthYearException(BirthYearException::TOO_OLD);
        else if (year > currentYear)
            throw BirthYearException(BirthYearException::FUTURE);

        std::wcout << L"Спасибо!\n";

    }
    catch (const BirthYearException& e) {
        std::wcout << e.what() << L"\n";
    }

    return 0;
}
