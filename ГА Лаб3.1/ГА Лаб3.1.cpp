#include <iostream>
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
    int a[1000];

    for (int i = 0; i < 1000; i++)
    {
        a[i] = rand() % 10000;
    }

    qsort(a, 0, 999);

    for (int i = 0; i < 1000; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
