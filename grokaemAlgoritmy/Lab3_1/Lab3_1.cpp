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
    const int s = 1000;
    int array[s];
    cout << "Первые 10 элементов исходного массива:" << endl;
    for (int i = 0; i < s; i++) {
        array[i] = rand() % 10000;
        if (i < 10) cout << array[i] << " " ;
    }
    cout << endl;

    quickSort(array, 0, 999);
    cout << "Первые 10 элементов отсортированного списка:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
}   