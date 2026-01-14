#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int N = 10;
    int a[N];

    srand(time(0));

    // Заполнение массива случайными числами [0; 100]
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 101;
    }

    cout << "Исходный массив:\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;

    // Сортировка выбором по убыванию
    for (int i = 0; i < N - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (a[j] > a[maxIndex])
                maxIndex = j;
        }
        swap(a[i], a[maxIndex]);
    }

    cout << "Отсортированный массив:\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";

    return 0;
}
