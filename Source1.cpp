#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> arr, int x) {
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

vector<int> selectionSort(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		int min_index = findMin(arr, i);
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	return arr;
}

int main()
{
	vector<int> arrey{ 2, 29, 47, 99, 13, 1, 88, 101, 11 };
	vector<int> sort = selectionSort(arrey);
	for (int n : sort) cout << n << ", ";

}
