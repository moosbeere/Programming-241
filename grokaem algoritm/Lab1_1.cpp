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
        arr[i] = rand() % 104 + 2;
        cout << arr[i] << " ";
    }
    cout << endl;

    int min, temp;
    for (int i = 0; i < s; i++) {
        min = i;
        for (int j = i + 1; j < s; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    cout << "Отсортированный массив: ";
    print(arr, s);
}