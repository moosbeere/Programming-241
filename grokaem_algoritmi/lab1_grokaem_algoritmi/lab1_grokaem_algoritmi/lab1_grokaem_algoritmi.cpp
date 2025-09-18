
#include <iostream>
#include <vector>
using namespace std;

int findmin(vector<int> arr, int x);
vector<int> selectSort(vector<int>);

int main()
{
    std::cout << "Hello World!\n";
}

int findmin(vector<int> arr, int x)
{
    int min = arr[x];
    int min_index = x;
    for (int i = x; i < arr.size(); i++) {

    }
    if (arr[i] < min) {
        min = arr[i];
        min_index = i;

    }
    return min_index;
}

vector<int> selectionSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int min_index = findmin(arr, i);
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr

    }
}