#include <iostream>
#include <ctime>
using namespace std;

void qsort(int arr[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            int x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i++;
            j--;
        }
    }

    if (left < j)
        qsort(arr, left, j);
    if (i < right)
        qsort(arr, i, right);
}

int main()
{
    int a[20];
    srand(time(0));
    setlocale(LC_ALL, "RU");

    for (int i = 0; i < 20; i++)
    {
        a[i] = rand() % 50 + 50;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << " ";
    }

    qsort(a, 0, 19);

    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}