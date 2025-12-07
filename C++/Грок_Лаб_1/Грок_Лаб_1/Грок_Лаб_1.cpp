#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

void selectionSort(vector<int>& arr, int size, bool mode) {
    if (mode == false) {
        for (int i = 0; i < size; i++) {
            int min_idx = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(arr[i], arr[min_idx]);
            }
        }
    }
    else if (mode == true) {
        for (int i = 0; i < size; i++) {
            int min_idx = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] > arr[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(arr[i], arr[min_idx]);
            }
        }
    }
}
void str_selectionSort(vector<string>& arr, int size) {
    for (int i = 0; i < size; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    // Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, 
    // находящихся в интервале {2,103}. Использовать сортировку выбором. 

    int size = rand() % 1000 + 1;
    cout << "РАЗМЕР: " << size << "\n";
    vector<int> A1(size);
    cout << "ВЕКТОР:\n   ";

    for (int i = 0; i < size; i++) {
        A1[i] = rand() % 102 + 2;
        cout << A1[i] << " ";
    }
    
    selectionSort(A1, size, false);
    cout << "\n\nСОРТИРОВКА:\n   ";
    for (int i = 0; i < size; i++) {
        cout << A1[i] << " ";
    }
    cout << "\n\n\n\n\n";

    // Написать программу, сортирующую по убыванию одномерный массив случайных целых чисел,
    // находящихся в интервале {0,100}. 

    size = rand() % 1000 + 1;
    cout << "РАЗМЕР: " << size << "\n";
    vector<int> A2(size);
    cout << "ВЕКТОР:\n   ";

    for (int i = 0; i < size; i++) {
        A2[i] = rand() % 102 + 2;
        cout << A2[i] << " ";
    }

    selectionSort(A2, size, true);
    cout << "\n\nСОРТИРОВКА:\n   ";
    for (int i = 0; i < size; i++) {
        cout << A2[i] << " ";
    }
    cout << "\n\n\n\n\n";

    // Написать программу, сортирующую список телефонов по возрастанию и использующую  
    // сортировку выбором. Телефон задан в виде строки. Например, 23-45-67.


    size = rand() % 100 + 1;
    cout << "РАЗМЕР: " << size << "\n";
    vector<string> A3(size);
    cout << "ВЕКТОР:\n   ";
    for (int i = 0; i < size; i++) {
        string a = "";
        int b = 0;
        for (int j = 0; j < 3; j++) {
            b = rand() % 100;
            if (b < 10) {
                a += '0' + std::to_string(b);
            }
            else {
                a += std::to_string(b);
            }
            if (j != 2) {
                a += '-';
            }
        }
        cout << a << " ";
        A3[i] = a;
    }

    str_selectionSort(A3, size);
    cout << "\n\nСОРТИРОВКА:\n   ";
    for (int i = 0; i < size; i++) {
        cout << A3[i] << " ";
    }
}
