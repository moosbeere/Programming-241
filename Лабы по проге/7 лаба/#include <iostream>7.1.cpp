#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Попросим пользователя ввести строку
    cout << "Введи строку: ";
    string userStr;
    getline(cin, userStr);

    // 2. Покажем символы со 2 по 4 (индексы 1,2,3)
    if (userStr.size() >= 4) {
        cout << "Символы с 2 по 4: " << userStr.substr(1, 3) << endl;
    } else if (userStr.size() >= 2) {
        // Если строка короткая — покажем что есть с 2-й буквы
        cout << "Символы с 2 по 4: " << userStr.substr(1) << endl;
    } else {
        cout << "Строка слишком короткая." << endl;
    }

    // 3. Найдём первую букву 'a'
    size_t pos = userStr.find('a');
    if (pos != string::npos) {
        cout << "Первая 'a' стоит под номером: " << pos << endl;
    } else {
        cout << "Буква a не найдена" << endl;
    }

    return 0;
}

