#include <iostream>
#include <random>

using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const int s = 50;
    int array[s];
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < s; i++) {
        array[i] = rand() % (100 - 51) + 51;
        cout << array[i] << " ";
    }
    cout << endl;

    quickSort(array, 0, 49);
    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < s; i++) {
        cout << array[i] << " ";
    }
}