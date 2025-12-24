#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void printArr(int arr[], int size, const string &label) {
  cout << label << ": ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printStringArr(const string arr[], int size, const string &label) {
  cout << label << ":" << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
  cout << endl;
}
void fillArr(int arr[], int size, int minVal, int maxVal) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % (maxVal - minVal + 1) + minVal;
  }
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

void selectionSortReversed(int arr[], int size) {
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
  const int size = 10;
  int arr[size];

  fillArr(arr, size, 2, 103);

  printArr(arr, size, "До сортировки");

  selectionSort(arr, size);

  printArr(arr, size, "После сортировки");
}

void task2() {
  const int size = 10;
  int arr[size];

  fillArr(arr, size, 0, 100);
  printArr(arr, size, "До сортировки");
  selectionSortReversed(arr, size);
  printArr(arr, size, "После сортировки");
}

void task3() {
  const int size = 8;
  string phoneNumbers[size] = {"23-45-67", "12-34-56", "98-76-54", "11-22-33",
                               "55-44-33", "67-89-01", "45-67-89", "32-10-98"};

  printStringArr(phoneNumbers, size, "До");
  sortPhoneNumbers(phoneNumbers, size);
  printStringArr(phoneNumbers, size, "После");
}

int main() {
  setlocale(LC_ALL, "RU-ru.UTF-8");

  task1();
  task2();
  task3();

  return 0;
}
