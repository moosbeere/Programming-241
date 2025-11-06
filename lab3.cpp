#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>  // Для использования qsort
#include <algorithm>  // Для стандартной сортировки
using namespace std;

// Функция быстрой сортировки
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);  // Сортируем левую часть
        quicksort(arr, pi + 1, high); // Сортируем правую часть
    }
}

// Структура для студента
struct Student {
    char name[100];
    int id;
};

// Функция для сравнения студентов по имени (для qsort)
int compareStudents(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int main() {
    // ✅ Включаем русскую локализацию
    setlocale(LC_ALL, "Russian");

    // ✅ Переключаем консоль Windows в UTF-8
    system("chcp 65001 > nul");

    srand(time(0));

    // 1. Сортировка 1000 чисел с помощью быстрой сортировки
    cout << "Задача 1: Сортировка массива из 1000 чисел\n";
    int arr1[1000];
    for (int i = 0; i < 1000; ++i) {
        arr1[i] = rand() % 1000;  // Случайные числа от 0 до 999
    }

    // Выводим неотсортированный массив
    cout << "Неотсортированный массив:\n";
    for (int i = 0; i < 1000; ++i) {
        cout << arr1[i] << " ";
    }
    cout << "\n";

    quicksort(arr1, 0, 999);  // Быстрая сортировка

    // Выводим отсортированный массив
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < 1000; ++i) {
        cout << arr1[i] << " ";
    }
    cout << "\n\n";

    // 2. Сортировка массива случайных чисел в интервале {50, 100}
    cout << "Задача 2: Сортировка массива случайных чисел {50, 100}\n";
    int arr2[100];
    for (int i = 0; i < 100; ++i) {
        arr2[i] = rand() % 51 + 50;  // Случайные числа от 50 до 100
    }

    // Выводим неотсортированный массив
    cout << "Неотсортированный массив:\n";
    for (int i = 0; i < 100; ++i) {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    quicksort(arr2, 0, 99);  // Быстрая сортировка

    // Выводим отсортированный массив
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < 100; ++i) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";

    // 3. Сортировка первого столбца двумерного массива
    cout << "Задача 3: Сортировка первого столбца двумерного массива\n";
    int arr3[10][5];  // 10 строк, 5 столбцов
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr3[i][j] = rand() % 57 + 5;  // Случайные числа от 5 до 61
        }
    }

    // Выводим двумерный массив до сортировки
    cout << "Двумерный массив до сортировки первого столбца:\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << arr3[i][j] << " ";
        }
        cout << "\n";
    }

    // Сортируем первый столбец
    int firstColumn[10];
    for (int i = 0; i < 10; ++i) {
        firstColumn[i] = arr3[i][0];
    }

    quicksort(firstColumn, 0, 9);  // Быстрая сортировка столбца

    // Заменяем отсортированные значения обратно в массив
    for (int i = 0; i < 10; ++i) {
        arr3[i][0] = firstColumn[i];
    }

    // Выводим двумерный массив после сортировки первого столбца
    cout << "Двумерный массив после сортировки первого столбца:\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << arr3[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // 4. Сортировка студентов по алфавиту с использованием qsort
    cout << "Задача 4: Сортировка студентов по алфавиту\n";
    Student students[15] = {
        {"Ivanov", 1},
        {"Petrov", 2},
        {"Sidorov", 3},
        {"Alekseev", 4},
        {"Zaharov", 5},
        {"Dmitriev", 6},
        {"Alexandrov", 7},
        {"Vasiliev", 8},
        {"Kuznetsov", 9},
        {"Morozov", 10},
        {"Popov", 11},
        {"Novikov", 12},
        {"Gorbunov", 13},
        {"Fedorov", 14},
        {"Volkov", 15}
    };

    qsort(students, 15, sizeof(Student), compareStudents);  // Сортировка студентов по имени

    cout << "Студенты отсортированы по алфавиту:\n";
    for (int i = 0; i < 15; ++i) {
        cout << students[i].name << "\n";  // Выводим только имена студентов
    }
    cout << "\n";

    return 0;
}
