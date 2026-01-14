#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//---------------------- Быстрая сортировка массива ----------------------
void quicksort(int a[], int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (left < j) quicksort(a, left, j);
    if (i < right) quicksort(a, i, right);
}

//---------------------- Быстрая сортировка столбца в 2D массиве ----------------------
const int ROWS = 10;
const int COLS = 5;

void quicksortColumn(int a[][COLS], int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2][0];

    while (i <= j) {
        while (a[i][0] < pivot) i++;
        while (a[j][0] > pivot) j--;
        if (i <= j) {
            for (int c = 0; c < COLS; c++)
                swap(a[i][c], a[j][c]);
            i++; j--;
        }
    }
    if (left < j) quicksortColumn(a, left, j);
    if (i < right) quicksortColumn(a, i, right);
}

//---------------------- Функция сравнения для qsort ----------------------
int compareStrings(const void* a, const void* b) {
    const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;
    return strcmp(s1, s2);
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    // -------------------------- 1 --------------------------
    int N = 1000;
    int arrONE[N];

    for (int i = 0; i < N; i++)
        arrONE[i] = rand() % 1000;

    quicksort(arrONE, 0, N - 1); // массив отсортирован

    // -------------------------- 2 --------------------------
    N = 20;
    int arrTWO[N];

    for (int i = 0; i < N; i++)
        arrTWO[i] = 50 + rand() % 51;

    quicksort(arrTWO, 0, N - 1); // массив отсортирован

    // -------------------------- 3 --------------------------
    int arrTHREE[ROWS][COLS];

    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            arrTHREE[r][c] = 5 + rand() % 57;

    quicksortColumn(arrTHREE, 0, ROWS - 1); // массив отсортирован

    // -------------------------- 4 --------------------------
        N = 5;
        const char* students[N] = {
            "Иванов",
            "Петров",
            "Сидоров",
            "Алексеев",
            "Матвеев"
        };

        qsort(students, N, sizeof(char*), compareStrings);

        cout << "Отсортированный список студентов:\n";
        for (int i = 0; i < N; i++)
            cout << students[i] << endl;

    return 0;
}
