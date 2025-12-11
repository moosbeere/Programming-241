#include <iostream>
#include <stdexcept> 
using namespace std;

class myException : public std::exception {
private:
public:
    enum myCode {
        OLD,
        FUTURE,
        NEGATIVE,
        ОКАК
    };
    myCode code;
    myException(myCode code) : code(code) {}

    const char* what() const noexcept override {
        switch (code) {
        case OLD:
            return "Что-то не верится...";
        case FUTURE:
            return "Вы ещё не родились";
        case NEGATIVE:
            return "Вы ввели отрицательное число!";
        case ОКАК:
            return "ОКААААААААААААААААААААААААААААААААК";
        default:
            return "Неизвестная ошибка";
        }
    }
};

string text(int n) {
    if (n==1) return "Один";
    else if (n==2) return "Два";
    else if (n==3) return "Три";
    else throw invalid_argument("Некорректное значение");
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        cout << "Введите число от 1 до 3: ";
        int a;
        cin >> a;
        cout << text(a) << "\n";
    }
    catch (const invalid_argument& msg) {
        cout << msg.what() << "\n";
    }

    try {
        cout << "Введите свой год рождения: ";
        int b;
        cin >> b;
        if (b == 69) throw myException(myException::ОКАК);
        else if (b < 0) throw myException(myException::NEGATIVE);
        else if (b < 1850) throw myException(myException::OLD);
        else if (b > 2025) throw myException(myException::FUTURE);
        else cout << "Спасибо!" << endl;
    }
    catch (const myException& msg) {
        cout << msg.what() << "\n";
    }
}