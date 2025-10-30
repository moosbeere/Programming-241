#include <iostream>
using namespace std;

//void quick_sort(int arr[], int left, int right) {
//    if (left >= right) return;
//
//    int pivot = arr[(left + right) / 2];
//    int i = left, j = right;
//
//    while (i <= j) {
//        while (arr[i] < pivot) i++;
//        while (arr[j] > pivot) j--;
//        if (i <= j) {
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            i++;
//            j--;
//        }
//    }
//
//    quick_sort(arr, left, j);
//    quick_sort(arr, i, right);
//}
//
//int main() {
//    const int n = 1000;
//    int arr[n];
//
//    // Заполнение массива
//    for (int i = 0; i < n; i++) {
//        arr[i] = rand() % 10000;
//    }
//
//    cout << "Исходный массив:" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    quick_sort(arr, 0, n - 1);
//
//    cout << "Отсортированный массив:" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
//
////2
//void quick_sort(int arr[], int left, int right) {
//    if (left >= right) return;
//
//    int pivot = arr[(left + right) / 2];
//    int i = left, j = right;
//
//    while (i <= j) {
//        while (arr[i] < pivot) i++;
//        while (arr[j] > pivot) j--;
//        if (i <= j) {
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            i++;
//            j--;
//        }
//    }
//
//    quick_sort(arr, left, j);
//    quick_sort(arr, i, right);
//}
//
//int main() {
//    const int n = 20;
//    int arr[n];
//
//    // Заполнение массива числами от 50 до 100
//    for (int i = 0; i < n; i++) {
//        arr[i] = 50 + rand() % 51;
//    }
//
//    cout << "Исходный массив:" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    quick_sort(arr, 0, n - 1);
//
//    cout << "Отсортированный массив:" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
//
////3
//const int ROWS = 5;
//const int COLS = 4;
//
//void quick_sort(int arr[], int left, int right) {
//    if (left >= right) return;
//
//    int pivot = arr[(left + right) / 2];
//    int i = left, j = right;
//
//    while (i <= j) {
//        while (arr[i] < pivot) i++;
//        while (arr[j] > pivot) j--;
//        if (i <= j) {
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            i++;
//            j--;
//        }
//    }
//
//    quick_sort(arr, left, j);
//    quick_sort(arr, i, right);
//}
//
//int main() {
//    int arr[ROWS][COLS];
//
//    // Заполнение массива числами от 5 до 61
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            arr[i][j] = 5 + rand() % 57;
//        }
//    }
//
//    cout << "Исходный массив:" << endl;
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            cout << arr[i][j] << "\t";
//        }
//        cout << endl;
//    }
//
//    // Извлечение и сортировка первого столбца
//    int first_column[ROWS];
//    for (int i = 0; i < ROWS; i++) {
//        first_column[i] = arr[i][0];
//    }
//
//    quick_sort(first_column, 0, ROWS - 1);
//
//    // Возвращение отсортированного столбца
//    for (int i = 0; i < ROWS; i++) {
//        arr[i][0] = first_column[i];
//    }
//
//    cout << "Массив после сортировки первого столбца:" << endl;
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            cout << arr[i][j] << "\t";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}



//4
#include <iostream>
using namespace std;
#include <cstring>

struct Student {
    char name[50];
    char group[10];
    int grade;
};

// Функция сравнения для сортировки
int compare_students(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;
    return strcmp(studentA->name, studentB->name);
}

void quick_sort_students(Student arr[], int left, int right) {
    if (left >= right) return;

    int pivot_index = (left + right) / 2;
    char* pivot = arr[pivot_index].name;

    int i = left, j = right;

    while (i <= j) {
        while (strcmp(arr[i].name, pivot) < 0) i++;
        while (strcmp(arr[j].name, pivot) > 0) j--;
        if (i <= j) {
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort_students(arr, left, j);
    quick_sort_students(arr, i, right);
}

int main() {
    const int n = 5;
    Student students[n] = {
        {"Иванов Алексей ГРУППА-1", 85},
        {"Петрова Мария ГРУППА-2", 92},
        {"Сидоров Дмитрий ГРУППА-1", 78},
        {"Алексеева Анна ГРУППА-3", 88},
        {"Кузнецов Сергей ГРУППА-2", 95}
    };

    cout << "Исходный список студентов:" << endl;
    for (int i = 0; i < n; i++) {
        cout << students[i].name << " - " << students[i].group << " - " << students[i].grade << endl;
    }
    cout << endl;

    quick_sort_students(students, 0, n - 1);

    cout << "Отсортированный список студентов:" << endl;
    for (int i = 0; i < n; i++) {
        cout << students[i].name << " - " << students[i].group << " - " << students[i].grade << endl;
    }

    return 0;
}