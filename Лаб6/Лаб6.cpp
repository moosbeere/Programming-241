#include <iostream>

using namespace std;

class NTN{
public:
    enum ErrorCode {
        NEGATIVE,
        TOO_OLD,
        NOT_BORN
    };

    NTN(ErrorCode c) {
        code = c;
    }

    const char* what() const {
        if (code == NEGATIVE)
            return "Вы ввели отрицательное число!";
        else if (code == TOO_OLD)
            return "Что-то не верится...";
        else if (code == NOT_BORN)
            return "Вы ещё не родились";
        else
            return "Неизвестная ошибка";
    }

private:
    ErrorCode code;
};

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        int number;
        cout << "Введите число 1, 2 или 3: ";
        cin >> number;

        if (number == 1) {
            cout << "Один" << endl;
        }
        else if (number == 2) {
            cout << "Два" << endl;
        }
        else if (number == 3) {
            cout << "Три" << endl;
        }
        else {
            throw "Некорректное значение";
        }

        int year;
        cout << "Введите год своего рождения: ";
        cin >> year;

        if (year < 0) {
            throw NTN(NTN::NEGATIVE);
        }
        else if (year < 1850) {
            throw NTN(NTN::TOO_OLD);
        }
        else if (year > 2025) {
            throw NTN(NTN::NOT_BORN);
        }

        cout << "Спасибо!" << endl;
    }
    catch (const char* msg) { 
        cout << msg << endl;
    }
    catch (NTN e) {
        cout << e.what() << endl;
    }

    return 0;
}
