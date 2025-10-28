#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

void selectionSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {  
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSortedDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] < arr[i + 1]) {  
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    const int MIN_VALUE = 0;
    const int MAX_VALUE = 100;
    const int ARRAY_SIZE = 10;

    int arr[ARRAY_SIZE];

    cout << "Генерация случайного массива..." << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    cout << "Исходный массив: ";
    printArray(arr, ARRAY_SIZE);

    selectionSortDescending(arr, ARRAY_SIZE);

    cout << "Отсортированный массив (по убыванию): ";
    printArray(arr, ARRAY_SIZE);

    if (isSortedDescending(arr, ARRAY_SIZE)) {
        cout << "Массив отсортирован по убыванию корректно!" << endl;
    }
    else {
        cout << "Ошибка сортировки!" << endl;
    }

    return 0;
}