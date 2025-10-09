// alg_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <string>
using namespace ::std;


void selection_sort(int arr[], int const size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;

        }
        if (minIndex != i) {
            int b = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = b;
        }
     }
}



void unselection_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        if (maxIndex != i) {
            int b = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = b;
        }
    }
}

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

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {2,103}. Использовать сортировку выбором.\n\n";
    const int size = 10;
    int arr[size];

    srand(time(NULL));
    cout << "Исходный массив\n";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 102 + 2;
        cout << arr[i] << " ";
    }
    
    cout << "\nОтсортированный массив\n";
    selection_sort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\n\nНаписать программу, сортирующую по убыванию одномерный массив случайных целых чисел, находящихся в интервале {0,100}.\n\n";
    int arr2[size];
    cout << "Исходный массив\n";
    for (int i = 0; i < size; i++) {
        arr2[i] = rand() % 100 + 0;
        cout << arr2[i] << " ";
    }
    cout << "\nОтсортированный массив\n";
    unselection_sort(arr2, size);
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }

    cout << "\n\nНаписать программу, сортирующую список телефонов по возрастанию и использующую  сортировку выбором. Телефон задан в виде строки. Например, 23-45-67.\n";

    string array[] = {
        "54-43-11",
        "91-66-11",
        "11-11-11",
        "11-11-12",
        "54-11-43"
    };

    int sizee = sizeof(array) / sizeof(array[0]);

    cout << "\nИсходный массив:\n";
    for (int i = 0; i < sizee; i++) {
        cout << array[i] << "\n";
    }


    sselection_sort(array, sizee);

    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < sizee; i++) {
        cout << array[i] << "\n";
    }


}

