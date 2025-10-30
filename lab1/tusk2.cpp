#include <iostream>
#include <array>
int* selectionSortDesc(int *arr, int size);
int findMax(bool *taken, int *arr, int size);

int main() {
    int size = 10;
    int arr[10] = {2, 3, 1, 1, 7, 8, 2, 4, 10, 2};
    int *res = selectionSortDesc(arr, 10);    
    for (int i = 0; i < size; i++) {
        std::cout << res[i] << " ";
    }
    delete res;
}

int* selectionSortDesc(int *arr, int size) {
    bool taken[10] = {false};  // how to make taken[size]? 
    int *res = new int[size];
    for (int i = 0; i < size; i++) {
        int index_of_max = findMax(taken, arr, size);
        taken[index_of_max] = true;
        res[i] = arr[index_of_max];
    }
    return res;
}

int findMax(bool *taken, int *arr, int size) {
    int max = INT_MIN;
    int index = -1;
    for (int j = 0; j < size; j++) {
        if (arr[j] > max) {
            if (!taken[j]){
                index = j;
                max = arr[j];
            }
       }
    }
    if (index == -1) {
        std::cout << "MAX=" << max << " arr[index]=" << arr[index] << std::endl;
        for (int m = 0; m < 10; m++) std::cout << " taken[" << m << "]=" << taken[m];
    }
    std::cout << std::endl;
    return index;
}