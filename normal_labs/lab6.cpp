#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        int num;
        cout << "Введите число (1, 2 или 3): ";
        cin >> num;

        if (num == 1) cout << "Один" << endl;
        else if (num == 2) cout << "Два" << endl;
        else if (num == 3) cout << "Три" << endl;
        else throw invalid_argument("Некорректное значение");
    }
    catch (const invalid_argument& e) {
        cout << "Некорректное значение" << endl;
    }

    

    enum BirthError {
        TOO_OLD,
        TOO_YOUNG,
        NEGATIVE,
        MY_EXCEPTION
    };

    class BirthException {
    private:
        BirthError error;
    public:
        BirthException(BirthError e) : error(e) {}
        BirthError getCode() const { return error; }
    };

    try {
        int year;
        cout << "Введите год рождения: ";
        cin >> year;

        int currentYear = 2026;

        if (year < 0)
            throw BirthException(NEGATIVE);

        if (year < 1850)
            throw BirthException(TOO_OLD);

        if (year > currentYear)
            throw BirthException(TOO_YOUNG);
        
        if (year == 2007)
            throw BirthException(MY_EXCEPTION);

        cout << "Спасибо!" << endl;
    }
    catch (const BirthException& ex) {
        switch (ex.getCode()) {
        case NEGATIVE:
            cout << "Вы ввели отрицательное число!" << endl;
            break;
        case TOO_OLD:
            cout << "Что-то не верится..." << endl;
            break;
        case TOO_YOUNG:
            cout << "Вы ещё не родились" << endl;
            break;
        case MY_EXCEPTION:
            cout << "Мое исключение" << endl;
            break;
        }
    }

    return 0;
}