#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <locale>

using namespace std;

/* =========================
   БЫСТРАЯ СОРТИРОВКА (QuickSort)
   ========================= */

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)  quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

/* =========================
   ЗАДАЧА 1
   ========================= */
void task1()
{
    const int N = 1000;
    int arr[N];

    srand(time(nullptr));

    for (int i = 0; i < N; i++)
        arr[i] = rand() % 2000 - 1000;

    quickSort(arr, 0, N - 1);

    cout << "Первые 20 элементов отсортированной последовательности:\n";
    for (int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

/* =========================
   ЗАДАЧА 2
   ========================= */
void task2()
{
    const int N = 20;
    int arr[N];

    srand(time(nullptr));

    for (int i = 0; i < N; i++)
        arr[i] = 50 + rand() % 51; // [50;100]

    quickSort(arr, 0, N - 1);

    cout << "Отсортированный одномерный массив:\n";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

/* =========================
   ЗАДАЧА 3
   ========================= */
void task3()
{
    const int ROWS = 5;
    const int COLS = 4;

    int arr[ROWS][COLS];
    int firstCol[ROWS];

    srand(time(nullptr));

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = 5 + rand() % 57; // [5;61]

    for (int i = 0; i < ROWS; i++)
        firstCol[i] = arr[i][0];

    quickSort(firstCol, 0, ROWS - 1);

    for (int i = 0; i < ROWS; i++)
        arr[i][0] = firstCol[i];

    cout << "Двумерный массив после сортировки первого столбца:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << "\n";
}

/* =========================
   ЗАДАЧА 4 (qsort)
   ========================= */
struct Student
{
    char name[50];
};

int compareStudents(const void* a, const void* b)
{
    return strcmp(
        ((Student*)a)->name,
        ((Student*)b)->name
    );
}

void task4()
{
    Student group[] = {
        {"Иванов"},
        {"Петров"},
        {"Сидоров"},
        {"Алексеева"},
        {"Кузнецов"}
    };

    int n = sizeof(group) / sizeof(group[0]);

    qsort(group, n, sizeof(Student), compareStudents);

    cout << "Список студентов по алфавиту:\n";
    for (int i = 0; i < n; i++)
        cout << group[i].name << endl;

    cout << endl;
}

/* =========================
   MAIN
   ========================= */
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Задача 1:\n";
    task1();

    cout << "Задача 2:\n";
    task2();

    cout << "Задача 3:\n";
    task3();

    cout << "Задача 4:\n";
    task4();

    return 0;
}
