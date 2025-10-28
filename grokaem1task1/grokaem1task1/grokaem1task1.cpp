#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale> 

using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    const int MIN_VALUE = 2;
    const int MAX_VALUE = 103;
    const int ARRAY_SIZE = 10;

    int arr[ARRAY_SIZE];

    cout << "Генерация случайного массива..." << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    cout << "Исходный массив: ";
    printArray(arr, ARRAY_SIZE);

    selectionSort(arr, ARRAY_SIZE);

    cout << "Отсортированный массив: ";
    printArray(arr, ARRAY_SIZE);

    if (isSorted(arr, ARRAY_SIZE)) {
        cout << "Массив отсортирован корректно!" << endl;
    }
    else {
        cout << "Ошибка сортировки!" << endl;
    }

    return 0;
}