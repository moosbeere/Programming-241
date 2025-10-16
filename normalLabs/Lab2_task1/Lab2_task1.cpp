#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    float first, second;
    cout << "Введите два числа: ";
    cin >> first >> second;
    cout << (first + second) / 2;

    cout << "\nВведите знак операции (+,-,*,/): ";
    char oper;
    cin >> oper;

    //if (oper == '+') { cout << first + second << endl; }
    //else if (oper == '-') { cout << first - second << endl; }
    //else if (oper == '*') { cout << first * second << endl; }
    //else if (oper == '/') { cout << first / second << endl;  }
    
    switch (oper) {
        case '+':
            cout << first + second;
            break;
        case '-':
            cout << first - second;
            break;
        case '*':
            cout << first * second;
            break;
        case '/':
            cout << first / second;
            break;
        default:
            cout << "\nВы ввели неправильный знак!";
    }
}
