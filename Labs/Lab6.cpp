#include <iostream>
#include <exception>
#include <clocale>

// Идентификаторы ошибок
enum class ExceptionId
{
    UncorrectValue,
    DontBelieveYou,
    YouNotBornYet,
    NegativeNumber
};

// Исключение
class CustomException : public std::exception
{
public:
    explicit CustomException(ExceptionId id) // Только явный вызов конструктора
        : std::exception(messageById(id))
    {
    }

private:
    // Преобразование enum в текст ошибки
    static const char* messageById(ExceptionId id)
    {
        switch (id)
        {
        case ExceptionId::UncorrectValue:
            return "Некорректное значение";
        case ExceptionId::DontBelieveYou:
            return "Что-то не верится...";
        case ExceptionId::YouNotBornYet:
            return "Вы ещё не родились";
        case ExceptionId::NegativeNumber:
            return "Вы ввели отрицательное число!";
        default:
            return "Неизвестное исключение";
        }
    }
};

// Задание
static void runTask()
{
    int number = 0;
    int birthYear = 0;

    try
    {
        // Ввод числа
        std::cout << "Введите число 1, 2 или 3: ";
        std::cin >> number;

        if (number < 1 || number > 3)
            throw CustomException(ExceptionId::UncorrectValue); // Кидаем ошибку

        // Вывод текстового значения
        switch (number)
        {
        case 1: std::cout << "Один\n"; break;
        case 2: std::cout << "Два\n"; break;
        case 3: std::cout << "Три\n"; break;
        }

        // Ввод года рождения
        std::cout << "Введите год своего рождения: ";
        std::cin >> birthYear;

        if (birthYear < 0)
            throw CustomException(ExceptionId::NegativeNumber);
        else if (birthYear > 2025)
            throw CustomException(ExceptionId::YouNotBornYet);
        else if (birthYear < 1850)
            throw CustomException(ExceptionId::DontBelieveYou);

        std::cout << "Спасибо!\n";
    }
    catch (const CustomException& ex)
    {
        // Перехват пользовательского исключения
        std::cout << ex.what() << std::endl;
    }
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    runTask();
    return 0;
}
