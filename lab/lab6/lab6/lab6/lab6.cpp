#include <iostream>
using namespace std;

enum class YearError {
    NEGATIVE,
    BIG,
    LITTLE
};

class YearException : public std::exception {

private:
    YearError code;

public:

    YearException(YearError code) : code(code) {}

    const char* what() const throw() override {
        if (code == YearError::NEGATIVE) return "Вы ввели отрицательное число!";
        else if (code == YearError::BIG) return "Вы ещё не родились";
        else if (code == YearError::LITTLE) return "Что-то не верится...";
    }




};

class Year {

private:

    int year;

public:

    Year(int year) {

        if (year < 0) throw YearException(YearError::NEGATIVE);
        else if (year > 2025) throw YearException(YearError::BIG);
        else if (year < 1850) throw YearException(YearError::LITTLE);

        this->year = year;

    }



    int getHealth() {

        return year;

    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    /*int n;
    cout << "Введите число 1, 2 или 3:" << endl;
    cin >> n;
    try {
        if (!(n == 1 or n == 2 or n == 3)) throw "Некорректное значение";
    }
    catch (const char* msg) {
        std::cout << msg << "\n";
    }*/


    /*int year;
    cout << "Введите год рождения:" << endl;
    cin >> year;
    try {
        if (year < 0) throw "Вы ввели отрицательное число!";
        else if (year > 2025) throw "Вы ещё не родились";
        else if (year < 1850) throw "Что-то не верится...";
        cout << "Спасибо" << endl;
    }
    catch (const char* msg) {
        cout << msg << "\n";
    }*/

    try {

        //Player p(2000);

        //Player p(-10);

        //Player p(0);

        Year o(-1);
        cout << "Спасибо!";
    }

    catch (YearException err) {
        cout << err.what();
    }

}

