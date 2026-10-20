// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> arr, int x);
vector<int> selectionSort(vector<int> arr);

int main()
{
    vector<int> array{ 4,2,8,1,9 };
    vector<int> sort = selectionSort(array);
    for (int n : sort) cout << n << ", ";

}

int findMin(vector<int> arr, int x)
{
    int min = arr[x];
    int min_index = x;
    for (int i = x; i < arr.size(); i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> selectionSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++) {
        int min_index = findMin(arr, i);
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    return arr;
}
