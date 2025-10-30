#include <ctime>
#include <iostream>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T> void selectionSort(T arr[], int size, bool ascending) {
  for (int i = 0; i < size - 1; i++) {
    int newIndex = i;
    for (int j = i + 1; j < size; j++) {
      bool check = ascending ? arr[j] < arr[newIndex] : arr[j] > arr[newIndex];
      if (check) {
        newIndex = j;
      }
    }
    swap(arr[i], arr[newIndex]);
  }
}

template <typename T> void printArray(T arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void fillRand(int *arr, int len, int min, int max) {
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % (max + 1 - min) + min; // 2..103
  }
}

int main() {
  srand(time(0));

  const int SIZE = 10;
  int arr[SIZE];

  fillRand(arr, SIZE, 2, 103);
  cout << "Исходный массив: ";
  printArray(arr, SIZE);
  selectionSort(arr, SIZE, true);

  cout << "Отсортированный массив по возрастанию: ";
  printArray(arr, SIZE);
  fillRand(arr, SIZE, 0, 100);
  cout << "Исходный массив: ";
  printArray(arr, SIZE);
  selectionSort(arr, SIZE, false);
  cout << "Отсортированный массив по убыванию: ";
  printArray(arr, SIZE);

  string phones[] = {"71-45-67", "23-45-67", "32-45-67"};
  cout << "Исходный массив: ";
  printArray(phones, 3);
  selectionSort(phones, 3, true);
  cout << "Отсортированный массив по возрастанию: ";
  printArray(phones, 3);

  return 0;
}
