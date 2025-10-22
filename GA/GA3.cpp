#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Простая сортировка выбором
void sortArray(vector<int>& arr) {
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

// Сортировка по убыванию
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

int main() {
    cout << "Сортировка массивов" << endl;
    
    // Задача 1: Сортировка по возрастанию
    vector<int> arr1 = {5, 2, 8, 1, 9};
    cout << "Исходный массив: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    sortArray(arr1);
    cout << "Отсортированный: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // Задача 2: Сортировка по убыванию
    vector<int> arr2 = {3, 7, 1, 9, 4};
    cout << "\nИсходный массив: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    sortDescending(arr2);
    cout << "По убыванию: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    // Задача 3: Сортировка строк
    vector<string> phones = {"23-45-67", "12-34-56", "98-76-54"};
    cout << "\nТелефоны до сортировки: ";
    for (int i = 0; i < phones.size(); i++) {
        cout << phones[i] << " ";
    }
    cout << endl;
    
    sort(phones.begin(), phones.end());
    cout << "После сортировки: ";
    for (int i = 0; i < phones.size(); i++) {
        cout << phones[i] << " ";
    }
    cout << endl;
    
    return 0;
}