#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int разделение(vector<int>& arr, int низкий, int высокий) {
    int опора = arr[высокий]; 
    int i = (низкий - 1);

    for (int j = низкий; j <= высокий - 1; j++) {
        if (arr[j] <= опора) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[высокий]);
    return (i + 1);
}

void быстраяСортировка(vector<int>& arr, int низкий, int высокий) {
    if (низкий < высокий) {
        int pi = разделение(arr, низкий, высокий);

        быстраяСортировка(arr, низкий, pi - 1);
        быстраяСортировка(arr, pi + 1, высокий);
    }
}
void вывестиМассив(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int РАЗМЕР = 1000;
    vector<int> числа(РАЗМЕР);

    srand(time(0));

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < РАЗМЕР; i++) {
        числа[i] = rand() % 1000 + 1;
    }

    cout << "Первые 20 элементов исходного массива:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << числа[i] << " ";
    }
    cout << endl << endl;

    быстраяСортировка(числа, 0, РАЗМЕР - 1);

    cout << "Массив после сортировки:" << endl;
    cout << "Первые 20 элементов:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << числа[i] << " ";
    }
    cout << endl << endl;

    cout << "Последние 20 элементов:" << endl;
    for (int i = РАЗМЕР - 20; i < РАЗМЕР; i++) {
        cout << числа[i] << " ";
    }
    cout << endl;

    bool корректно = true;
    for (int i = 1; i < РАЗМЕР; i++) {
        if (числа[i] < числа[i - 1]) {
            корректно = false;
            break;
        }
    }

    if (корректно) {
        cout << "Сортировка выполнена корректно!" << endl;
    }
    else {
        cout << "Ошибка в сортировке!" << endl;
    }

    return 0;
}