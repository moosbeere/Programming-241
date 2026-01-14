#include <iostream>
#include <string>
#include <regex>
#include <locale>

int main() {
    // Устанавливаем локаль для корректного отображения русских символов
    setlocale(LC_ALL, "Russian");

    // 1. Попросим пользователя ввести имя
    std::string name;
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, name);

    // 2. Проверяем корректность имени с помощью регулярного выражения
    // Имя: от 2 до 32 символов, только буквы, первая заглавная
    std::regex name_regex("^[А-ЯA-Z][а-яa-zА-ЯA-Z]{1,31}$");
    if (std::regex_match(name, name_regex)) {
        std::cout << "Имя корректно." << std::endl;
    }
    else {
        std::cout << "Имя некорректно. Оно должно быть от 2 до 32 букв, первая буква заглавная." << std::endl;
    }

    // 3. Создаем строку с произвольным текстом, содержащим несколько e-mail адресов
    std::string text = "Пример текста с e-mail адресами: example1@mail.com, test.user@yandex.ru, hello123@gmail.com";

    // 4. С помощью регулярного выражения вытащим все e-mail адреса
    std::regex email_regex(R"(([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}))");
    auto emails_begin = std::sregex_iterator(text.begin(), text.end(), email_regex);
    auto emails_end = std::sregex_iterator();

    std::cout << "Найденные e-mail адреса:" << std::endl;
    for (std::sregex_iterator i = emails_begin; i != emails_end; ++i) {
        std::smatch match = *i;
        std::cout << match.str() << std::endl;
    }

    return 0;
}
