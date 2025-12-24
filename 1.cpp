#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void fill(int arr[], int size, int minVal, int maxVal) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % (maxVal - minVal + 1) + minVal;
  }
}

void printArr(int arr[], int size, const string &label) {
  cout << label << ": ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printSArr(const string arr[], int size, const string &label) {
  cout << label << ":\n";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
  cout << endl;
}

void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

void selectionSortRevers(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int maxIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] > arr[maxIndex]) {
        maxIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[maxIndex];
    arr[maxIndex] = temp;
  }
}

void sortPhoneNumbers(string arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    string temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

void task1() {
  const int SIZE = 10;
  int arr[SIZE];

  fill(arr, SIZE, 2, 103);
  printArr(arr, SIZE, "До");
  selectionSort(arr, SIZE);
  printArr(arr, SIZE, "После");
}

void task2() {
  const int SIZE = 10;
  int arr[SIZE];

  fill(arr, SIZE, 0, 100);
  printArr(arr, SIZE, "До");
  selectionSortRevers(arr, SIZE);
  printArr(arr, SIZE, "После");
}

void task3() {
  const int SIZE = 8;
  string phoneNumbers[SIZE] = {"23-45-67", "12-34-56", "98-76-54", "11-22-33",
                               "55-44-33", "67-89-01", "45-67-89", "32-10-98"};

  printSArr(phoneNumbers, SIZE, "До");
  sortPhoneNumbers(phoneNumbers, SIZE);
  printSArr(phoneNumbers, SIZE, "После");
}

int main() {
  setlocale(LC_ALL, "RU-ru.UTF-8");

  task1();
  task2();
  task3();

  return 0;
}
