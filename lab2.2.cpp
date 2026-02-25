#include <iostream>
using namespace std;

int main() {
  int n;
  while (true) {
    cout << "Введите целое положительное число: ";
    cin >> n;

    if (n > 0) {
      break;
    } else {
      cout << "Число должно быть положительным!" << endl;
    }
  }

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  cout << "Сумма чисел от 1 до " << n << " = " << sum << endl;

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "Массив: ";
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Четные индексы: ";
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;

  int oddSum = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 != 0) {
      oddSum += arr[i];
    }
  }
  cout << "Сумма нечетных индексов: " << oddSum << endl;

  return 0;
}
