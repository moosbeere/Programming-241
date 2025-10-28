#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <vector>

using namespace std;

void selectionSort(string arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) { 
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void printPhones(string phones[], int size) {
    for (int i = 0; i < size; i++) {
        cout << phones[i] << endl;
    }
}

bool isSorted(string arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

string generateRandomPhone() {
    string phone = "";
    for (int i = 0; i < 3; i++) {
        int part = rand() % 100;  
        if (part < 10) {
            phone += "0" + to_string(part); 
        }
        else {
            phone += to_string(part);
        }
        if (i < 2) {
            phone += "-";
        }
    }
    return phone;
}

int main() {
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    const int ARRAY_SIZE = 8;
    string phones[ARRAY_SIZE];

    cout << "Генерация списка телефонов..." << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        phones[i] = generateRandomPhone();
    }

    cout << "Исходный список телефонов:" << endl;
    printPhones(phones, ARRAY_SIZE);

    selectionSort(phones, ARRAY_SIZE);

    cout << "\nОтсортированный список телефонов (по возрастанию):" << endl;
    printPhones(phones, ARRAY_SIZE);

    if (isSorted(phones, ARRAY_SIZE)) {
        cout << "\nСписок телефонов отсортирован корректно!" << endl;
    }
    else {
        cout << "\nОшибка сортировки!" << endl;
    }

    return 0;
}