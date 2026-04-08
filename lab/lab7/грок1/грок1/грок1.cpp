#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

void selectionSortMin(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int mini = i;  
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            swap(arr[i], arr[mini]);
        }
    }
}


void selectionSortMax(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxi = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxi]) {
                maxi = j;
            }
        }
        if (maxi != i) {
            swap(arr[i], arr[maxi]);
        }
    }
}

void selectionSortPhon(string phon[], int sizePhon) {
    for (int i = 0; i < sizePhon - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < sizePhon; j++) {
            if (phon[j] < phon[mini]) {
                mini = j; 
            }
        }
        if (mini != i) {
            swap(phon[i], phon[mini]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    int arr[] = {0, 45, 12, 89, 34, 2, 67, 103, 23 };
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSortMin(arr, size);

    cout << "по возрастанию: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSortMax(arr, size);
    cout << "по убыванию: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    string phon[] = {
        "23-45-67",
        "12-34-56",
        "89-01-23",
        "45-67-89",
        "34-56-78",
        "78-90-12",
        "01-23-45",
        "67-89-01"
    };

    int sizePhon = sizeof(phon) / sizeof(phon[0]);


    selectionSortPhon(phon, sizePhon);

    cout << "список номеров: ";
    for (int i = 0; i < size; i++) {
        cout << phon[i] << " ";
    }
}

