#include <iostream>
#include <string>
using namespace std;

int main() {
    string userInput;
    cout << "Введите строку: ";
    getline(cin, userInput);

    if (userInput.length() >= 4) {
        string substring = userInput.substr(1, 3); 
        cout << "Подстрока со 2-го по 4-й символ: " << substring << endl;
    } else {
        cout << "Строка слишком короткая для извлечения подстроки!" << endl;
    }

    int index = userInput.find('a');
    if (index != string::npos) {
        cout << "Индекс первого вхождения 'a': " << index << endl;
    } else {
        cout << "Символа a не найдено" << endl;
    }

    return 0;
}
