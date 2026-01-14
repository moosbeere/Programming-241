#include <iostream>
#include <string>
#include <regex>

int main() {
    // Простая версия для английских имен

    // 1. Запрос имени у пользователя
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // 2. Проверка имени (только латинские буквы)
    std::regex namePattern("^[A-Z][a-zA-Z]{1,31}$");

    if (std::regex_match(name, namePattern)) {
        std::cout << "Name '" << name << "' is valid." << std::endl;
    }
    else {
        std::cout << "Invalid name! Must be 2-32 letters, starting with capital letter." << std::endl;
    }

    // 3. Текст с email-адресами
    std::string textWithEmails =
        "Contact us at: support@example.com or sales@company.org.\n"
        "For help email: help@service.co.uk, test.user@subdomain.site.com.\n"
        "Invalid emails: user@, @domain.com, just text.";

    std::cout << "\nText with emails:\n" << textWithEmails << std::endl;

    // 4. Поиск email-адресов
    std::regex emailPattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

    std::cout << "\nFound email addresses:\n";

    // Использование regex_iterator для поиска всех совпадений
    auto begin = std::sregex_iterator(textWithEmails.begin(), textWithEmails.end(), emailPattern);
    auto end = std::sregex_iterator();

    int count = 0;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        std::cout << ++count << ". " << match.str() << '\n';
    }

    std::cout << "Total found: " << count << " email(s)." << std::endl;

    return 0;
}