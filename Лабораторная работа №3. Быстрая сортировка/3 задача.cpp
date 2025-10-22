#include <iostream>
using namespace std;

const int rows = 3;
const int cols = 3;

void swap(int data[rows][cols], int firstrows, int secondrows) {
    auto temp = data[firstrows][0];
    data[firstrows][0] = data[secondrows][0];
    data[secondrows][0] = temp;
}

void sort(int data[rows][cols], int start = 0, int end = rows - 1) {
    if (start >= end) return;
    int current = start;
    for (int i = start + 1; i <= end; i++) {
        if (data[i][0] < data[start][0]) swap(data, ++current, i);
    }
    swap(data, current, start);
    if (current > start) {
        sort(data, start, current - 1);
    }
    if (end > current) {
        sort(data, current + 1, end);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int data[rows][cols] = { {61, 55, 43}, {29, 7, 6}, {5, 9, 9 } };
    cout << "исходный массив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "отсортированный массив:\n";
    sort(data, 0, rows - 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}
