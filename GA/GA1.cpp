#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Сортировка выбором по возрастанию
void sortAscending(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Сортировка выбором по убыванию
void sortDescending(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

// Сортировка выбором для телефонов
void sortPhones(vector<string>& phones) {
    int n = phones.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (phones[j] < phones[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            string temp = phones[i];
            phones[i] = phones[minIndex];
            phones[minIndex] = temp;
        }
    }
}

int main() {
    srand(time(0));
    
    cout << "=== Задача 1: Сортировка по возрастанию {2,103} ===" << endl;
    vector<int> arr1;
    for (int i = 0; i < 10; i++) {
        arr1.push_back(2 + rand() % 102); // числа от 2 до 103
    }
    
    cout << "Исходный массив: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    sortAscending(arr1);
    cout << "Отсортированный: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "\n=== Задача 2: Сортировка по убыванию {0,100} ===" << endl;
    vector<int> arr2;
    for (int i = 0; i < 10; i++) {
        arr2.push_back(rand() % 101); // числа от 0 до 100
    }
    
    cout << "Исходный массив: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    sortDescending(arr2);
    cout << "Отсортированный: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    cout << "\n=== Задача 3: Сортировка телефонов ===" << endl;
    vector<string> phones = {"23-45-67", "12-34-56", "98-76-54", "11-22-33", "55-66-77"};
    
    cout << "Исходный список: ";
    for (int i = 0; i < phones.size(); i++) {
        cout << phones[i] << " ";
    }
    cout << endl;
    
    sortPhones(phones);
    cout << "Отсортированный: ";
    for (int i = 0; i < phones.size(); i++) {
        cout << phones[i] << " ";
    }
    cout << endl;
    
    return 0;
}
