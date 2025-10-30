#include <iostream>  
#include <locale>    
using namespace std; 

int main() {
    setlocale(LC_ALL, "Russian"); 
 

    // 1. Получаем от пользователя 2 числа
    double number1, number2; 

    cout << "Введите первое число: "; 
    cin >> number1;                   

    cout << "Введите второе число: "; 
    cin >> number2;                   

    // 2. Выводим среднее арифметическое двух чисел
    double average = (number1 + number2) / 2; // Вычисляем среднее арифметическое
    cout << "Среднее арифметическое чисел " << number1 << " и " << number2
        << " равно: " << average << endl;

    // 3. Просим пользователя ввести знак операции
    
    char operation; 

    cout << "Введите знак операции (+, -, *, /): "; 
    cin >> operation; 

    // 5. Реализация с использованием условного оператора if-else
    /*
    double result; 

    if (operation == '+') { 
        result = number1 + number2;
        cout << number1 << " + " << number2 << " = " << result << endl;
    }
    else if (operation == '-') { 
        result = number1 - number2;
        cout << number1 << " - " << number2 << " = " << result << endl;
    }
    else if (operation == '*') {
        result = number1 * number2;
        cout << number1 << " * " << number2 << " = " << result << endl;
    }
    else if (operation == '/') { 
        if (number2 != 0) { 
            result = number1 / number2;
            cout << number1 << " / " << number2 << " = " << result << endl;
        }
        else {
            cout << "Ошибка: деление на ноль невозможно!" << endl;
        }
    }
    else {
        cout << "Ошибка: неверный знак операции!" << endl;
    }
    */

    // 6. Реализация с использованием оператора switch-case
    double result; // Переменная для хранения результата операции

    switch (operation) { // Начинаем оператор switch
    case '+': 
        result = number1 + number2;
        cout << number1 << " + " << number2 << " = " << result << endl;
        break; 

    case '-': 
        result = number1 - number2;
        cout << number1 << " - " << number2 << " = " << result << endl;
        break; 

    case '*': 
        result = number1 * number2;
        cout << number1 << " * " << number2 << " = " << result << endl;
        break; 

    case '/': 
        if (number2 != 0) { 
            result = number1 / number2;
            cout << number1 << " / " << number2 << " = " << result << endl;
        }
        else {
            cout << "Ошибка: деление на ноль невозможно!" << endl;
        }
        break; 

    default: 
        cout << "Ошибка: неверный знак операции!" << endl;
        break; 
    }

    return 0; 
}