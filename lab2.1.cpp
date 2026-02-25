#include <iostream>
using namespace std;

int main() {
  double num1, num2;
  cout << "Введите первое число: ";
  cin >> num1;
  cout << "Введите второе число: ";
  cin >> num2;

  cout << "Среднее арифметическое: " << (num1 + num2) / 2 << endl;

  char op;
  cout << "Введите операцию (+, -, *, /): ";
  cin >> op;

  /*
  if (operation == '+') {
      cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
  }
  else if (operation == '-') {
      cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
  }
  else if (operation == '*') {
      cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
  }
  else if (operation == '/') {
      cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
  }
  else {
      cout << "Неизвестная операция!" << endl;
  }
  */

  switch (op) {
  case '+':
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    break;
  case '-':
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    break;
  case '*':
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    break;
  case '/':
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;

    break;
  default:
    cout << "Неизвестная операция!" << endl;
  }

  return 0;
}
