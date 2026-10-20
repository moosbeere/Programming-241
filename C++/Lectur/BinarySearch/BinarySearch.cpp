// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int binarySearch(int list[], int item, int length);

int main()
{
    int list[] = {3, 5, 7, 9, 12, 15, 17};
    int length = sizeof(list) / sizeof(list[0]);
    std::cout << binarySearch(list, 90, length) << '\n';
}

int binarySearch(int list[], int item, int length)
{
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int mid = trunc((low + high) / 2);
        int guess = list[mid];
        if (item == guess) return mid;
        if (item < guess) high = mid - 1;
        else low = mid + 1;
    }
    return NULL;
}
