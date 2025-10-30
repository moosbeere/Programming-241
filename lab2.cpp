#include <iostream>

using namespace std;

void recurRangePrint(int a, int b) {
  if (a == b)
    return;
  cout << a << " ";
  recurRangePrint(a + 1, b);
}

void recurRangeAB(int a, int b) {
  if (a == b)
    return;
  if (a < b) {
    cout << a << " ";
    a += 1;
  } else {
    cout << a << " ";
    a -= 1;
  }
  recurRangeAB(a, b);
}

int recurSum(int a) {
  if (a <= 0)
    return 0;
  return recurSum(a - 1) + a;
};

void recurDivisors(int n, int c = 2) {
  if (n == 1) {
    return;
  }

  if (c * c > n) {
    if (n > 1) {
      cout << n << " ";
    }
    return;
  }

  if (n % c == 0) {
    cout << c << " ";
    recurDivisors(n / c, c);
  } else {
    if (c == 2) {
      recurDivisors(n, 3);
    } else {
      recurDivisors(n, c + 2);
    }
  }
}

int main() {

  int a, b, n;
  cout << "Дано натуральное число n. Выведите все числа от 1 до n." << endl;
  cout << "Введите число n: ";
  cin >> n;

  if (n < 1)
    return -1;
  recurRangePrint(1, n + 1);
  cout << endl;

  cout << "Даны два целых числа A и В (каждое в отдельной строке). Выведите "
          "все числа от A до B включительно, в порядке возрастания, если A < "
          "B, или в порядке убывания в противном случае"
       << endl;

  cout << "Введите число a: ";
  cin >> a;
  cout << "Введите число b: ";
  cin >> b;

  if (a < b) {
    b += 1;
  } else {
    b -= 1;
  }
  recurRangeAB(a, b);
  cout << endl;

  cout << "Дано натуральное число N. Вычислите сумму его цифр. При решении "
          "этой задачи нельзя использовать строки, списки, массивы (ну и "
          "циклы, разумеется)."
       << endl;
  cout << "Введите число a: ";
  cin >> a;
  cout << recurSum(a) << endl;

  cout << "Дано натуральное число n>1. Выведите все простые делители этого "
          "числа в порядке возрастания. Алгоритм должен иметь сложность "
          "О(sqrt(n))"
       << endl;

  cout << "Введите число a: ";
  cin >> a;
  recurDivisors(a);
  cout << endl;

  return 0;
}
