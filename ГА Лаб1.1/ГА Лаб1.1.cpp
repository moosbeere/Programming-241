#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    int const size = 10;

    int arr[size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 102 + 2;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int x = arr[i];
        arr[i] = arr[min];
        arr[min] = x;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}