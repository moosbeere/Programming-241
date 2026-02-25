#include <iostream>
using namespace std;

int func1(int n = 1) {
  if (n <= 0) {
    return 0;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

void calc(int a, int b, int &s, int &p) {
  s = a + b;
  p = a * b;
}

int main() {
  int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

  int tota = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      tota += matrix[i][j];
    }
  }
  cout << "Сумма: " << tota << endl;

  int cols[3] = {0};
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 2; i++) {
      cols[j] += matrix[i][j];
    }
  }

  cout << "Суммы столбцов: ";
  for (int i = 0; i < 3; i++) {
    cout << cols[i] << " ";
  }
  cout << endl;

  float num = 20.84f;

  float &ref1 = num;
  float &ref2 = num;

  ref1 = 15.25f;

  cout << "num: " << num << ", ref1: " << ref1 << ", ref2: " << ref2 << endl;

  cout << "Число 0: " << func1(0) << endl;
  cout << "Число 5: " << func1(5) << endl;
  cout << "Без числа: " << func1() << endl;

  int x = 5, y = 3;
  int sum, product;
  calc(x, y, sum, product);
  cout << x << " + " << y << " = " << sum << endl;
  cout << x << " * " << y << " = " << product << endl;

  int v = 10;
  cout << "Переменная для цикла: " << v << endl;

  for (int i = 0; i < 3; i++) {
    cout << "v внутри цикла: " << v << endl;

    int k = i * 2;

    cout << "k: " << k << endl;
  }

  // cout << k << endl;

  return 0;
}
