#include <iostream>
#include <string>

int* to_numbers(std::string *arr, int size);
int findMin(int *arr, bool *taken, int size);
std::string* selectionSort(std::string *arr, int size);

int main() {
    int size = 10;
    std::string arr[10] = {"23-23-54", "54-23-12", "12-23-03", "12-32-41", "12-11-23", "32-43-52", "88-65-31",
                            "16-46-76", "29-03-12", "01-12-02"};
    std::string *res = selectionSort(arr, 10);
    for (int i = 0; i < size; i++) std::cout << res[i] << ' ';
    delete[] res;
}
std::string* selectionSort(std::string *arr, int size) {
    int *new_arr = to_numbers(arr, size);
    bool used[10] = {false};
    std::string *result = new std::string[10];
    int indx_of_min = -1;

    for (int i = 0; i < size; i++) {
        indx_of_min = findMin(new_arr, used, size);
        used[indx_of_min] = true;
        result[i] = arr[indx_of_min];
        

    }
    return result;
}

int findMin(int *arr, bool *taken, int size) {
    int min = INT_MAX;
    int index = -1;
    for (int j = 0; j < size; j++) {
        if (arr[j] < min && !taken[j]) {;
            min = arr[j];
            index = j;
        }
    }
    return index;
}

int* to_numbers(std::string *arr, int size) {
    int* new_arr = new int[size];
    // for (int i = 0; i < size; i++) new_arr[i] = new int[2];
    for (int i = 0; i < size; i++) {
        std::string el = arr[i];
        el.erase(2, 1);
        el.erase(4, 1);
        // new_arr[i][0] = (i);
        new_arr[i] = std::stoi(el);
    }
    return new_arr;
}