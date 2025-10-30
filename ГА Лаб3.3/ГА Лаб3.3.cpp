#include <iostream>
#include <ctime>
using namespace std;

void qsort(int arr[][5], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2][0];

    while (i <= j)
    {
        while (arr[i][0] < pivot)
            i++;
        while (arr[j][0] > pivot)
            j--;
        if (i <= j)
        {
            for (int k = 0; k < 5; k++)
            {
                int x = arr[i][k];
                arr[i][k] = arr[j][k];
                arr[j][k] = x;
            }
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
    const int ROWS = 6;
    const int COLUMNS = 5;
    int a[ROWS][COLUMNS];
    setlocale(LC_ALL, "RU");
    srand(time(0));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            a[i][j] = 5 + rand() % 57;
        }
    }

    cout << "Исходный массив:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    qsort(a, 0, ROWS - 1);

    cout << "\nМассив после сортировки по первому столбцу:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
