

#include <iostream>
#include <cstdlib>
using namespace ::std;
int quick_sort(int arr[1000], int start, int end)
{
    if (start >= end)
        return;

    int x = arr[500];
    int left = start;
    int right = end;

    while (left <= right)
    {
        while (arr[left] < x)
            left++;
        while (arr[right] > x)
            right--;
        if (left <= right)
        {
            int b = arr[left];
            arr[left] = arr[right];
            arr[right] = b;
            left++;
            right--;
        }
        quick_sort(arr, start, right);
        quick_sort(arr, left, end);
    }

   
}


int main()
{
    int array[1000];
    for (int i = 0; i < 1000; i++) {
        array[i] = rand();
    }

    for (int i = 0; i < 1000; i++) {
        cout << array[i] << " ";
    }
}

