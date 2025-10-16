#include <iostream>
#include <random>

using namespace std;

void print(int array[], int s) {
    for (int i = 0; i < s; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const int s = 7;
    int arr[s];
    cout << "Первоначальный массив: ";
    for (int i = 0; i < s; i++) {
        // генерируем псевдорандомные значения, которые записываем в массив
        arr[i] = rand() % 101;
        cout << arr[i] << " ";
    }
    cout << endl;
    // 2
    int max, temp;
    for (int i = 0; i < s; i++) {
        max = i;
        for (int j = i + 1; j < s; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
    cout << "Массив отсортированный по убыванию: ";
    print(arr, s);
}