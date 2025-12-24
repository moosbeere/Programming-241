#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

struct Student {
  char name[50];
  int group;
};

const int SIZE_1D = 20;
const int SIZE_2D_ROWS = 10;
const int SIZE_2D_COLS = 5;
const int size = 8;

void quickSort(int arr[], int left, int right) {
  if (left >= right)
    return;

  int pivot = arr[(left + right) / 2];
  int i = left, j = right;

  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
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

int compareStud(const void *a, const void *b) {
  const Student *studentA = (const Student *)a;
  const Student *studentB = (const Student *)b;
  return strcmp(studentA->name, studentB->name);
}

void fill(int arr[], int size, int minVal, int maxVal) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % (maxVal - minVal + 1) + minVal;
  }
}

void printArr(int arr[], int size, const string &label) {
  if (label[0] != '\0')
    cout << label << ":\n";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
    if ((i + 1) % 20 == 0)
      cout << endl; // По 20 чисел в строке
  }
  cout << "\n";
}

void printStudents(Student students[], int count) {
  for (int i = 0; i < count; i++) {
    cout << i + 1 << ". " << students[i].name << " - " << students[i].group
         << endl;
  }
}

void task1() {
  const int size = 20;
  int sequence[size];

  fill(sequence, size, 1, 1000);
  printArr(sequence, size, "Исходный");
  quickSort(sequence, 0, size - 1);
  printArr(sequence, size, "Отсортированный");
}

void task2() {
  const int size = 15;
  int arr[size];

  fill(arr, size, 50, 100);
  printArr(arr, size, "Исходный");
  quickSort(arr, 0, size - 1);
  printArr(arr, size, "Отсортированный");
}

void task3() {
  const int rows = 6;
  const int cols = 6;
  int matrix[rows][cols];

  for (int i = 0; i < rows; i++)
    fill(matrix[i], cols, 5, 61);

  cout << "До сортировки" << endl;
  for (int i = 0; i < rows; i++)
    printArr(matrix[i], cols, "");

  int arr[rows];
  for (int i = 0; i < rows; i++)
    arr[i] = matrix[i][0];

  quickSort(arr, 0, rows - 1);

  for (int i = 0; i < rows; i++)
    matrix[i][0] = arr[i];

  cout << "После" << endl;
  for (int i = 0; i < rows; i++)
    printArr(matrix[i], cols, "");
}

void task4() {
  const int size = 8;
  Student students[size] = {{"Иванов Иван", 101},     {"Петров Петр", 102},
                            {"Сидоров Алексей", 101}, {"Кузнецова Мария", 103},
                            {"Смирнов Дмитрий", 102}, {"Васильева Анна", 103},
                            {"Попова Елена", 101},    {"Новиков Сергей", 104}};

  cout << "Исходный список" << endl;
  printStudents(students, size);

  qsort(students, size, sizeof(Student), compareStud);

  cout << "Отсортированный список" << endl;
  printStudents(students, size);
}

int main() {
  task1();
  cout << endl;
  task2();
  cout << endl;
  task3();
  cout << endl;
  task4();

  return 0;
}
