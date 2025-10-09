#include <iostream>
#include <string>
using namespace ::std;

void sselection_sort(string arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    string arr[] = {
        "54-43-11",
        "91-66-11",
        "11-11-11",
        "11-11-12",
        "54-11-43"
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }


    sselection_sort(arr, size);

    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\n";
    }

    return 0;
}