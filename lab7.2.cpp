#include <iostream>
#include <regex>
#include <string>

int main() {
  std::string name;
  std::cout << "Введите ваше имя: ";
  std::getline(std::cin, name);

  std::regex nameRegex("^[A-Z][a-zA-Z]{1,31}$");

  if (std::regex_match(name, nameRegex)) {
    std::cout << "Имя корректно!" << std::endl;
  } else {
    std::cout << "Ошибка!" << std::endl;
  }

  std::string textWithEmails = R"(
        Почта для работы: work.email@company.com.
        Для личной переписки: personal123@mail.ru.
        Иногда пишу с: john.doe123@example.co.uk.
        А вот это не email: просто@текст.
        Контакты для связи: support@my-site.com, admin@server.local.
    )";

  // Почта@компания.код_компании
  std::regex emailRegex(R"(([a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}))");

  auto words_begin = std::sregex_iterator(textWithEmails.begin(),
                                          textWithEmails.end(), emailRegex);
  auto words_end = std::sregex_iterator();

  int emailCount = 0;
  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;
    std::cout << emailCount << ". " << match.str() << std::endl;
    emailCount += 1;
  }

  return 0;
}
