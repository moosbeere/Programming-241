#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

template <typename T> void quickSort(T arr[], int left, int right) {
  if (left >= right)
    return;

  int mid = arr[(left + right) / 2];
  int i = left, j = right;

  while (i <= j) {
    while (arr[i] < mid)
      i++;
    while (arr[j] > mid)
      j--;
    if (i <= j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  quickSort(arr, left, j);
  quickSort(arr, i, right);
}

void fillRand(int *arr, int len, int min, int max) {
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % (max + 1 - min) + min; // 2..103
  }
}

template <typename T> void printArray(T arr[], int size, string del = " ") {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << del;
  }
  cout << endl;
}

int compare(const void *x1, const void *x2) {
  return ((string *)x1)->compare(*(string *)x2);
}

int main() {
  srand(time(0));

  // Первая программа
  const int SIZE = 1000;
  int arr[SIZE];
  fillRand(arr, SIZE, 0, 1000);
  printArray(arr, SIZE);
  quickSort(arr, 0, SIZE - 1);
  printArray(arr, SIZE);

  // Вторая программа
  fillRand(arr, SIZE, 50, 100);
  printArray(arr, SIZE);
  quickSort(arr, 0, SIZE - 1);
  printArray(arr, SIZE);

  // Третья программа
  const int SIZE_2D = 5;
  int arr_2d[SIZE_2D][SIZE_2D] = {0};
  for (int i = 0; i < SIZE_2D; i++) {
    fillRand(arr_2d[i], SIZE_2D, 5, 61);
  }
  for (int i = 0; i < SIZE_2D; i++) {
    printArray(arr_2d[i], SIZE_2D);
  }

  int row[SIZE_2D];
  for (int i = 0; i < SIZE_2D; i++) {
    row[i] = arr_2d[i][0];
  }

  quickSort(row, 0, SIZE_2D - 1);
  for (int i = 0; i < SIZE_2D; i++) {
    arr_2d[i][0] = row[i];
  }

  for (int i = 0; i < SIZE_2D; i++) {
    printArray(arr_2d[i], SIZE_2D);
  }

  // Четвертая программа
  string students[] = {"Иванов Алексей", "Петрова Мария", "Сидоров Дмитрий",
                       "Абрамова Анна", "Козлов Иван"};
  qsort(students, 4, sizeof(students[0]), compare);
  printArray(students, 4, "\n");
}
