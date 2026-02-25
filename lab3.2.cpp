#include <iostream>
using namespace std;

int sum(int a, int b) { return a + b; }

int difference(int a, int b) { return a - b; }

int (*getOperation(char op))(int, int) {
  if (op == '+') {
    return &sum;
  } else if (op == '-') {
    return &difference;
  }
  return nullptr;
}

int sumArray(int *start, int *end) {
  int total = 0;

  while (start != end) {
    total += *start;
    start++;
  }

  return total;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  int result = sumArray(arr, arr + size);
  cout << "Сумма массива: " << result << endl;

  char operation = '+';

  int (*funcPtr)(int, int) = getOperation(operation);

  if (funcPtr != nullptr) {
    int calcResult = funcPtr(10, 5);
    cout << "10 " << operation << " 5 = " << calcResult << endl;
  }

  float *dynamicFloat = new float; // Выделение памяти в куче

  *dynamicFloat = 3.14159f;

  cout << "float значение: " << *dynamicFloat << endl;

  delete dynamicFloat;
  dynamicFloat = nullptr;

  return 0;
}
