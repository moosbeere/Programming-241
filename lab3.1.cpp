#include <iostream>
using namespace std;

int main() {
  int myVar = 42;
  cout << "Переменная myVar = " << myVar << endl;

  int *ptr = &myVar;

  cout << "Адрес ptr: " << &ptr << endl;
  cout << "Адрес, на который указывает ptr: " << ptr << endl;
  cout << "Значение по адресу ptr: " << *ptr << endl;

  *ptr = 100;

  cout << "myVar: " << myVar << endl;

  int arr[5] = {10, 20, 30, 40, 50};

  cout << "Массив через указатель: ";
  int *arrp = arr;
  for (int i = 0; i < 5; i++) {
    cout << *(arrp + i) << " ";
  }
  cout << endl;

  int num = 5;
  cout << "Значение num: " << num << endl;

  int *const constPtr = &num;

  // constPtr = &myVar;

  *constPtr = 25;
  cout << "Значение num: " << num << endl;

  int anotherVar = 50;
  // constPtr = &anotherVar;

  return 0;
}
