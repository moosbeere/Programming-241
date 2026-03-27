#include <iostream>
#include <array>
int* selectionSort(int *arr, int size);
int findMin(bool *taken, int *arr, int size);

int main() {
    int size = 10;
    int arr[10] = {2, 3, 1, 1, 7, 8, 2, 4, 10, 2};
    int *res = selectionSort(arr, 10);    
    for (int i = 0; i < size; i++) {
        std::cout << res[i] << " ";
    }
    delete res;
}

int* selectionSort(int *arr, int size) {
    bool taken[10] = {false};  // how to make taken[size]? 
    int *res = new int[size];
    for (int i = 0; i < size; i++) {
        int index_of_min = findMin(taken, arr, size);
        taken[index_of_min] = true;
        res[i] = arr[index_of_min];
    }
    return res;
}

int findMin(bool *taken, int *arr, int size) {
    int min = INT_MAX;
    int index = -1;
    for (int j = 0; j < size; j++) {
        if (arr[j] < min) {
            if (!taken[j]){
                index = j;
                min = arr[j];
            }
       }
    }
    if (index == -1) {
        std::cout << "MIN=" << min << " arr[index]=" << arr[index] << std::endl;
        for (int m = 0; m < 10; m++) std::cout << " taken[" << m << "]=" << taken[m];
    }
    std::cout << std::endl;
    return index;
}