#include <cmath>
#include <iostream>

using namespace std;

void task1(int n) {
  if (n <= 0)
    return;
  task1(n - 1);
  cout << n << " ";
}

void task2(int a, int b) {
  if (a == b) {
    cout << a << " ";
    return;
  }

  cout << a << " ";

  if (a < b) {
    task2(a + 1, b);
  } else {
    task2(a - 1, b);
  }
}

int task3(int n) {
  if (n == 0)
    return 0;
  return (n % 10) + task3(n / 10);
}

bool isPrime(int n, int divisor = 2) {
  if (n <= 2)
    return (n == 2);
  if (n % divisor == 0)
    return false;
  if (divisor * divisor > n)
    return true;
  return isPrime(n, divisor + 1);
}

void task4(int n, int divisor = 2) {
  if (n <= 1)
    return;

  if (divisor * divisor > n) {
    if (n > 1 && isPrime(n)) {
      cout << n << " ";
    }
    return;
  }

  if (n % divisor == 0 && isPrime(divisor)) {
    cout << divisor << " ";
    while (n % divisor == 0) {
      n /= divisor;
    }
  }

  task4(n, divisor + 1);
}

int main() {
  int n1, a, b, n3;

  cout << "Введите n: ";
  cin >> n1;
  task1(n1);
  cout << endl;

  cout << "Введите A: ";
  cin >> a;
  cout << "Введите B: ";
  cin >> b;
  task2(a, b);
  cout << endl;

  cout << "Введите число N: ";
  cin >> n3;
  cout << task3(abs(n3)) << std::endl;

  int n4;
  cout << "Введите число N: ";
  cin >> n4;
  task4(n4);
  cout << endl;

  return 0;
}
