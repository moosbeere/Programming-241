#include <iostream>
using namespace std;

float var1, var2;
char operSign;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Запишите два числа: ";
    cin >> var1 >> var2;
    cout << "\nСреднее число: " << (var1+var2) / 2 << "\nВведите знак: ";
    cin >> operSign;

    //if (operSign == '+') {
    //    cout << "\nСумма: " << var1 + var2;
    //}
    //if (operSign == '-') {
    //    cout << "\nРазность: " << var1 - var2;
    //}
    //if (operSign == '*') {
    //    cout << "\nПроизведение: " << var1 * var2;
    //}
    //if (operSign == '/') {
    //    cout << "\nЧастное: " << var1 / var2;
    //}

    switch (operSign) {
        case '+': cout << "\nСумма: " << var1 + var2; break;
        case '-': cout << "\nРазность: " << var1 - var2; break;
        case '*': cout << "\nПроизведение: " << var1 - var2; break;
        case '/': cout << "\nЧастное: " << var1 / var2; break;
        default:  cout << "не, работать не буду.";
    }
}

