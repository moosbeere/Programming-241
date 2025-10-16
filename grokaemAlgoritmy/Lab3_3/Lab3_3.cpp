#include <iostream>
#include <random>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> m, const int r, const int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void quickSort(vector<vector<int>>& arr, int left, int right) {
    if (left >= right) return;
    int mid = arr[(left + right) / 2][0];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i][0] < mid) i++;
        while (arr[j][0] > mid) j--;
        if (i <= j) {
            swap(arr[i][0], arr[j][0]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const int ROWS = 10, COLS = 10;
    vector<vector<int>> matrix(ROWS, vector<int>(COLS));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % (61 - 6) + 6;
        }
    }
    cout << "Первоначальная матрица:" << endl;
    printMatrix(matrix, ROWS, COLS);
    cout << endl;

    quickSort(matrix, 0, 9);
    cout << "Матрица после сортировки первого столбца:" << endl;
    printMatrix(matrix, ROWS, COLS);
}